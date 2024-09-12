#include <stdlib.h>
#include <stdio.h>
#include "source/genericStruct.c"




int main(){
    DataSt *queue = newStructure(QUEUE);
    DataSt *stack = newStructure(STACK);
    queue->push(queue, 5);
    queue->push(queue, 3);
    queue->push(queue, 4);
    stack->push(stack, 1);
    stack->push(stack, 2);
    stack->push(stack, 3);
    queue->print(queue);
    printf("\n");
    stack->print(stack);

    return 0;
}
