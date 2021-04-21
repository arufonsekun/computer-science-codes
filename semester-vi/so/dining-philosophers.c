/*
    Nome: Junior Vitor Ramisch 
    Matrícula: 1811100034
    Semestre: 2020.2
    gcc (GCC) 10.2.0
    Compilar: gcc -o dining-philosophers dining-philosophers.c -lpthread
    Executar: ./dining-philosophers
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <semaphore.h>
#include <pthread.h>

#define N 5
#define LEFT (i + N - 1) % N
#define RIGHT (i + 1) % N
#define THINKING 0
#define HUNGRY 1
#define EATING 2
#define ALIVE 1

int state[N];
sem_t mutex;
sem_t s[N];

void * philosopher(void* p_id);
void think();
void take_forks(int i);
void eat();
void give_back(int i);
void try2_eat(int i);
void sleep();

int main() {

    printf("----------- Philosophers dining simulation -----------\n");
    printf("|\tHit Ctrl+c to exit                           |\n");
    sem_init(&mutex, 0, 1);
    pthread_t philosophers [N];

    for(int i=0; i < N; i++) {
        int *j = malloc(sizeof(int));
        *j = i;
        printf("|\tPhilosopher %d arrived at the restaurant      |\n", i);
        pthread_create(&(philosophers[i]), NULL, philosopher, (void *) j);
    }

    for(int i=0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }
    
    printf("------------------------------------------------------\n");
    
    return 0;
}

// Function that represents a philosopher life cycle.
void * philosopher(void *p_id) {
    int i;
    i = *((int *) p_id);
    free((int *) p_id);

    printf("|\tPhilosopher %d sat down at the table          |\n", i);
    while (ALIVE) {
        think();
        take_forks(i);
        eat(i);
        give_back(i);
    }
}

void think() {
    sleep(2);
}

void eat() {
    sleep(2);
}

void take_forks(int i) {
    sem_wait(&mutex);
    state[i] = HUNGRY;
    printf("|\tPhilosopher %d is hungry                      |\n", i);
    printf("|\t                                             |\n");
    
    try2_eat(i);

    sem_post(&mutex);

    // Sets semaphore state to DOWN, it means
    // philosopher releases critical region
    sem_wait(&s[i]);
}

void give_back(int i) {
    
    // releases critical region 
    sem_wait(&mutex);
    
    // Starts thinking again
    state[i] = THINKING;
    printf("|\tPhilosopher %d is thinking                    |\n", i);
    printf("|\t                                             |\n");
    try2_eat(LEFT);
    try2_eat(RIGHT);
    
    sem_post(&mutex);
}

void try2_eat(int i) {
    bool isHungry = state[i] == HUNGRY,
    leftIsnEating = state[LEFT] != EATING,
    rightIsnEating = state[RIGHT] != EATING;

    if (isHungry && leftIsnEating && rightIsnEating) {
        state[i] = EATING;
        printf("|\tPhilosopher %d is eating                      |\n", i);
        printf("|\t                                             |\n");

        // Sets semaphore state to UP, it means
        // philosopher acquires critical region
        sem_post(&s[i]);
    }
}