#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
typedef struct queue{
    int value;
    struct queue *prox;
}Queue;

void pushQ(void **, int);
void printQ(Queue *);
int popQ(void **);
void reverseQ(void **);
#endif