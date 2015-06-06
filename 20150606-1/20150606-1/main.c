//
//  main.c
//  20150606-1
//
//  Created by 欣 陈 on 15/6/6.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//共享栈的测试代码
#include <stdio.h>
#include <stdlib.h>
#define StackSize 100
typedef int DataType;
typedef struct{
    DataType stack[StackSize];
    int top[2];
}SSeqStack;

void InitStack(SSeqStack *S){
    S->top[0] = 0;
    S->top[1] = StackSize - 1;
}

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

int StackEmpty(SSeqStack S,int flag){
    switch(flag){
        case 1:
            if(S.top[0] == 0)
                return 1;
            break;
        case 2:
            if(S.top[1] == StackSize - 1)
                return 1;
            break;
        default:
            printf("输入的flag参数有误！");
            return -1;
    }
    return 0;
}

int main(){
    SSeqStack S;
    int i;
    DataType a[] = {10,20,30,40,50,60};
    DataType b[] = {100,200,300,500};
    DataType e1,e2;
    InitStack(&S);
    for(i = 0;i < sizeof(a) /sizeof(a[0]);i++){
        if(PushStack(&S,a[i],1) == 0){
            printf("栈已满，不能进栈！");
            return 0;
        }
    }
    for(i = 0;i <sizeof(b) / sizeof(b[0]);i++){
        if(PushStack(&S,b[i],2) == 0){
            printf("栈已满，不能进栈~~~、\n");
            return 0;
        }
    }
    if(GetTop(S,&e1,1) == 0){
        printf("栈已空~");
        return 0;
    }
    if(GetTop(S,&e2,2) == 0){
        printf("栈已空~");
        return 0;
    }
    printf("左端栈顶元素是：%d，右端栈的栈顶元素是：%d\n",e1,e2);
    printf("左端栈的出栈的元素次序是：");
    while(!StackEmpty(S,1)){
        PopStack(&S,&e1,1);
        printf("%5d",e1);
    }
    printf("\n");
    printf("右端栈的出栈的元素的次序是：");
    while(!StackEmpty(S,2)){
        PopStack(&S,&e2,2);
        printf("%5d",e2);
    }
    printf("\n");
    return 0;
}
