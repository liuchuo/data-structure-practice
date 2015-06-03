//
//  main.c
//  20150603-2
//
//  Created by 欣 陈 on 15/6/3.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//静态链表
//静态链表的存储结构
#define ListSize 100
typedef int DataType;
typedef struct SListNode{
    DataType data;
    int cur;
}SListNode;
typedef struct{
    SListNode list[ListSize];
    int av;
}SLinkList;

//静态链表的基本运算
//初始化静态链表
void InitSList(SLinkList *L){
    int i;
    for(i = 0;i < ListSize;i++){
        (*L).list[i].cur = i + 1;
    }
    (*L).list[ListSize - 1].cur = 0;
    (*L).av = 1;
}

//分配结点
int AssignNode(SLinkList L){
    int i;
    i = L.av;
    L.av = L.list[i].cur;
    return i;
}

//回收结点。
void FreeNode(SLinkList L,int pos){
    L.list[pos].cur = L.av;
    L.av = pos;
}

//插入操作
void InsertList(SLinkList *L,int i,DataType e){
    int j,k,x;
    k = (*L).av;
    (*L).av = (*L).list[k].cur;
    (*L).list[k].data = e;
    j = (*L).list[0].cur;
    for(x = 1;x < i-1;x++){
        j = (*L).list[j].cur;
    }
    (*L).list[k].cur = (*L).list[j].cur;
    (*L).list[j].cur = k;
}

//删除操作
void DeleteSList(SLinkList *L,int i,DataType *e){
    int j,k,x;
    if(i == 1){
        k = (*L).list[0].cur;
        (*L).list[0].cur = (*L).list[k].cur;
    }
    else{
        j = (*L).list[0].cur;
        for(x = 1;x < i-1;x++){
            j = (*L).list[j].cur;
        }
        k = (*L).list[j].cur;
        (*L).list[j].cur = (*L).list[k].cur;
    }
    (*L).list[k].cur = (*L).av;
    *e = (*L).list[k].data;
    (*L).av = k;
}
