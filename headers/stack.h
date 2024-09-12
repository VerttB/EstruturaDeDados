#ifndef STACk_H_INCLUDED
#define STACk_H_INCLUDED
typedef struct stack{
    int value;
    struct stack *prox;
}Stack;

void pushS(void **, int);
void printSt(Stack *);
Stack *reverse(Stack **);
Stack *intersection(Stack *, Stack *);
void pop(Stack **);

#endif