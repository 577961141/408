#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int QElemType;
typedef struct QNode
{
     QElemType data;
     struct QNode *next;
}QNode, *QueuePtr;
typedef struct
{
     QueuePtr front, rear;
}LinkQueue;
Status InitQueue(LinkQueue *Q) {
     Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
     if (!Q->front) {
         return ERROR;
     }
     Q->front->next = NULL;
     return OK;
}
Status DestroyQueue(LinkQueue *Q)
{
     while (Q->front) {
         Q->rear = Q->front->next;
         free(Q->front);
         Q->front = Q->rear;
     }
     return OK;
}
Status clearQueue(LinkQueue *Q)
{
     QueuePtr p,q;
     Q->rear = Q->front;
     p = Q->front->next;
     Q->front->next = NULL;
     while(p) {
         q = p;
         p = p->next;
         free(q);
     }
     return OK;
}
Status QueueEmpty(LinkQueue Q) {
     if (Q.front == Q.rear) {
         return TRUE;
     } else {
         return FALSE;
     }
}
Status EnQueue(LinkQueue *Q, QElemType e)
{
     QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
     if (!s) {
         return ERROR;
     }
     s->data = e;
     s->next = NULL;
     Q->rear->next = s;
     Q->rear = s;
     return OK;
}
Status DeQueue(LinkQueue *Q, QElemType *e) {
     QueuePtr s;
     if (Q->front == Q->rear) {
         return ERROR;
     }
     s = Q->front->next;
     *e = s->data;
     Q->front->next = s->next;
     if (s == Q->rear) {
         Q->rear = Q->front;
     }
     free(s);
     return OK;
}
 int QueueLength(LinkQueue Q)
{
     QueuePtr p;
     p = Q.front->next;
     int count = 0;
     while (p) {
         count++;
         p = p->next;
     }
     return count;
}
Status GetHead(LinkQueue Q, QElemType *e)
{
     if (Q.front == Q.rear) {
         return ERROR;
     }
     *e = Q.front->next->data;
     return OK;
}