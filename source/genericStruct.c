#ifndef STACKTESTE_H_INCLUDED
#define STACKTESTE_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../headers/genericStruct.h"
#include "stack.c"
#include "queue.c"

DataSt *newStructure(TYPE type){
    DataSt *n = (DataSt*) malloc(sizeof(DataSt));
    if (n == NULL) return NULL;
    n->data = NULL;
    n->type = type;
    n->push = push;
    n->print = print;
    return n;
}
void print(DataSt *ds){
    if(ds->type == STACK) printSt(ds->data);
    else if(ds->type == QUEUE) printQ(ds->data);
}

void push(DataSt *ds, int val){
    if(ds->type == STACK) pushS(&ds->data, val);
    else if(ds->type == QUEUE) pushQ(&ds->data, val);
}

#endif // STACKTESTE_H_INCLUDED
