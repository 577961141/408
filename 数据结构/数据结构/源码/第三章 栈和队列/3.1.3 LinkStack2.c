#include "stdio.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int SElemType;

typedef struct StackNode {
    SElemType   data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct
{
    int count;
    LinkStackPtr top;
}LinkStack;

Status InitStack(LinkStack *S) {
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));

    if (!S->top) {
        return ERROR;
    }

    S->top->next = NULL;
    S->count = 0;

    return OK;
}

Status clearStack(LinkStack *S) {
    LinkStackPtr p,q;

    p = S->top->next;

    while (p)
    {
       q = p;
       p = q->next;
       free(p);
    }

    S->count = 0;
    return ERROR;
}

Status StackEmtype(LinkStack S) {
    if (S.count == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int StackLength(LinkStack S) {
   return S.count;
}

Status Push(LinkStack *S, SElemType e) {
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    if (!p) {
        return ERROR;
    }

    p->data = e;
    p->next = S->top->next;
    S->top->next = p;
    S->count++;

    return OK;
}

Status Pop(LinkStack *S, SElemType *e) {
    if (S->count == 0) {
        return ERROR;
    }

    LinkStackPtr p;

    p = S->top->next;
    *e = p->data;
    S->top->next =p->next;
    free(p);
     S->count--;

    return OK;
}


Status GetTop(LinkStack S, SElemType *e) {
    if (S.count == 0) {
        return ERROR;
    }
     *e = S.top->next->data;

    return OK;
}