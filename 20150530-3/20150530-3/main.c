//
//  main.c
//  20150530-3
//
//  Created by 欣 陈 on 15/5/30.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//编写一个main函数，分别调用函数CreatList创建链表，
//调用InsertNode插入结点，调用DeleteNode删除结点,调用DispList输出结点的值
#include <stdio.h>
#include <stdlib.h>
struct student{
    long no;
    char name[20];
    char addr[30];
    struct student *next;
};
typedef struct student LIST;
LIST *CreateList();
LIST *InsertNode(LIST *h,LIST *s);
LIST *DeleteNode(LIST *h,long no);
void DispList(LIST *h);
int main(){
    LIST *head,*p;
    long no;
    head = CreateList();
    printf("学号    姓名     地址\n");
    DispList(head);
    printf("输入要插入的结点元素：\n");
    p = (LIST*)malloc(sizeof(LIST));
    scanf("%ld %s %s",&p->no,p->name,p->addr);
    head = InsertNode(head,p);
    DispList(head);
    printf("请输入一个要删除的结点的学号：\n");
    scanf("%ld",&no);
    head = DeleteNode(head,no);
    if(head != NULL){
        printf("学号    姓名    地址\n");
        DispList(head);
    }
    return 0;
}

LIST *CreateList(){
    LIST *h,*prev,*cur;
    int i,n;
    h = NULL;
    printf("输入结点个数：");
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        cur = (LIST *)malloc(sizeof(LIST));
        cur->next = NULL;
        if(h == NULL){
            h = cur;
        }
        else{
            prev->next = cur;
        }
        scanf("%ld %s %s",&cur->no,cur->name,cur->addr);
        prev = cur;
    }
    return h;
}

LIST *InsertNode(LIST *h,LIST *s){
    LIST *pre,*p;
    p = h;
    if(h == NULL){
        h = s;
        s->next = NULL;
    }
    else{
        while((s->no > p->no) &&(p->next != NULL)){
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

LIST *DeleteNode(LIST *h,long no){
    LIST *pre,*p;
    if(h == NULL){
        printf("链表为空，不能删除结点！\n");
        return NULL;
    }
    p = h;
    while((p->no != no) && (p->next != NULL)){
        pre = p;
        p = p->next;
    }
    if(p->no == no){
        if(p == h){
            h = p->next;
        }
        else{
            pre->next = p->next;
        }
        free(p);
        printf("成功删除结点!\n");
    }
    else{
        printf("没有发现要删除的结点！\n");
    }
    return h;
}

void DispList(LIST *h){
    LIST *p;
    p = h;
    while(p != NULL){
        printf("%ld  %s  %s\n",p->no,p->name,p->addr);
        p = p->next;
    }
}
