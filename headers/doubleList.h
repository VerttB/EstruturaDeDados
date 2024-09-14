typedef struct dbList {
  struct dbList *prox;
  struct dbList *ant;
  int num;
} DbList;

void pushDb(void **, int);
void printDb(DbList *);
int popDb(void **);
void reverseDb(void **);