
#include <stdlib.h>
#include <stdio.h>
#include "../headers/queue.h"
#include "../headers/stack.h"
void pushQ(void **st, int value){
  Queue **inicio = (Queue**)st;
  Queue *novo, *atual = NULL, *ant = NULL;
  novo = (Queue *)malloc(sizeof(Queue));
  novo->value = value;

  if (*inicio == NULL) {
    novo->prox = NULL;
    (*inicio) = novo;
  } else {
    atual = (*inicio);
    while (atual->prox != NULL && novo->value > atual->value) {
      ant = atual;
      atual = atual->prox;
    }
    if (novo->value < (*inicio)->value) {
      novo->prox = *inicio;
      *inicio = novo;
      (*inicio)->prox = atual;
    } else {
      if (atual->prox == NULL && novo->value > atual->value) {
        atual->prox = novo;
        novo->prox = NULL;
      } else {
        ant->prox = novo;
        novo->prox = atual;
      }
    }
  }

}

void printQ(Queue *q){
    if(q == NULL) return;
    Queue *aux;
    aux = q;
    while(aux != NULL){
        printf("%d ", aux->value);
        aux = aux->prox;
    }
    printf("\n");
}

int popQ(Queue **q){
  Queue *aux = (*q);
  int val = aux->value;
  *q = (*q)->prox;
  free(aux);
  return val;
}

Queue *inverseQ(Queue *q){
  Queue *aux = q;
  Stack *auxSt = NULL;
  while(aux != NULL){
    pushS(&auxSt, popQ(&q));
    pushQ(&q, popS(&auxSt));
  }
  






}