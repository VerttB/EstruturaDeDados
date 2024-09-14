
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

int popQ(void **q){
  Queue **queue = (Queue**)q;
  Queue *aux = (*queue);
  int val = aux->value;
  *q = (void*)(*queue)->prox;
  free(aux);
  return val;
}

void reverseQ(void **q){
  void *queueVoid = *q;
  void *auxSt = NULL; // pilha
  while(*q != NULL){
    pushS(&auxSt,popQ(q));  // Retira dafila e empilha inversamente
  }

  *q = auxSt;
}