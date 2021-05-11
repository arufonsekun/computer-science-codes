/*
    Nome: Junior Vitor Ramisch 
    Matrícula: 1811100034
    Semestre: 2020.2
    gcc (GCC) 10.2.0
    Compilar: gcc -o one-d-iterative-averaging one-d-iterative-averaging.c -lpthread -lm
    Executar: ./one-d-iterative-averaging
*/

#include <pthread.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define VECTOR_SIZE 30
#define EDGES 2

static pthread_barrier_t barrier;

double OLD[VECTOR_SIZE];
double NEW[VECTOR_SIZE];
double TEMP[VECTOR_SIZE];
int SLICE_SIZE;
int N_ITERATIONS;
bool SHOW_THREAD_MESSAGE = true;

void test_command_line_args(int n_threads, int n_iterations)
{
    printf("Amount of threads: %d\n", n_threads);
    printf("Number of iterations: %d\n", n_iterations);
}

void test_slice()
{
    printf("Slice size: %d\n", SLICE_SIZE);
}

void test_threads_range(int n_threads)
{
    printf("Vector size: %d\n", VECTOR_SIZE);
    int start = 0, end = 0;
    for (int i = 0; i < n_threads; i++)
    {
        start = i * SLICE_SIZE + 1;
        end = start + SLICE_SIZE - 1;
        if (end > (VECTOR_SIZE - 2)) end = VECTOR_SIZE - 2;
        printf("Thread id %d will compute range [%d:%d]\n", i, start, end);
    }
}

void fill_vectors()
{
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        OLD[i]  = (double)(i < VECTOR_SIZE-1 ? 0 : 1);
        NEW[i]  = (double)(i < VECTOR_SIZE-1 ? 0 : 1);
        TEMP[i] = (double)(i < VECTOR_SIZE-1 ? 0 : 1);
    }
}

void print_vector()
{
    for (int i = 0; i < VECTOR_SIZE; i++)
    {
        if (NEW[i] > 0)
            printf("%f ", NEW[i]);
        else
            printf("%d ", 0);
    }
    printf("\n");
}

void swap_vectors()
{
    for (int i=0; i < VECTOR_SIZE; i++)
    {
        TEMP[i] = NEW[i];
        NEW[i] = OLD[i];
        OLD[i] = TEMP[i];
    }
}

void *compute(void *t_id)
{
    int thread_id, barrier_state;
    thread_id = *((int *) t_id);
    int start = 0, end = 0;
    start = thread_id * SLICE_SIZE + 1;
    end = start + SLICE_SIZE - 1;
    if (end > (VECTOR_SIZE - 2)) end = VECTOR_SIZE - 2;

    for (int i=0; i < N_ITERATIONS; i++)
    {
        for (int j=start; j <= end; j++)
        {
            NEW[j] = ((double)OLD[j-1] + (double)OLD[j+1]) / 2;
        }
        barrier_state = pthread_barrier_wait(&barrier);

        if (barrier_state == 0)
        {
            if (SHOW_THREAD_MESSAGE)
                printf("Thread id %d passed barrier %d\n", thread_id, i);
        }
        else if (barrier_state == PTHREAD_BARRIER_SERIAL_THREAD)
        {
            if (SHOW_THREAD_MESSAGE)
                printf("Yay, all threads passed\n");
            print_vector();
            swap_vectors();
        }
        else
        {
            if (SHOW_THREAD_MESSAGE)
                printf("Pthread id %d barrier wait error\n", thread_id);
        }
    }

    if (SHOW_THREAD_MESSAGE)
        printf("Thread id %d computed range [%d:%d]\n", thread_id, start, end);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("+---------------------------------------------------+\n");
        printf("| You're supposed to pass 2 command line arguments: |\n");
        printf("| 1. Amount of threads;                             |\n");
        printf("| 2. Number of iterations;                          |\n");
        printf("+---------------------------------------------------+\n");
    }
    else
    {
        int barrier_state, thread_state;
        int n_threads = atoi(argv[1]);
        int n_iterations = atoi(argv[2]);
        N_ITERATIONS = n_iterations;
        // test_command_line_args(n_threads, n_iterations);

        int N = VECTOR_SIZE - EDGES;
        float s_size = (float)N / (float)n_threads;
        SLICE_SIZE = ceil(s_size);
        // test_slice();

        // test_threads_range(n_threads);
        
        fill_vectors();
        print_vector();

        pthread_t threads[n_threads];
        barrier_state = pthread_barrier_init(&barrier, NULL, n_threads);

        if (barrier_state != 0)
        {
            printf("Pthread barrier init failed\n");
            exit(EXIT_FAILURE);
        }

        for (int i=0; i < n_threads; i++)
        {
            int *thread_id = malloc(sizeof(int));
            *thread_id = i;
            thread_state = pthread_create(&(threads[i]), NULL, compute, (void *) thread_id);
            if (thread_state != 0)
            {
                printf("Thread %d create failed\n", i);
                exit(EXIT_FAILURE);
            }
        }

        for (int t=0; t < n_threads; t++)
        {
            thread_state = pthread_join(threads[t], NULL);
            if (thread_state != 0)
            {
                printf("Thread %d join failed\n", t);
                exit(EXIT_FAILURE);
            }
        }
    }
    exit(EXIT_SUCCESS);
}