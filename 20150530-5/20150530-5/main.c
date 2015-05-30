//
//  main.c
//  20150530-5
//
//  Created by 欣 陈 on 15/5/30.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//第二篇 线性数据结构 第3章 线性表
//顺序表的基本运算
#include <stdio.h>
#define ListSize 100
typedef int DataType;
typedef struct{
    DataType list[ListSize];
    int length;
}SeqList;
//初始化线性表
void InitList(SeqList *L){
    L->length = 0;
}
//判断线性表是否为空
int ListEmpty(SeqList L){
    if(L.length == 0)
        return 1;
    else
        return 0;
}
//按序号查找
int GetElem(SeqList L,int i,DataType *e){
    if(i < 1 || i > L.length){
        return -1;
    }
    *e = L.list[i - 1];
    return 1;
}
//按内容查找
int LocateElem(SeqList L,DataType e){
    int i;
    for(i = 0;i < L.length;i++){
        if(L.list[i] == e)
            return i+1;
    }
    return 0;
}
//在顺序表的第i位置插入元素e
int InsertList(SeqList *L,int i,DataType e){
    int j;
    if(i < 1 || i > L->length+1){
        printf("插入的位置i不合法！\n");
        return -1;
    }
    else if(L->length >= ListSize){
        printf("顺序表满\n");
        return 0;
    }
    else{
        for(j = L->length;j >= i;j--){
            L->list[j] = L->list[j-1];
        }
        L->list[i-1] = e;
        L->length = L->length + 1;
        return 1;
    }
}
//删除第i个元素
int DeleteList(SeqList *L,int i,DataType *e){
    int j;
    if(L->length <= 0){
        printf("链表为空不能删除\n");
        return 0;
    }
    else if(i < 1 || i > L->length){
        printf("删除位置不合适\n");
        return -1;
    }
    else{
        *e = L->list[i - 1];
        for(j = i;j <= L->length;j++){
            L->list[j - 1] = L->list[j];
        }
        L->length = L->length - 1;
        return 1;
    }
}
//求线性表的长度
int ListLength(SeqList L){
    return L.length;
}
//清空顺序表
void ClearList(SeqList *L){
    L->length = 0;
}
