/*
    Nome: Junior Vitor Ramisch 
    Matrícula: 1811100034
    Semestre: 2020.2
    gcc (GCC) 10.2.0
    Compilar: gcc -o variable-increment-condition-var variable-increment-condition-var.c -lpthread
    Executar: ./variable-increment-condition-var
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 

int counter = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t incrementer0, incrementer1, incrementer2 = PTHREAD_COND_INITIALIZER;

void *manager();
void *increment_0();
void *increment_1();
void *increment_2();

pthread_t Thread0, Thread1, Thread2, Thread3;

int main() {
    
    pthread_create(&Thread1, NULL, increment_0, NULL);
    pthread_create(&Thread2, NULL, increment_1, NULL);
    pthread_create(&Thread3, NULL, increment_2, NULL);
    pthread_create(&Thread0, NULL, manager, NULL);

    pthread_join(Thread1, NULL);
    pthread_join(Thread2, NULL);
    pthread_join(Thread3, NULL);
    pthread_join(Thread0, NULL);

    printf("Global variable %d\n", counter);
    exit(EXIT_SUCCESS);
}

void *manager() {
    for (;;) {
        pthread_mutex_lock(&mutex);

        if (counter % 3 == 0) {
            pthread_mutex_unlock( &mutex );
            pthread_cond_signal(&incrementer0);
        }
        if (counter % 3 == 1) {
            pthread_mutex_unlock( &mutex );
            pthread_cond_signal(&incrementer1);
        }
        if (counter % 3 == 2) {
            pthread_mutex_unlock( &mutex );
            pthread_cond_signal(&incrementer2);
        }
        if(counter >= MAX) return(NULL);
    }
}

void *increment_0() {
    for (;;) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&incrementer0, &mutex);
        counter++;
        printf("Thread 0 increment: %d\n", counter);
        pthread_mutex_unlock(&mutex);
        if(counter >= MAX) return(NULL);
    }
}

void *increment_1() {
    for (;;) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&incrementer1, &mutex);
        counter++;
        printf("Thread 1 increment: %d\n", counter);
        pthread_mutex_unlock(&mutex);
        if(counter >= MAX) return(NULL);
    }
}

void *increment_2() {
    for (;;) {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&incrementer2, &mutex);
        counter++;
        printf("Thread 2 increment: %d\n", counter);
        pthread_mutex_unlock(&mutex);
        if(counter >= MAX) return(NULL);
    }
}