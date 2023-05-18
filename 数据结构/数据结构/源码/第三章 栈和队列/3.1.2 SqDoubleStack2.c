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
typedef int SElemtype;

typedef struct {
     SElemtype data[MAXSIZE];
     int top1;
     int top2;
}SqDoubleStack;

Status InitStack(SqDoubleStack *S)
{
     S->top1 = -1;
     S->top2 = MAXSIZE;

     return OK;
}

Status ClearStack(SqDoubleStack *S)
{
     S->top1 = -1;
     S->top2 = MAXSIZE;

     return OK;
}


Status StackEmpty(SqDoubleStack S)
{
     if (S.top1 == 0 && S.top2 == MAXSIZE) {
          return TRUE;
     }

     return FALSE;
}

int StackLength(SqDoubleStack S) {
     return (S.top1+1)+(MAXSIZE - S.top2);
}

Status Push(SqDoubleStack *S, SElemtype e, int StackNumber)
{
     // 栈满
     if (S->top1+1 == S->top2) {
          return ERROR;
     }

     if (StackNumber == 1) {
          S->data[++S->top1] = e;
     }

     if (StackNumber == 2) {
          S->data[--S->top2] = e;
     }


     return OK;
}

Status Pop(SqDoubleStack *S, SElemtype *e, int StackNumber)
{
     // 栈空
     if (StackNumber == 1 && S->top1 == -1) {
          return ERROR;
     }

     if (StackNumber == 2 && S->top1 == MAXSIZE) {
          return ERROR;
     }

     if (StackNumber == 1){
          *e = S->data[S->top1--];
     }

     if (StackNumber == 2){
          *e = S->data[S->top2++];
     }

     return OK;
}

Status GetTop(SqDoubleStack S, SElemtype *e, int StackNumber)
{
     // 栈空
     if (StackNumber == 1 && S.top1 == -1) {
          return ERROR;
     }

     if (StackNumber == 2 && S.top1 == MAXSIZE) {
          return ERROR;
     }

     if (StackNumber == 1){
          *e = S.data[S.top1];
     }

     if (StackNumber == 2){
          *e = S.data[S.top2];
     }

     return OK;
}