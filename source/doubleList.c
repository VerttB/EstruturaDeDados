#include <stdlib.h>
#include <stdio.h>
#include "../headers/doubleList.h"


void pushDb(void **voidInicio, int num) {
  DbList *novo = NULL, *atual = NULL;
  DbList **inicio = (DbList**)voidInicio;
  novo = (DbList *)malloc(sizeof(DbList));
  if (!novo) exit(1);


  novo->num = num;
  atual = (*inicio);
  
  if (atual == NULL) {
    (*inicio) = novo;
    (*inicio)->prox = NULL;
    (*inicio)->ant = NULL;
    return;
  }

  while (atual->prox != NULL && atual->num < novo->num) {
    atual = atual->prox;
  }
  if(atual == (*inicio) && atual->num > novo->num){
    novo->ant = NULL;
    novo->prox = atual;
    atual->ant = novo;
    (*inicio) = novo;
  }
   else {
    if (atual->prox == NULL) {
      novo->ant = atual;
      atual->prox = novo;
      novo->prox = NULL;
      
    } else {
      atual->ant->prox = novo;
      novo->prox = atual;
      novo->ant = atual->ant;
      atual->ant = novo;
    }
  }
}

void printDb(DbList *inicio) {
  DbList *aux;
  aux = (inicio);
  while (aux != NULL) {
    printf("%d ", aux->num);
    aux = aux->prox;
  }
}