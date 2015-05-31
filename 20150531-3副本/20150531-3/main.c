//
//  main.c
//  20150531-3
//
//  Created by 欣 陈 on 15/5/31.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//设计一种表示任意长的整数的数据结构，计算任意给定的两个整数之和的算法
#include <stdio.h>
#define MaxLen 100
typedef int sqlist[MaxLen];

int input(sqlist A){
    int i;
    for(i = 0;i < MaxLen;i++){
        A[i] = 0;
    }
    printf("输入整数的各位（以-1结束）：\n");
    i = 0;
    while(1){
        scanf("%d",&A[i]);
        if(A[i] < 0)
            break;
        i++;
    }
    return i;
}

void output(sqlist A,int low,int high){
    int i;
    for(i = low;i < high;i++)
        printf("%d",A[i]);
    printf("\n");
}

void move1(sqlist A,int na){
    int i;
    for(i = 0;i < na;i++)
        A[MaxLen - i -1] = A[na - i -1];
}

int add(sqlist *A,int na,sqlist B,int nb){
    int nc,i,j;
    int length = 0;
    if(na > nb)
        nc = na;
    else
        nc = nb;
    move1(*A,na);
    move1(B,nb);
    for(i = MaxLen - 1;i >= MaxLen - nc;i--){
        j = (*A)[i] + B[i];
        if(j > 9){
            (*A)[i - 1] = (*A)[i - 1] + 1;
            (*A)[i] =j - 10;
        }
        else{
            (*A)[i] = j;
        }
        if(i == MaxLen - nc){
            if(j > 9){
                (*A)[i - 1] = 1;
                length = nc + 1;
            }
            else{
                length = nc;
            }
        }
    }
    return length;
}

int main(){
    sqlist A,B;
    int na,nb,nc;
    na = input(A);
    nb = input(B);
    printf("整数A:\n");
    output(A,0,na);
    printf("整数B:\n");
    output(B,0,nb);
    nc = add(&A,na,B,nb);
    printf("相加后的结果：\n");
    output(A,MaxLen - nc,MaxLen);
    return 0;
}
