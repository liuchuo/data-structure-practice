//
//  main.c
//  20150530-1
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

//在链表中插入新结点
LIST *InsertNode(LIST *h,LIST *s){
    LIST *pre,*p;
    p = h;
    if(h == NULL){
        h = s;
        s->next = NULL;
    }
    else{
        while((s->no > p->no) && (p->next != NULL)){
            pre = p;
            p = p->next;
        }
        if(s->no <= p->no){
            if(h == p){
                h = s;
                s->next = p;
            }
            else{
                pre->next = s;
                s->next = p;
            }
        }
        else{
            p->next = s;
            s->next = NULL;
        }
    }
    return h;
}