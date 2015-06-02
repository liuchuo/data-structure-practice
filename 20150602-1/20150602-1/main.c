//
//  main.c
//  20150602-1
//
//  Created by 欣 陈 on 15/6/2.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//已知两个单链表A和B，其中的元素都是非递减排列，
//编写算法将单链表A和B合并得到一个递减有序的单链表C（值相同的只保留一个）并要求利用原链表的结点空间
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct Node{
    DataType data;
    struct Node *next;
}ListNode,*LinkList;

void InitList(LinkList *head){
    if((*head = (LinkList)malloc(sizeof(ListNode))) == NULL)
        exit(-1);
    (*head)->next = NULL;
}

int ListEmpty(LinkList head){
    if(head->next == NULL)
        return 1;
    else
        return 0;
}

ListNode *Get(LinkList head,int i){
    ListNode *p;
    int j;
    if(ListEmpty(head))
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
        printf("插入位置有误\n");
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

void MergeList(LinkList A,LinkList B,LinkList *C);

int main(){
    int i;
    DataType a[] = {8,10,15,21,67,91};
    DataType b[] = {5,9,10,13,21,78,91};
    LinkList A,B,C;
    ListNode *p;
    InitList(&A);
    InitList(&B);
    for(i = 1;i <= sizeof(a) / sizeof(a[0]);i++){
        if(InsertList(A,i,a[i - 1]) == 0){
            printf("a插入位置不合法\n");
            return 0;
        }
    }
    for(i = 1;i <= sizeof(b) / sizeof(b[0]);i++){
        if(InsertList(B,i,b[i - 1]) == 0){
            printf("b插入位置不合法\n");
            return 0;
        }
    }
    printf("单链表A中有%d个元素：\n",ListLength(A));
    for(i = 1;i <= ListLength(A);i++){
        p = Get(A,i);
        if(p)
            printf("%4d",p->data);
    }
    printf("\n");
    printf("单链表B中有%d个元素：\n",ListLength(B));
    for(i = 1;i <= ListLength(B);i++){
        p = Get(B,i);
        if(p)
            printf("%4d",p->data);
    }
    printf("\n");
    MergeList(A,B,&C);
    printf("单链表C中有%d个元素：\n",ListLength(C));
    for(i = 1;i <= ListLength(C);i++){
        p = Get(C,i);
        if(p)
            printf("%4d",p->data);
    }
    printf("\n");
    return 0;
}

void MergeList(LinkList A,LinkList B,LinkList *C){
    ListNode *pa,*pb,*qa,*qb;
    pa = A->next;
    pb = B->next;
    free(B);
    *C = A;
    (*C)->next = NULL;
    while(pa && pb){
        if(pa->data < pb->data){
            qa = pa;
            pa = pa->next;
            if((*C)->next == NULL){
                qa->next = (*C)->next;
                (*C)->next = qa;
            }
            else if((*C)->next->data < qa->data){
                qa->next = (*C)->next;
                (*C)->next = qa;
            }
            else
                free(qa);
        }
        else{
            qb = pb;
            pb = pb->next;
            if((*C)->next == NULL){
                qb->next = (*C)->next;
                (*C)->next = qb;
            }
            else if((*C)->next->data < qb->data){
                qb->next = (*C)->next;
                (*C)->next = qb;
            }
            else
                free(qb);
        }
    }
    
    while(pa){
        qa = pa;
        pa = pa->next;
        if((*C)->next && (*C)->next->data < qa->data){
            qa->next = (*C)->next;
            (*C)->next = qa;
        }
        else
            free(qa);
    }
    
    while(pb){
        qb = pb;
        pb = pb->next;
        if((*C)->next && (*C)->next->data < qb->data){
            qb->next = (*C)->next;
            (*C)->next = qb;
        }
        else
            free(qb);
    }
}
