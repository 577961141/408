
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MaxSize 50                      // 定义线性表的最大长度
typedef int ElemType;                   /* ElemType类型根据实际情况而定，这里假设为int */
typedef struct{
    ElemType data[MaxSize];             // 顺序表中的元素
    int length;                         // 顺序表当前的长度
}SqList;                                // 顺序表的类型定义

typedef int Status;

/* 插入元素 */
Status ListInsert(SqList *L, int i, ElemType e) {
    int k;
    if (L->length == MaxSize) {         /* 说明顺序表的元素满了 */
        return ERROR;
    }
    if (i < 1 || i > L->length+1) {     /* 判断i是否在有效范围内 */
        return ERROR;
    }

    // for (k = L->length; k >= i; k--) /* 将要插入位置后的元素向后移一位 */
    // {
    //     L->data[k] = L->data[k-1];
    // }

    if (i <= L->length) {               /* 如果插入数据不在表尾 */
        for (k = L->length-1; k >= i - 1; k--) /* 将要插入位置后的元素向后移一位 */
        {
            L->data[k+1] = L->data[k];
        }
        
    }

    L->data[i-1] = e;                   /* 将新元素插入 */
    L->length++;

    return OK;
}

/* 删除元素 */
Status ListDelete(SqList *L, int i, ElemType *e)  
{
    int k;
    if (L->length == 0) {               /* 线性表的数据为空 */
        return ERROR;
    }

    if (i < 1 || i > L->length) {       /* 删除位置不正确 */
        return ERROR;
    }

    *e = L->data[i - 1];
    if (i < L->length) {                /* 如果删除不是最后的位置 */
        for (k = i; k < L->length; k++) { /* 将删除位置后继元素前移 */
            L->data[k-1] = L->data[k];
        }
    }
    L->length--;
    return OK;
}

/* 查找线性表某个值第一次出现的位序 */
int LocateElem(SqList L, ElemType e) {
    int i;
    for (i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i+1;
        }
    }
    return 0;
}
