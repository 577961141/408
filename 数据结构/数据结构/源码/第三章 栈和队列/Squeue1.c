#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int SElemType;

typedef struct {
     SElemType data[MAXSIZE];
     int top;
     int rear;
}SQueue;

Status InitQueue(SQueue *S) {
     S->top = S->rear = 0;
     return OK;
}

Status ClearQueue(SQueue *S) {
     S->top = S->rear = 0;
     return OK;
}

Status StackEmpty(SQueue S) {
     if (S.top == S.rear) {
        return TRUE;
     }

     return FALSE;
}

int StackLength(SQueue S) {
    return (S.rear-S.top+MAXSIZE)%MAXSIZE;
}

Status Push(SQueue *S, SElemType e) {
     if  (S->top == (S->rear+1) % MAXSIZE) {
         return ERROR;
     }

     S->data[S->rear] = e;
     S->rear = (S->rear+1) % MAXSIZE;

     return OK;
}

Status Pop(SQueue *S, SElemType *e) {
     if  (S->top == S->rear) {
         return ERROR;
     }

     e = S->data[S->top];
     S->top = (S->top+1) % MAXSIZE;

     return OK;
}
