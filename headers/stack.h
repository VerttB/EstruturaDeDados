#ifndef STACk_H_INCLUDED
#define STACk_H_INCLUDED
typedef struct stack{
    int value;
    struct stack *prox;
}Stack;

void pushS(void **, int);
void printSt(Stack *);
void reverseS(void **);
Stack *intersection(Stack *, Stack *);
int popS(void **);

#endif