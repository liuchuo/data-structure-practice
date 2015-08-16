//
//  main.c
//  20150816-6
//
//  Created by 欣 陈 on 15/8/16.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//2.三元组存储时的算法
/*三元组顺序表的类型定义，只需要增加一个成员数组rpos，用来存储三元组中每一行的第一个非零元素的位置*/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 200
typedef int DataType;
typedef struct{
    int i;
    int j;
    DataType e;
}Triple;
typedef struct{
    Triple data[MaxSize];
    int rpos[MaxSize];
    int m;
    int n;
    int len;
}TriSeqMatrix;

void MultMatrix(TriSeqMatrix A,TriSeqMatrix B,TriSeqMatrix *C);
void PrintMatrix(TriSeqMatrix M);
int CreateMatrix(TriSeqMatrix *M);

void MultMatrix(TriSeqMatrix A,TriSeqMatrix B,TriSeqMatrix *C){
    int i,k;
    int tp,tq,p,q;
    int arow,brow,ccol;
    int temp[MaxSize];
    int num[MaxSize];
    if(A.n != B.m)
        return;
    C->m = A.m;
    C->n = B.n;
    C->len = 0;
    if(A.len * B.len == 0)
        return;
    
    for(i = 0;i < B.m;i++)
        num[i] = 0;
    for(k = 0;k < B.len;k++){
        i = B.data[k].i;
        num[i]++;
    }
    B.rpos[0] = 0;
    for(i = 1;i < B.m;i++)
        B.rpos[i] = B.rpos[i - 1] + num[i - 1];
    
    for(i = 0;i < A.m;i++)
        num[i] = 0;
    for(k = 0;k < A.len;k++){
        i = B.data[k].i;
        num[i]++;
    }
    A.rpos[0] = 0;
    for(i = 1;i < A.m;i++)
        A.rpos[i] = A.rpos[i - 1] + num[i - 1];
    
    for(arow = 0;arow < A.m;arow++){
        for(i = 0;i < B.n;i++)
            temp[i] = 0;
        C->rpos[arow] = C->len;
        if(arow < A.m - 1)
            tp = A.rpos[arow + 1];
        else
            tp = A.len;
        for(p = A.rpos[arow];p < tp;p++){
            brow = A.data[p].j;
            if(brow < B.m - 1)
                tq = B.rpos[brow + 1];
            else
                tq = B.len;
            for(q = B.rpos[brow];q < tq;q++){
                ccol = B.data[q].j;
                temp[ccol] += A.data[p].e * B.data[q].e;
            }
        }
        for(ccol = 0;ccol < C->n;ccol++)
            if(temp[ccol]){
                if(++C->len > MaxSize)
                    return;
                C->data[C->len - 1].i = arow;
                C->data[C->len - 1].j = ccol;
                C->data[C->len - 1].e = temp[ccol];
            }
    }
}

int CreateMatrix(TriSeqMatrix *M){
    int i,m,n;
    DataType e;
    int flag;
    printf("请输入稀疏矩阵的行数，列数以及非零元素的个数：");
    scanf("%d,%d,%d",&M->m,&M->n,&M->len);
    if(M->len > MaxSize)
        return 0;
    for(i = 0;i < M->len;i++){
        do{
            printf("请按行序顺序输入第%d个非零元素所在的行(1~%d),列(1~%d),元素值：",i,M->m,M->n);
            scanf("%d,%d,%d",&m,&n,&e);
            flag = 0;
            if(m < 0 || m > M->m || n < 0 || n > M->n)
                flag = 1;
            if((i > 0 && M->data[i - 1].i) || (m == M->data[i - 1].i && n <= M->data[i - 1].j))
                flag = 1;
        }while(flag);
        M->data[i].i = m;
        M->data[i].j = n;
        M->data[i].e = e;
    }
    return 1;
}

void PrintMatrix(TriSeqMatrix M){
    int i;
    printf("稀疏矩阵是%d行 x %d列，共%d个非零元素。\n",M.m,M.n,M.len);
    printf("行      列      元素值\n");
    for(i = 0;i < M.len;i++)
        printf("%2d%6d%8d\n",M.data[i].i,M.data[i].j,M.data[i].e);
}

int main(){
    TriSeqMatrix M,N,Q;
    CreateMatrix(&M);
    PrintMatrix(M);
    CreateMatrix(&N);
    PrintMatrix(N);
    MultMatrix(M,N,&Q);
    PrintMatrix(Q);
    return 0;
}
