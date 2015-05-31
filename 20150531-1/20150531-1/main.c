//
//  main.c
//  20150531-1
//
//  Created by 欣 陈 on 15/5/31.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//编写一个算法，把一个顺序表拆分成两个部分，使线性表中<=0的数位于左端，>0的数位于右端
//要求不占用额外的存储空间。
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

int InsertList(SeqList *L,int i,DataType e){
    int j;
    if(i < 1 || i > L->length + 1){
        printf("插入位置不合法！\n");
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
        L->list[j - 1] = e;
        L->length = L->length + 1;
        return 1;
    }
}

int GetElem(SeqList L,int i,DataType *e){
    if(i < 1 || i > L.length)
        return -1;
    *e = L.list[i - 1];
    return 1;
}

void SqlitSeqList(SeqList *L){
    int i,j;
    DataType e;
    i = 0;
    j = (*L).length - 1;
    while(i < j){
        while(L->list[i] <= 0)
            i++;
        while(L->list[j] > 0)
            j--;
        if(i < j){
            e = L->list[i];
            L->list[i] = L->list[j];
            L->list[j] = e;
        }
    }
}

int main(){
    int i,flag,n;
    DataType e;
    SeqList L;
    int a[] = {-12,3,-6,-10,20,-7,9,-20};
    InitList(&L);
    n = sizeof(a) / sizeof(a[0]);
    for(i = 1;i <= n;i++){
        if(InsertList(&L,i,a[i - 1]) == 0){
            printf("位置不合法~\n");
            return 0;
        }
    }
    printf("顺序表中的元素：\n");
    for(i = 1;i <= L.length;i++){
        flag = GetElem(L,i,&e);
        if(flag == 1){
            printf("%4d",e);
        }
    }
    printf("\n");
    printf("调整后的表~：\n");
    SqlitSeqList(&L);
    for(i = 1;i <= L.length;i++){
        flag = GetElem(L,i,&e);
        if(flag == 1){
            printf("%4d",e);
        }
    }
    printf("\n");
    return 0;
}
