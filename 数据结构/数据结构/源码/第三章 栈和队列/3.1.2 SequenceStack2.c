#include "stdio.h"
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

typedef  struct {
     SElemType data[MAXSIZE];
     int top;
}SequenceStack;

Status InitStack(SequenceStack *s) {
     s->top = 0;
     return OK;
}

Status ClearStack(SequenceStack *s) {
     s->top = 0;
     return OK;
}

Status StackEmpty(SequenceStack s) {
     if (s.top == 0) {
         return TRUE;
     }

     return FALSE;
}

Status StackLength(SequenceStack s) {
     return s.top;
}

Status Push(SequenceStack *s, SElemType e) {
    if (s->top == MAXSIZE-1){
         return ERROR;
     }

     s->data[s->top++] = e;

     return OK;
}

Status Pop(SequenceStack *s, SElemType *e) {
     if (s->top == 0) {
         return ERROR;
     }

     *e = s->data[--s->top];
     return OK;
}

Status GetTop(SequenceStack s, SElemType *e) {
     if (s.top == 0) {
         return ERROR;
     }

     *e = s.data[s.top-1];
     return OK;
}
