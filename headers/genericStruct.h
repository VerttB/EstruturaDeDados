#ifndef GENERICSTRUCT_H_INCLUDED
#define GENERICSTRUCT_H_INCLUDED
typedef enum {STACK, QUEUE, DBLIST} TYPE;

typedef struct dataSt{
    void *data;
    TYPE type;
    void (*push)(struct dataSt*, int);
    void (*print)(struct dataSt *);
    void (*reverse)(struct dataSt *);
}DataSt;

DataSt *newStructure(TYPE);
void print(DataSt *);
void push(DataSt *, int);
void reverse(DataSt *);
#endif