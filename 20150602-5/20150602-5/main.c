//
//  main.c
//  20150602-5
//
//  Created by 欣 陈 on 15/6/2.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//已知一个带捎点h的循环单链表中的数据元素含有正数和负数，试编写一个算法
//构造两个循环单链表，使一个循环单链表中只含正数，另一个循环链表中只含有负数
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct Node{
    DataType data;
    struct Node *next;
}ListNode,*LinkList;

LinkList CreateCycList();
void Split(LinkList ha,LinkList hb);
void DispCyclist(LinkList h);

int main(){
    LinkList ha,hb;
    ListNode *s,*p;
    ha = NULL;
    hb = NULL;
    ha = CreateCycList();
    p = ha;
    while(p->next != ha){
        p = p->next;
    }
    s = (ListNode *)malloc(sizeof(ListNode));
    s->next = ha;
    ha = s;
    p->next = ha;
    s = (ListNode *)malloc(sizeof(ListNode));
    s->next = hb;
    hb = s;
    
    Split(ha,hb);
    printf("输出单链表A:\n");
    DispCyclist(ha);
    printf("输出单链表B:\n");
    DispCyclist(hb);
    return 0;
}

LinkList CreateCycList(){
    ListNode *h,*s,*t;
    h = NULL;
    s = NULL;
    t = NULL;
    DataType e;
    int i = 1;
    printf("创建一个循环单链表（输入0表示创建结束）:\n");
    while(1){
        printf("请输入第%d个结点的data域值：",i);
        scanf("%d",&e);
        if(e == 0){
            break;
        }
        if(i == 1){
            h = (ListNode *)malloc(sizeof(ListNode));
            h->data = e;
            h->next = NULL;
            t = h;
        }
        else{
            s = (ListNode *)malloc(sizeof(ListNode));
            s->data = e;
            s->next = NULL;
            t->next = s;
            t = s;
        }
        i++;
    }
    if(t != NULL){
        t->next = h;
    }
    return h;
}

void Split(LinkList ha,LinkList hb){
    ListNode *ra,*rb,*p;
    int v;
    p = ha->next;
    ra = ha;
    ra->next = NULL;
    rb = hb;
    rb->next = NULL;
    while(p != ha){
        v = p->data;
        if(v > 0){
            ra->next = p;
            ra = p;
        }
        else{
            rb->next = p;
            rb = p;
        }
        p = p->next;
    }
    ra->next = ha;
    rb->next = hb;
}

void DispCyclist(LinkList h){
    ListNode *p;
    p = h->next;
    if(p == NULL){
        printf("链表为空！\n");
        return;
    }
    while(p->next != h){
        printf("%4d",p->data);
        p = p->next;
    }
    printf("%4d",p->data);
    printf("\n");
}
