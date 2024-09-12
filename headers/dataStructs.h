#ifndef STACKTESTE_H_INCLUDED
#define STACKTESTE_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

typedef struct stackT{
    int value;
    struct stackT *prox;
}StackT;

typedef struct queueT{
    int value;
    struct queueT *prox;
    struct queueT *fim;
}QueueT;

typedef struct bigS{
    void *sts;
    void (*pushar)(void **, int);
}BigS;

void pushar(StackT **, int);
BigS *newStructure(char *);
void pushQ(QueueT **inicio, int value);
void pushar(StackT **top, int val) {

    StackT *node = (StackT*) malloc(sizeof(StackT));
    if (node == NULL) return;
    node->value = val;
    node->prox = *top;
    *top = node;
}


BigS *newStructure(char *type){
    BigS *n = (BigS*) malloc(sizeof(BigS));
    if (n == NULL) return NULL;
    n->sts = NULL;
    printf("%s",type);
    if(strcmp(type,"stack") == 0) n->pushar = (void (*)(void **, int))pushS;
    else n->pushar = (void (*)(void **, int))pushQ;

    return n;

}

void printSt(StackT *t){
    if(t == NULL) return;
    StackT *aux;
    aux = t;

    while(aux != NULL){
        printf("%d ", aux->value);
        aux = aux->prox;
    }
    printf("\n");
}

void pushQ(QueueT **inicio, int value){
    QueueT *novo, *atual = NULL, *ant = NULL;
  novo = (QueueT *)malloc(sizeof(QueueT));
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

#endif // STACKTESTE_H_INCLUDED
