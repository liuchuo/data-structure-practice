//
//  main.c
//  20150605-2
//
//  Created by 欣 陈 on 15/6/5.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//利用顺序栈的基本操作，将元素A B C D E F依次进栈，
//然后将F和E出栈，再将G和H进栈，最后将元素全部出栈
#include <stdio.h>
#include <stdlib.h>
#define StackSize 100
typedef char DataType;
typedef struct{
    DataType stack[StackSize];
    int top;
}SeqStack;

void InitStack(SeqStack *S){
    S->top = 0;
}

int StackEmpty(SeqStack S){
    if(S.top == 0)
        return 1;
    else
        return 0;
}

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

int StackLength(SeqStack S){
    return S.top;
}

int main(){
    SeqStack S;
    int i;
    DataType a[] = {'A','B','C','D','E','F'};
    DataType e;
    InitStack(&S);
    for(i = 0;i < sizeof(a) / sizeof(a[0]);i++){
        if(PushStack(&S,a[i]) == 0){
            printf("栈已满，不能进栈！\n");
            return 0;
        }
    }
    printf("依次出栈的元素是：");
    if(PopStack(&S,&e) == 1)
        printf("%4c",e);
    if(PopStack(&S,&e) == 1)
        printf("%4c",e);
    printf("\n");
    printf("当前栈顶元素是：");
    if(GetTop(S,&e) == 0){
        printf("栈已空~\n");
        return 0;
    }
    else
        printf("%4c\n",e);
    printf("将G、H依次入栈~~、\n");
    if(PushStack(&S,'G') == 0){
        printf("栈已满 不能进栈~~~\n");
        return 0;
    }
    if(PushStack(&S,'H') == 0){
        printf("栈已满 不能进栈~~~~~、、\n");
        return 0;
    }
    printf("当前栈中的个数是：%d\n",StackLength(S));
    printf("将栈中元素出栈，出栈的序列是：\n");
    while(!StackEmpty(S)){
        PopStack(&S,&e);
        printf("%4c",e);
    }
    printf("\n");
    return 0;
}