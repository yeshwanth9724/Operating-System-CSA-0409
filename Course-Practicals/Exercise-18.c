#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t empty, full;

void *producer(void *arg)
{
    sem_wait(&empty);
    printf("Producer produced an item\n");
    sem_post(&full);
    return NULL;
}

void *consumer(void *arg)
{
    sem_wait(&full);
    printf("Consumer consumed an item\n");
    sem_post(&empty);
    return NULL;
}

int main()
{
    pthread_t p,c;

    sem_init(&empty,0,1);
    sem_init(&full,0,0);

    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);

    pthread_join(p,NULL);
    pthread_join(c,NULL);

    return 0;
}
