//
//  main.c
//  20150602-2
//
//  Created by 欣 陈 on 15/6/2.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//利用单链表的基本运算，求两个集合的交集
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct Node{
    DataType data;
    struct Node *next;
}ListNode,*LinkList;

void Sort(LinkList S);
void DispList(LinkList S);
void Interction(LinkList A,LinkList B,LinkList *C);
void InitList(LinkList *head);
int InsertList(LinkList A,int i,DataType e);
int ListLength(LinkList A);

int main(){
    int i;
    DataType a[] = {5,9,6,20,70,58,44,81};
    DataType b[] = {21,81,8,31,5,66,20,95,50};
    LinkList A,B,C;
    InitList(&A);
    InitList(&B);
    for(i = 1;i <= sizeof(a) / sizeof(a[0]);i++){
        if(InsertList(A,i,a[i - 1]) == 0){
            printf("位置不合法");
            return 0;
        }
    }
    for(i = 1;i <= sizeof(b) / sizeof(b[0]);i++){
        if(InsertList(B,i,b[i - 1]) == 0){
            printf("位置不合法");
            return 0;
        }
    }
    printf("单链表A中的元素有%d个:\n",ListLength(A));
    DispList(A);
    printf("单链表B中的元素有%d个:\n",ListLength(B));
    DispList(B);
    Interction(A,B,&C);
    printf("A和B的交集有%d个元素:\n",ListLength(C));
    DispList(C);
    return 0;
}

void Sort(LinkList S){
    ListNode *p,*q,*r;
    DataType t;
    p = S->next;
    while(p->next){
        r = p;
        q = p->next;
        while(q){
            if(r->data > q->data)
                r = q;
            q = q->next;
        }
        if(p != r){
            t = p->data;
            p->data = r->data;
            r->data = t;
        }
        p = p->next;
    }
}

void DispList(LinkList S){
    ListNode *p,*q;
    p = S->next;
    while(p){
        q = p;
        printf("%4d",p->data);
        p = p->next;
    }
    printf("\n");
}

void Interction(LinkList A,LinkList B,LinkList *C){
    ListNode *pa,*pb,*pc;
    Sort(A);
    printf("排序后A的元素：\n");
    DispList(A);
    Sort(B);
    printf("排序后B的元素：\n");
    DispList(B);
    pa = A->next;
    pb = B->next;
    *C = (LinkList)malloc(sizeof(ListNode));
    (*C)->next = NULL;
    while(pa && pb){
        if(pa->data < pb->data)
            pa = pa->next;
        else if(pa->data > pb->data)
            pb = pb->next;
        else{
            pc = (ListNode*)malloc(sizeof(ListNode));
            pc->data = pa->data;
            pc->next = (*C)->next;
            (*C)->next = pc;
            pa = pa->next;
            pb = pb->next;
        }
    }
}

void InitList(LinkList *head){
    if((*head = (LinkList)malloc(sizeof(ListNode))) == NULL)
        exit(-1);
    (*head)->next = NULL;
}

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
        printf("插入位置有误！\n");
        return 0;
    }
    if((p = (ListNode *)malloc(sizeof(ListNode))) == NULL)
        exit(-1);
    p->data = e;
    p->next = pre->next;
    pre->next = p;
    return 1;
}

int ListLength(LinkList head){
    int count;
    count = 0;
    ListNode *p;
    p = head;
    while(p->next != NULL){
        p = p->next;
        count++;
    }
    return count;
}
