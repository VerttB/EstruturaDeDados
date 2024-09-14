#include <stdlib.h>
#include <stdio.h>
#include "source/genericStruct.c"




int main(){
    DataSt *stack = newStructure(DBLIST);
    stack->push(stack,2);
    stack->push(stack,5);
    stack->push(stack,1);
    stack->print(stack);
  


    return 0;
}
