/*
    Nome: Junior Vitor Ramisch 
    Matrícula: 1811100034
    Semestre: 2020.2
    gcc (GCC) 10.2.0
    Compilar: gcc -o variable-increment-semaphore variable-increment-semaphore.c -lpthread
    Executar: ./variable-increment-semaphore
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>

#define N 3
#define INCREMENTING 1
#define WAITING 0
#define GOT_MUTEX 0
#define MAX 10 // Max represents counting range

int counter = 0;
int state[N] = {INCREMENTING, WAITING, WAITING};

sem_t incrementers[N];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *increment_0();
void *increment_1();
void *increment_2();

pthread_t Thread0, Thread1, Thread2;

int main() {
    pthread_create(&Thread0, NULL, increment_0, NULL);
    pthread_create(&Thread1, NULL, increment_1, NULL);
    pthread_create(&Thread2, NULL, increment_2, NULL);

    sem_post(&(incrementers[0]));

    pthread_join(Thread0, NULL);
    pthread_join(Thread1, NULL);
    pthread_join(Thread2, NULL);

    printf("Global variable %d\n", counter);
    exit(EXIT_SUCCESS);
}

void *increment_0() {
    int t0_is_incrementing, t1_t2_are_waiting;

    while (1) {
        sem_wait(&incrementers[0]);

        t0_is_incrementing = state[0] == INCREMENTING;
        t1_t2_are_waiting = state[1] == WAITING && state[2] == WAITING;

        if (t0_is_incrementing && t1_t2_are_waiting) {
            if(pthread_mutex_lock(&mutex) == GOT_MUTEX) {
                counter++;
                printf("Thread 0 increment: %d\n", counter);
                pthread_mutex_unlock(&mutex);
                state[0] = WAITING;
                state[1] = INCREMENTING;
                sem_post(&incrementers[1]);
                if (counter+3 > MAX) {
                    pthread_exit(NULL);
                }
            }
        }
    }
}

void *increment_1() {

    int t1_is_incrementing, t0_t2_are_waiting;

    while (1) {
        sem_wait(&incrementers[1]);

        t1_is_incrementing = state[1] == INCREMENTING;
        t0_t2_are_waiting = state[0] == WAITING && state[2] == WAITING;

        if (t1_is_incrementing && t0_t2_are_waiting) {
            if(pthread_mutex_lock(&mutex) == GOT_MUTEX) {
                counter++;
                printf("Thread 1 increment: %d\n", counter);
                pthread_mutex_unlock(&mutex);
                state[1] = WAITING;
                state[2] = INCREMENTING;
                sem_post(&incrementers[2]);
                if (counter+3 > MAX) {
                    pthread_exit(NULL);
                }
            }
        }
    }
}

void *increment_2() {

    int t2_is_incrementing, t0_t1_are_waiting;

    while (1) {
        
        sem_wait(&incrementers[2]);
        t2_is_incrementing = state[2] == INCREMENTING;
        t0_t1_are_waiting = state[0] == WAITING && state[1] == WAITING;

        if (t2_is_incrementing && t0_t1_are_waiting) {
            if(pthread_mutex_lock(&mutex) == GOT_MUTEX) {
                counter++;
                printf("Thread 2 increment: %d\n", counter);
                
                pthread_mutex_unlock(&mutex);
                state[2] = WAITING;
                state[0] = INCREMENTING;
                sem_post(&incrementers[0]);

                if (counter+3 > MAX) {
                    pthread_exit(NULL);
                }
            }
        }
    }
}