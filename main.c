#include <stdlib.h>
#include <stdio.h>
#include "headers/dataStructs.h"

int main(){
    BigS *queue = newStructure("queue");
    queue->pushar(&queue->sts, 5);
    queue->pushar(&queue->sts, 3);
    queue->pushar(&queue->sts, 4);
    printSt(queue->sts);
    return 0;
}
