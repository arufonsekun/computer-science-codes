#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define GET_MUTEX 0

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
    int get_mutex1, get_mutex2;

    do {
        get_mutex1 = pthread_mutex_trylock(&mutex1) == GET_MUTEX;
        
        if (get_mutex1) {
            printf("Thread ID: %ld got mutex1.\n", pthread_self());
            sleep(1);
            get_mutex2 = pthread_mutex_trylock(&mutex2) == GET_MUTEX;

            while (!get_mutex2) {
                printf("\nThread ID: %ld did not get mutex2.\n", pthread_self());
                get_mutex2 = pthread_mutex_trylock(&mutex2) == GET_MUTEX;
            }
            
            printf("Thread ID: %ld got mutex2.\n", pthread_self());
            sleep(1);

            pthread_mutex_unlock(&mutex2);
            pthread_mutex_unlock(&mutex1);
        } else {
            printf("\nThread ID: %ld did not get mutex1.\n", pthread_self());
        }

    } while (!get_mutex1);
}

void *thread2(void* data){
    int get_mutex2, get_mutex1;

    do {
        get_mutex2 = pthread_mutex_trylock(&mutex2) == GET_MUTEX;
        
        if (get_mutex2) {
            printf("Thread ID: %ld got mutex2.\n", pthread_self());
            sleep(1);
            get_mutex1 = pthread_mutex_trylock(&mutex1) == GET_MUTEX;

            while (!get_mutex1) {
                printf("\nThread ID: %ld did not get mutex1.\n", pthread_self());
                get_mutex1 = pthread_mutex_trylock(&mutex1) == GET_MUTEX;
            }
            
            printf("Thread ID: %ld got mutex1.\n", pthread_self());
            sleep(1);

            pthread_mutex_unlock(&mutex1);
            pthread_mutex_unlock(&mutex2);
        } else {
            printf("\nThread ID: %ld did not get mutex2.\n", pthread_self());
        }

    } while (!get_mutex2);
}