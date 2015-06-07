//
//  main.c
//  20150607-2
//
//  Created by 欣 陈 on 15/6/7.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//辗转相除法~~~喵~~~
//链表应用举例:利用链表模拟栈实现将十进制数5678转换为对应的八进制数
//辗转相处法实现将十进制数转换为八进制数
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct node{
    DataType data;
    struct node *next;
}LStackNode,*LinkStack;

void Conversion(int N){
    LStackNode *p,*top;
    top = NULL;
    do{
        p = (LStackNode *)malloc(sizeof(LStackNode));
        p->data = N%8;
        p->next = top;
        top = p;
        N = N / 8;
    }while(N != 0);
    while(top != NULL){
        p = top;
        printf("%d",p->data);
        top = top->next;
        free(p);
    }
}

int main(){
    int n;
    printf("请输入一个十进制数：\n");
    scanf("%d",&n);
    printf("转换后的八进制数为：\n");
    Conversion(n);
    printf("\n");
    return 0;
}
