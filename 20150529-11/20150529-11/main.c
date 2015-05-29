//
//  main.c
//  20150529-11
//
//  Created by 欣 陈 on 15/5/29.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//创建一个链表，向链表中输入数据，然后输出链表
#include <stdio.h>
#include <stdlib.h>
struct student{
    int no;
    char name[20];
    char addr[30];
    struct student *next;
};
typedef struct student LIST;
LIST *CreateList();
void DispList(LIST *h);
int main(){
    LIST *head;
    head = CreateList();
    printf("学号  姓名      地址：\n");
    DispList(head);
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
        if(h == NULL)
            h = cur;
        else
            prev->next = cur;
        scanf("%d %s %s",&cur->no,cur->name,cur->addr);
        prev = cur;
    }
    return h;
}

void DispList(LIST *h){
    LIST *p = h;
    while(p != NULL){
        printf("%d %s %s\n",p->no,p->name,p->addr);
        p = p->next;
    }
}
