#include "../headers/stack.h"
#include <stdlib.h>
#include <stdio.h>

void pushS(void **st, int val) {
    Stack **top = (Stack**)st;
    Stack *node = (Stack *) malloc(sizeof(Stack));
    if (node == NULL) return;
    node->value = val;
    node->prox = *top;
    *top = node;
}

void printSt(Stack *t){
    if(t == NULL) return;
    Stack *aux;
    aux = t;

    while(aux != NULL){
        printf("%d ", aux->value);
        aux = aux->prox;
    }
    printf("\n");
}

int popQ(void *t){
        Stack **top = (Stack**)st;

  Stack *aux = (*t);
  int val = aux->value;
  *t = (*t)->prox;
  free(aux);
  return val;
}
