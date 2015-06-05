//
//  main.c
//  20150605-3
//
//  Created by 欣 陈 on 15/6/5.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//共享栈的基本运算
#include <stdio.h>
#include <stdlib.h>
#define StackSize 100
typedef char DataType;
typedef struct{
    DataType stack[StackSize];
    int top[2];
}SSeqStack;

//初始化栈
void InitStack(SSeqStack *S){
    S->top[0] = 0;
    S->top[1] = StackSize - 1;
}

//取出栈顶元素
int GetTop(SSeqStack S,DataType *e,int flag){
    switch(flag){
    case 1:
        if(S.top[0] == 0)
            return 0;
        *e = S.stack[S.top[0] - 1];
        break;
    case 2:
        if(S.top[1] == StackSize - 1)
            return 0;
        *e = S.stack[S.top[1] + 1];
        break;
    default:
        return 0;
    }
    return 1;
}

//将元素e入栈
int PushStack(SSeqStack *S,DataType e,int flag){
    if(S->top[0] == S->top[1])
        return 0;
    switch(flag){
        case 1:
            S->stack[S->top[0]] = e;
            S->top[0]++;
            break;
        case 2:
            S->stack[S->top[1]] = e;
            S->top[1]--;
            break;
        default:
            return 0;
    }
    return 1;
}

//将栈顶元素出栈
int PopStack(SSeqStack *S,DataType *e,int flag){
    switch(flag){
        case 1:
            if(S->top[0] == 0)
                return 0;
            S->top[0]--;
            *e = S->stack[S->top[0]];
            break;
        case 2:
            if(S->top[1] == 0)
                return 0;
            S->top[1]++;
            *e = S->stack[S->top[1]];
            break;
        default:
            return 0;
    }
    return 1;
}

//判断栈是否为空。
int StackEmpty(SSeqStack S,int flag){
    switch(flag){
        case 1:
            if(S.top[0] == 0)
                return 1;
            break;
        case 2:
            if(S.top[1] == 0)
                return 1;
            break;
        default:
            printf("输入的flag参数有误！");
            return -1;
    }
    return 0;
}
