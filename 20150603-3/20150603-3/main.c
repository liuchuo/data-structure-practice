//
//  main.c
//  20150603-3
//
//  Created by 欣 陈 on 15/6/3.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//利用静态链表的基本操作创建静态链表，通过键盘输入想要插入的元素及位置向静态链表中插入元素
//通过输入删除元素的位置删除静态链表中的元素
#include <stdio.h>
#include <stdlib.h>
#define ListSize 100
typedef int DataType;
typedef struct Node{
    DataType data;
    int cur;
}SLinkNode;
typedef struct{
    SLinkNode list[ListSize];
    int av;
}SLinkList;

void PrintDList(SLinkList L,int n);
void InitSList(SLinkList *L);
void InsertSList(SLinkList *L,int i,DataType e);
void DeleteSList(SLinkList *L,int i,DataType *e);

int main(){
    SLinkList L;
    int i,num;
    int pos;
    int e;
    DataType a[] = {20,15,-82,37,52,8,-90};
    num = sizeof(a) / sizeof(a[0]);
    InitSList(&L);
    for(i = 1;i <= num;i++){
        InsertSList(&L,i,a[i - 1]);
    }
    printf("静态链表中的元素：\n");
    PrintDList(L,num);
    printf("请输入要插入的元素和位置:");
    scanf("%d",&e);
    getchar();
    scanf("%d",&pos);
    getchar();
    InsertSList(&L,pos,e);
    printf("插入元素后，静态链表中的元素：\n");
    PrintDList(L,num + 1);
    printf("请输入要删除的位置：\n");
    scanf("%d",&pos);
    getchar();
    DeleteSList(&L,pos,&e);
    printf("元素%d已经被删除。\n",e);
    printf("删除元素后，静态链表中的元素：\n");
    PrintDList(L,num);
    return 0;
}

void PrintDList(SLinkList L,int n){
    int j,k;
    k = L.list[0].cur;
    for(j = 1;j <= n;j++){
        printf("%3d",L.list[k].data);
        k = L.list[k].cur;
    }
    printf("\n");
}

void InitSList(SLinkList *L){
    int i;
    for(i = 0;i < ListSize;i++){
        (*L).list[i].cur = i+1;
    }
    (*L).list[ListSize - 1].cur = 0;
    (*L).av = 1;
}

void InsertSList(SLinkList *L,int i,DataType e){
    int j,k,x;
    k = (*L).av;
    (*L).list[k].data = e;
    (*L).av = (*L).list[k].cur;
    j = (*L).list[0].cur;
    for(x = 1;x < i-1;x++){
        j = (*L).list[j].cur;
    }
    (*L).list[k].cur = (*L).list[j].cur;
    (*L).list[j].cur = k;
}

void DeleteSList(SLinkList *L,int i,DataType *e){
    int j,k,x;
    if(i == 1){
        k = (*L).list[0].cur;
        (*L).list[0].cur = (*L).list[k].cur;
    }
    else{
        j = (*L).list[0].cur;
        for(x = 1;x < i-1;i++){
            j = (*L).list[i].cur;
        }
        k = (*L).list[j].cur;
        (*L).list[j].cur = (*L).list[k].cur;
    }
    (*L).list[k].cur = (*L).av;
    *e = (*L).list[k].data;
    (*L).av = k;
}
