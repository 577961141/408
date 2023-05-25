#include "stdlib.h"

#include "math.h"
#include "time.h"


#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int SElemType;

typedef struct {
     SElemType data[MAXSIZE];
     int top;
     int rear;
     int size;
}SQueue;

Status InitQueue(SQueue *S) {
     S->top = S->rear = S->size = 0;
     return OK;
}

Status ClearQueue(SQueue *S) {
     S->top = S->rear = S->size = 0;
     return OK;
}

Status QueueEmpty(SQueue S) {
     if (S.size == 0) {
        return TURE;
     }

     return FALSE;
}

int QueueLength(SQueue S) {
     return S.size;
}

Status Push(SQueue *S, SElemType e) {
     if (S->size == MAXSIZE) {
         return ERROR;
     }

     S->data[S->rear] = e;
     S->rear = (S->rear+1) % MAXSIZE;
     S->size += 1;

     return OK;
}

Status Pop(SQueue *S, SElemType *e) {
     if  (S->size == 0) {
         return ERROR;
     }

     *e = S->data[S->top];
     S->top = (S->top+1) % MAXSIZE;
     S->size--;

     return OK;
}
