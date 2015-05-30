//
//  main.c
//  20150530-6
//
//  Created by 欣 陈 on 15/5/30.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//扩大线性表LA，将存在于线性表B中且不存在于A中的元素插入A中
#include <stdio.h>
#define ListSize 100
typedef int DataType;
typedef struct{
    DataType list[ListSize];
    int length;
}SeqList;

void InitList(SeqList *L){
    L->length = 0;
}

int GetElem(SeqList L,int i,DataType *e){
    if(i < 1 || i > L.length){
        return -1;
    }
    *e = L.list[i-1];
    return 1;
}

int LocateElem(SeqList L,DataType e){
    int i;
    for(i = 0;i < L.length;i++){
        if(L.list[i] == e){
            return i+1;
        }
    }
    return 0;
}

int InsertList(SeqList *L,int i,DataType e){
    int j;
    if(i < 1 || i > L->length + 1){
        printf("插入的位置i不合法！\n");
        return -1;
    }
    else if(L->length >= ListSize){
        printf("顺序表已满！\n");
        return 0;
    }
    else{
        for(j = L->length;j >= i;j--){
            L->list[j] = L->list[j - 1];
        }
        L->list[i - 1] = e;
        L->length = L->length + 1;
        return 1;
    }
}

int main(){
    void UnionAB(SeqList *LA,SeqList LB);
    int i;
    int flag;
    DataType e;
    DataType a[]={2,3,17,20,9,31};
    DataType b[]={8,31,5,17,22,9,48,67};
    SeqList LA,LB;
    InitList(&LA);
    InitList(&LB);
    for(i = 0;i < sizeof(a) / sizeof(a[0]);i++){
        if(InsertList(&LA,i+1,a[i]) == 0){
            printf("插入顺序表LA失败！位置不合法\n");
            return 0;
        }
    }
    for(i = 0;i < sizeof(b) / sizeof(b[0]);i++){
        if(InsertList(&LB,i+1,b[i]) == 0){
            printf("插入线性表LB失败！位置不合法\n");
            return 0;
        }
    }
    printf("顺序表LA中的元素：\n");
    for(i = 1;i <= LA.length;i++){
        flag = GetElem(LA,i,&e);
        if(flag == 1){
            printf("%4d",e);
        }
    }
    printf("\n");
    printf("顺序表LB中的元素：\n");
    for(i = 1;i <= LB.length;i++){
        flag = GetElem(LB,i,&e);
        if(flag == 1){
            printf("%4d",e);
        }
    }
    printf("\n");
    printf("将LB中但不在LA中的元素插入到LA中：\n");
    UnionAB(&LA,LB);
    for(i = 1;i <= LA.length;i++){
        flag = GetElem(LA,i,&e);
        if(flag == 1){
            printf("%4d",e);
        }
    }
    printf("\n");
    return 0;
}

void UnionAB(SeqList *LA,SeqList LB){
    int i,flag,pos;
    DataType e;
    for(i = 1;i <= LB.length;i++){
        flag = GetElem(LB,i,&e);
        if(flag == 1){
            pos = LocateElem(*LA,e);
            if(!pos){
                InsertList(LA,LA->length+1,e);
            }
        }
    }
}