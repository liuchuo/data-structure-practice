//
//  main.c
//  20150607-3
//
//  Created by 欣 陈 on 15/6/7.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//用栈检验括号匹配问题,设计一个算法判断表达式的括号是否匹配
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
typedef char DataType;
typedef struct node{
    DataType data;
    struct node *next;
}LStackNode,*LinkStack;

void InitStack(LinkStack *top){
    if((*top = (LinkStack)malloc(sizeof(LStackNode))) == NULL)
        exit(-1);
    (*top)->next = NULL;
}


int Match(DataType e,DataType ch);
int main(){
    LinkStack S;
    char *p;
    DataType e;
    DataType ch[60];
    InitStack(&S);
}
