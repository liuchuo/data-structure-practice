//
//  main.c
//  20150605-1
//
//  Created by 欣 陈 on 15/6/5.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//第四章 栈
//栈的基本运算
#include <stdio.h>
#define StackSize 100
typedef int DataType;
typedef struct{
    DataType stack[StackSize];
    int top;
}SeqStack;

//初始化栈
void InitStack(SeqStack *S){
    S->top = 0;
}

//判断栈是否为空
int StackEmpty(SeqStack S){
    if(S.top == 0)
        return 1;
    else
        return 0;
}

//取栈顶元素
int GetTop(SeqStack S,DataType *e){
    if(S.top == 0){
        printf("栈已经空~\n");
        return 0;
    }
    else{
        *e = S.stack[S.top - 1];
        return 1;
    }
}

//将元素e入栈
int PushStack(SeqStack *S,DataType e){
    if(S->top >= StackSize){
        printf("栈已满 不能将元素入栈~\n");
        return 0;
    }
    else{
        S->stack[S->top] = e;
        S->top++;
        return 1;
    }
}

//将栈顶元素出栈
int PopStack(SeqStack *S,DataType *e){
    if(S->top == 0){
        printf("栈中已经没有元素，不能进行出栈操作！\n");
        return 0;
    }
    else{
        S->top--;
        *e = S->stack[S->top];
        return 1;
    }
}

//求栈的长度
int StackLength(SeqStack S){
    return S.top;
}

//清空栈
void ClearStack(SeqStack *S){
    S->top = 0;
}
