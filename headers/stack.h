typedef struct stack{
    int value;
    struct stackT *prox;
}Stack;

void pushS(Stack , int);
Stack *reverse(Stack **);
Stack *intersection(Stack *, Stack *);
void pop(Stack **);