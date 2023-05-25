#include "stdlib.h"

#include "math.h"
#include "time.h"



#define MaxSize 10      // 定义元素的最大容量
typedef struct {
     char data[MaxSize];
     int top;
} SqStack;

// 初始化栈
void InitStack(SqStack *s);

// 判断栈是否为空
bool StackEmpty(SqStack s);

// 新元素入栈
bool Push(SqStack *s, char x);

// 栈顶元素出栈，用x返回
bool Pop(SqStack *s, char *x);

bool bracketCheck(char str[], int length) {
     SqStack S;
     InitStack(&S);      // 初始化一个栈

     for (int i = 0; i < length; i++) {
         if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
             Push(&S, str[i]);       // 扫描到左括号，入栈
         } else {
             if (StackEmpty(S)) {    // 扫描到右括号，且当前栈为空
                 return false;       // 匹配失败
             }

             char topElem;
             Pop(&S, &topElem);      // 栈顶元素出栈
             if (str[i] == ')' && topElem != '(') {
                 return false;
             }

             if (str[i] == ']' && topElem != '[') {
                 return false;
             }

             if (str[i] == '}' && topElem != '{') {
                 return false;
             }
         }
     }

     if (!StackEmpty(S)) {       // 还有未匹配的右括号
         return false;
     }

     return true;
}

