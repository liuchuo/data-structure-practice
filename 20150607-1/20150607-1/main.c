//
//  main.c
//  20150607-1
//
//  Created by 欣 陈 on 15/6/7.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//栈的链式存储结构
//链栈的结点类型和基本运算
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct node{
    DataType data;
    struct node *next;
}LStackNode,*LinkStack;

//初始化链栈
void InitStack(LinkStack *top){
    if((*top = (LinkStack)malloc(sizeof(LStackNode))) == NULL)
        exit(-1);
    (*top)->next = NULL;
}

//判断链栈是否为空
int StackEmpty(LinkStack top){
    if(top->next == NULL)
        return 1;
    else
        return 0;
}

//将元素e入栈
int PushStack(LinkStack top,DataType e){
    LStackNode *p;
    if((p = (LStackNode *)malloc(sizeof(LStackNode))) == NULL){
        printf("内存分配失败！~\n");
        exit(-1);
    }
    p->data = e;
    p->next = top->next;
    top->next = p;
    return 1;
}

//将栈顶元素出栈
int PopStack(LinkStack top,DataType *e){
    LStackNode *p;
    p = top->next;
    if(!p){
        printf("栈已空");
        return 0;
    }
    top->next = p->next;
    *e = p->data;
    free(p);
    return 1;
}

//取栈顶元素
int GetTop(LinkStack top,DataType *e){
    LStackNode *p;
    p = top->next;
    if(!p){
        printf("栈已空");
        return 0;
    }
    *e = p->data;
    return 1;
}

//求栈的长度
int StackLength(LinkStack top){
    LStackNode *p;
    int count;
    count = 0;
    p = top;
    while(p->next != NULL){
        p = p->next;
        count++;
    }
    return count;
}

//销毁链栈
void DestoryStack(LinkStack top){
    LStackNode *p,*q;
    p = top;
    while(p){
        q = p;
        p = p->next;
        free(q);
    }
}
