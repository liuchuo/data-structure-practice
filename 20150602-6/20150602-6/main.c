//
//  main.c
//  20150602-6
//
//  Created by 欣 陈 on 15/6/2.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//双向链表
//双向链表的结点存储结构描述
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct Node{
    DataType data;
    struct Node *prior;
    struct Node *next;
}DListNode,*DLinkList;

//插入操作
int InsertDList(DLinkList head,int i,DataType e){
    DListNode *p,*s;
    int j;
    p = head->next;
    j = 0;
    while(p != head && j < i){
        p = p->next;
        j++;
    }
    if(j != i){
        printf("error!!~~\n");
        return -1;
    }
    s = (DListNode *)malloc(sizeof(DListNode));
    if(!s){
        return -1;
    }
    s->data = e;
    s->prior = p->prior;
    p->prior->next = s;
    s->next = p;
    p->prior = s;
    return 1;
}

//删除第i个结点
int DeleteDlist(DLinkList head,int i,DataType *e){
    DListNode *p;
    int j;
    p = head->next;
    j = 0;
    while(p != head && j < i){
        p = p->next;
        j++;
    }
    if(j != i){
        printf("error~~\n");
        return -1;
    }
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return 1;
}
