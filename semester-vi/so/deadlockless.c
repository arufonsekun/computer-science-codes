#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define DONT_GET_MUTEX 1

void *thread1 (void* data);
void *thread2 (void* data);

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER,
mutex2 = PTHREAD_MUTEX_INITIALIZER;

pthread_t Thread1, Thread2;

int main(void) {
    pthread_create(&Thread1, NULL, thread1, NULL);
    pthread_create(&Thread2, NULL, thread2, NULL);

    pthread_join(Thread1, NULL);
    printf("Thread1 id %ld returned\n", Thread1);
    pthread_join(Thread2, NULL);
    printf("Thread2 id %ld returned\n", Thread2);

    return 1;
}

void *thread1(void* data){
    unsigned long i, j;
    int didnt_get_mutex1 = pthread_mutex_trylock(&mutex1) == DONT_GET_MUTEX;

    while (didnt_get_mutex1) {
        printf("\nThread ID: %ld did not get mutex1.\n", pthread_self());
        didnt_get_mutex1 = pthread_mutex_trylock(&mutex1) == DONT_GET_MUTEX;
    }

    printf("Thread ID: %ld got mutex1.\n", pthread_self());
    sleep(1);
    pthread_mutex_unlock(&mutex1);

    int didnt_get_mutex2 = pthread_mutex_trylock(&mutex2) == DONT_GET_MUTEX;
    while (didnt_get_mutex2) {
        printf("\nThread ID: %ld did not get mutex2.\n", pthread_self());
        didnt_get_mutex2 = pthread_mutex_trylock(&mutex2) == DONT_GET_MUTEX;
    }

    printf("Thread ID: %ld got mutex2.\n", pthread_self());
    sleep(1);
    pthread_mutex_unlock(&mutex2);
    pthread_exit(NULL);
}

void *thread2(void* data){
    unsigned long i, j;
    int didnt_get_mutex2 = pthread_mutex_trylock(&mutex2) == 1;

    while (didnt_get_mutex2) {
        printf("\nThread ID: %ld did not get mutex2.\n", pthread_self());
        didnt_get_mutex2 = pthread_mutex_trylock(&mutex2) == 1;
    }

    printf("Thread ID: %ld got mutex2.\n", pthread_self());
    sleep(1);
    pthread_mutex_unlock(&mutex2);

    int didnt_get_mutex1 = pthread_mutex_trylock(&mutex1) == 1;
    while (didnt_get_mutex1) {
        printf("\nThread ID: %ld did not get mutex1.\n", pthread_self());
        didnt_get_mutex1 = pthread_mutex_trylock(&mutex1) == 1;
    }

    printf("Thread ID: %ld got mutex1.\n", pthread_self());
    sleep(1);
    pthread_mutex_unlock(&mutex1);
    pthread_exit(NULL);
}