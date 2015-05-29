//
//  main.c
//  20150529-77
//
//  Created by 欣 陈 on 15/5/29.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//编写函数，要求将数组中的n个元素的值分别减去20
#include <stdio.h>
#define N 10
void subarray1(int b[],int n);
void subarray2(int *p,int n);
int main(){
    int a[N] = {51,52,53,54,55,56,57,58,59,60};
    int i;
    printf("原来的顺序为：\n");
    for(i = 0;i < N;i++)
        printf("%4d",a[i]);
    printf("\n");
    subarray1(a,N);
    printf("-20后为:\n");
    for(i = 0;i < N;i++)
        printf("%4d",a[i]);
    printf("\n");
    printf("再-20后为：\n");
    subarray2(a,N);
    for(i = 0;i < N;i++)
        printf("%4d",a[i]);
    printf("\n");
    return 0;
}

void subarray1(int b[],int n){
    int i;
    for(i = 0;i < N;i++)
        b[i] = b[i] - 20;
}

void subarray2(int *p,int n){
    int i;
    for(i = 0;i < N;i++)
        *(p + i) = *(p + i) - 20;
}
