//
//  main.c
//  20150601-1
//
//  Created by 欣 陈 on 15/6/1.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
//单链表的基本运算
//单链表的存储结构
typedef int DataType;
typedef struct Node{
    DataType data;
    struct Node *next;
}ListNode,*LinkList;

//初始化单链表
void InitList(LinkList *head){
    if((*head = (LinkList)malloc(sizeof(ListNode))) == NULL)
        exit(-1);
    (*head)->next = NULL;
}

//判断单链表是否为空
int ListEmpty(LinkList head){
    if(head->next == NULL)
        return 1;
    else
        return 0;
}

//按序号查找操作
ListNode *Get(LinkList head,int i){
    ListNode *p;
    int j;
    while(ListEmpty(head))
        return NULL;
    if(i < 1)
        return NULL;
    j = 0;
    p = head;
    while(p->next != NULL && j < i){
        p = p->next;
        j++;
    }
    if(j == i)
        return p;
    else
        return NULL;
}

//按内容查找
ListNode *LocateElem(LinkList head,DataType e){
    ListNode *p;
    p = head->next;
    while(p){
        if(p->data != e)
            p = p->next;
        else break;
    }
    return p;
}

//定位操作。定位操作与按内容查找类似，只是返回值为该结点的序号。
int LocatePos(LinkList head,DataType e){
    ListNode *p = NULL;
    int i;
    if(ListEmpty(head))
        return 0;
    i = 1;
    p = head->next;
    while(p){
        if(p->data == e)
            return i;
        else{
            p = p->next;
            i++;
        }
    }
    return 0;
}

//在第i的位置插入元素e
int InsertList(LinkList head,int i,DataType e){
    ListNode *pre,*p;
    int j;
    pre = head;
    j = 0;
    while(pre->next != NULL && j < i-1){
        pre = pre->next;
        j++;
    }
    if(j != i-1){
        printf("插入位置错误~\n");
        return 0;
    }
    if((p = (ListNode *)malloc(sizeof(ListNode))) == NULL)
        exit(-1);
    p->data = e;
    p->next = pre->next;
    pre->next = p;
    return 1;
}

//删除第i个结点
int DeleteNode(LinkList head,int i,DataType *e){
    ListNode *pre,*p;
    int j;
    pre = head;
    j = 0;
    while(pre->next != NULL &&pre->next->next != NULL && j<i-1){
        pre = pre->next;
        j++;
    }
    if(j != i-1){
        printf("删除位置有误~\n");
        return 0;
    }
    p = pre->next;
    *e = p->data;
    pre->next = p->next;
    free(p);
    return 1;
}

//求表长操作
int ListLength(LinkList head){
    ListNode *p;
    int count;
    count = 0;
    p = head;
    while(p->next != NULL){
        p = p->next;
        count++;
    }
    return count;
}

//销毁链表
void DestoryList(LinkList head){
    ListNode *p,*q;
    p = head;
    while(p != NULL){
        q = p;
        p = p->next;
        free(q);
    }
}
