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
     int tag;
}SQueue;

Status InitQueue(SQueue *S) {
     S->top = S->rear = S->tag = 0;
     return OK;
}

Status ClearQueue(SQueue *S) {
     S->top = S->rear = S->tag = 0;
     return OK;
}

Status QueueEmpty(SQueue S) {
     if (S.top == S.rear && S.tag == 0) {
        return TURE;
     }

     return FALSE;
}

int QueueLength(SQueue S) {
     if (S.top == S.rear && S.tag == 0) { // 队空
        return 0;
     }

     if (S.top == S.rear && S.tag == 1) { // 堆满
        return MAXSIZE;
     }
     // 其他情况
     return (S.rear - S.top + MAXSIZE)%MAXSIZE;
}

Status Push(SQueue *S, SElemType e) {
     if (S->top == S->rear && S->tag == 1) {
         return ERROR;
     }

     S->data[S->rear] = e;
     S->rear = (S->rear+1) % MAXSIZE;
     S->tag = 1;

     return OK;
}

Status Pop(SQueue *S, SElemType *e) {
     if  (S->top == S->rear && S->tag == 0) {
         return ERROR;
     }

     *e = S->data[S->top];
     S->top = (S->top+1) % MAXSIZE;
     S->tag = 0;

     return OK;
}

