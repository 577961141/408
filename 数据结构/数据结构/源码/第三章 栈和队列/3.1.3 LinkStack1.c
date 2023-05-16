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

    p = S->top;

    while (p)
    {
        q = p;
        p = q->next;
        free(q);
    }

    S->count = 0;
    return OK;
}

Status StackEmtype(LinkStack S) {
    if (S.count == 0) {
        return TRUE;
    }

    return FALSE;
}

int StackLength(LinkStack S) {
    return S.count;
}

Status Push(LinkStack *S, SElemType e) {
    LinkStackPtr q = (LinkStackPtr)malloc(sizeof(StackNode));
    if (!q) {
        return ERROR;
    }

    q->data = e;
    q->next = S->top;
    S->top = q;
    S->count++;
    return OK;
}

Status Pop(LinkStack *S, SElemType *e) {
    if (S->count == 0) {
        return ERROR;
    }

    LinkStackPtr q;
    q = S->top;
    *e = q->data;
    S->top = q->next;
    free(q);
    S->count--;

    return OK;
}

Status GetTop(LinkStack S, SElemType *e) {
    if (S.count == 0) {
        return ERROR;
    }

    *e = S.top->data;
    return OK;
}