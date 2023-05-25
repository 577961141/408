#include "stdlib.h"

#include "math.h"
#include "time.h"


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int QElement;

typedef struct QNode{
    QElement data;
    struct QNode *next;
}QNode, *LinkQueuePtr;

typedef struct {
    LinkQueuePtr front,rear;
}LinkQueue;

Status InitQueue(LinkQueue *Q)
{
     // 带头结点也是这样，不带头结点也这样
    Q->front = Q->rear = (LinkQueuePtr)malloc(sizeof(QNode));

     if (!Q->front) {
         return ERROR;
     }

     Q->front->next = NULL;
     return OK;
}

Status DestroyQueue(LinkQueue *Q) {
     // 带头结点也是这样，不带头结点也这样
     while (Q->front) {
         Q->rear = Q->front->next;
         free(Q->front);
         Q->front = Q->rear;
     }

     return OK;
}

Status ClearQueue(LinkQueue *Q) {
     // 带头结点
     LinkQueuePtr p,q;
     Q->rear = Q->front;
     p = Q->front->next;
     Q->front->next = NULL;

     while(p) {
         q = p;
         p = q->next;
         free(q);
     }

     return OK;
}

Status QueueEmpty(LinkQueue Q) {
     // 带头结点
     if (Q.front == Q.rear) {
         return TRUE;
     } else {
         return FALSE;
     }

     // 不带头结点
      if (Q.front == NULL) {
          return TRUE;
      } else {
          return FALSE;
      }
}

 int QueueLength(LinkQueue Q) {
     int i = 0;
     LinkQueuePtr p;
     p = Q.front;
     while(Q.rear != p) {
         i++;
         p = p->next;
     }

     return i;
}

Status EnQueue(LinkQueue *Q, QElement e) {
     LinkQueuePtr s = (LinkQueuePtr)malloc(sizeof(QNode));
     if (!s) {
         return ERROR;
     }

     s->data = e;
     s->next = NULL;
     Q->rear->next = s;
     Q->rear = s;
     return OK;
}

Status DeQueue(LinkQueue *Q, QElement *e) {
     if (Q->front == Q->rear) { // 空的
         return ERROR;
     }

      LinkQueuePtr p;

     p = Q->front->next;
     *e = p->data;
     Q->front->next = p->next;

     if (p == Q->rear) {
         Q->rear = Q->front;
     }

     free(p);
     return OK;
}