//
//  main.c
//  20150530-2
//
//  Created by 欣 陈 on 15/5/30.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
struct student{
    int no;
    char name[20];
    char addr[30];
    struct student *next;
};
typedef struct student LIST;

//在链表中删除一个结点
LIST *DeleteNode(LIST *h,long no){
    LIST *pre,*p;
    if(h == NULL){
        printf("链表为空~不能~删除~结点~~\n");
        return NULL;
    }
    p = h;
    while((p->no != no) && (p->next != NULL)){
        pre = p;
        p = p->next;
    }
    if(p->no == no){
        if(p == h)
            h = p->next;
        else
            pre->next = p->next;
        free(p);
        printf("结点成功删除~\n");
    }
    else
        printf("没有发现要删除的结点~\n");
    return h;
}
