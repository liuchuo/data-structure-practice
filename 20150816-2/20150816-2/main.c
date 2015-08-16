//
//  main.c
//  20150816-2
//
//  Created by 欣 陈 on 15/8/16.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//


//稀疏矩阵的三元组存储结构及实现
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 200
typedef int DataType;

typedef struct {
    int i;
    int j;
    DataType e;
}Triple;

typedef struct {
    Triple data[MaxSize];
    int m;
    int n;
    int len;//矩阵中非零元素的个数
}TriSeqMatrix;

int CreateMatrix(TriSeqMatrix *M) {//按照行优先顺序
    int i,m,n;
    DataType e;
    int flag;
    printf("请输入稀疏矩阵的行数、列数及非零元素个数：");
    scanf("%d,%d,%d",&M->m,&M->n,&M->len);
    if(M->len > MaxSize)
        return 0;
    for(i = 0;i < M->len;i++){
        do {
            printf("请按行序顺序输入第%d个非零元素所在的行(0~%d),列(0~%d),元素值：",i+1,M->m - 1,M->n - 1);
            scanf("%d,%d,%d",&m,&n,&e);
            flag = 0;
            if(m < 0 || m > M->m || n < 0 || n > M->n)
                flag = 1;//if the data is error,do while again
            if((i > 0 && m < M->data[i - 1].i) || (m == M->data[i - 1].i && n <= M->data[i - 1].j))
                flag = 1;//if the order of enter data is error,do while again
        }while(flag);
        M->data[i].i = m;
        M->data[i].j = n;
        M->data[i].e = e;
    }
    return 1;
}

void CopyMatrix(TriSeqMatrix M,TriSeqMatrix *N) {
    int i;
    N->len = M.len;
    N->m = M.m;
    N->n = M.n;
    for(i = 0;i < M.len;i++) {
        N->data[i].i = M.data[i].i;
        N->data[j].j = M.data[j].j;
        N->data[i].e = M.data[i].e;
    }
}