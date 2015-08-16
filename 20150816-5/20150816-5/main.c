//
//  main.c
//  20150816-5
//
//  Created by 欣 陈 on 15/8/16.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//利用十字链表实现两个稀疏矩阵的相加
//矩阵A + B = C，1.A、B均非零 则结果若为0，不存储；结果为0，存储进C
//2.A不为0，B为0，把A对应的那个三元组的值存储进C
//3.B不为0，A为0，把B对应的那个三元组的值存储进C
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

int AddMatrix(TriSeqMatrix A,TriSeqMatrix B,TriSeqMatrix *C);
void PrintMatrix(TriSeqMatrix M);
int CreateMatrix(TriSeqMatrix *M);
int CompareElement(int a,int b);

int CreateMatrix(TriSeqMatrix *M){
    int i,m,n;
    DataType e;
    int flag;
    printf("请输入稀疏矩阵的行数、列数以及非零元素的个数：");
    scanf("%d,%d,%d",&M->m,&M->n,&M->len);
    if(M->len > MaxSize)
        return 0;
    for(i = 0;i < M->len;i++){
        do{
            printf("请按行序顺序输入第%d个非零元素所在的行(0~%d),列(0~%d),元素值：",i+1,M->m-1,M->n-1);
            scanf("%d,%d,%d",&m,&n,&e);
            flag = 0;
            if(m < 0 || m > M->m || n < 0 || n > M->n)
                flag = 1;
            if((i > 0 && m < M->data[i - 1].i) || (m == M->data[i - 1].i && n <= M->data[i - 1].j))
                flag = 1;
        }while(flag);
        M->data[i].i = m;
        M->data[i].j = n;
        M->data[i].e = e;
    }
    return 1;
}

int CompareElement(int a,int b){
    if(a < b)
        return -1;
    if(a > b)
        return 1;
    return 0;
}

void PrintMatrix(TriSeqMatrix M){
    int i;
    printf("稀疏矩阵是%d行 x %d列，共%d个元素。\n",M.m,M.n,M.len);
    printf("行      列       元素值\n");
    for(i = 0;i < M.len;i++)
        printf("%2d%6d%8d\n",M.data[i].i,M.data[i].j,M.data[i].e);
}

int AddMatrix(TriSeqMatrix A,TriSeqMatrix B,TriSeqMatrix *C){
    int m = 0;
    int n = 0;
    int k = -1;
    if(A.m != B.m || A.n != B.n)
        return 0;
    C->m = A.m;
    C->n = A.n;
    while(m < A.len && n < B.len) {
        switch(CompareElement(A.data[m].i,B.data[n].i)){
            case -1:
                C->data[++k] = A.data[m++];
                break;
            case 0:
                switch(CompareElement(A.data[m].j,B.data[n].j)){
                    case -1:
                        C->data[++k] = A.data[m++];
                        break;
                    case 0:
                        C->data[++k] = A.data[m++];
                        C->data[k].e = A.data[n++].e;
                        if(C->data[k].e == 0)
                            k--;
                        break;
                    case 1:
                        C->data[++k] = B.data[n++];
                }
                break;
            case 1:
                C->data[++k] = B.data[n++];
        }
    }
    while(m < A.len)
        C->data[++k] = A.data[m++];
    while(n < B.len)
        C->data[++k] = B.data[n++];
    C->len = k + 1;
    if(k > MaxSize)
        return 0;
    return 1;
}

int main(){
    TriSeqMatrix M,N,Q;
    CreateMatrix(&M);
    PrintMatrix(M);
    CreateMatrix(&N);
    PrintMatrix(N);
    AddMatrix(M,N,&Q);
    PrintMatrix(Q);
    return 0;
}
