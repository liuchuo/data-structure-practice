//
//  main.c
//  20150529-4
//
//  Created by 欣 陈 on 15/5/29.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//利用函数指针作为函数参数，实现选择排序算法的升序排列和降序排列
#include <stdio.h>
#define N 10
void ascending(int a,int b);
void descending(int a,int b);
void swap(int *,int *);
int selectsort(int a[],int n,int (*compare)(int,int));
void display(int a[],int n);
int main(){
    int a[N] = {22,55,12,7,19,65,81,3,30,52};
    int flag;
    while(1){
        printf("1.升序排列 2.降序排列 0.结束！");
        printf("请输入：");
        scanf("%d",&flag);
        switch(flag){
            case 1:
                printf("排序的数据为：");
                display(a,N);
                selectsort(a,N,ascending);
                printf("按照升序排列后的数据为：");
                display(a,N);
                break;
            case 2:
                printf("排序的数据为：");
                display(a,N);
                selectsort1(a,N,descending);
                printf("按照降序排列后的数据为：");
                display(a,N);
                break;
            case 0:
                printf("结束！");
                return 0;
                break;
            default:
                printf("输入数据有误，请重新输入！");
                break;
        }
    }
    return 0;
}

void selectsort(int a[],int n,int(*compare)(int,int)){
    int i,j,k;
    for(i = 0;i < n;i++){
        j = i;
        for(k = i+1;k < n;k++){
            if((*compare)(a[k],a[j]))
                j = k;
        }
        swap(&a[i],&a[j]);
    }
}

void swap(int *a,int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int ascending(int a,int b){
    if(a < b)
        return 1;
    else
        return 0;
}

int descending(int a,int b){
    if(a > b)
        return 1;
    else
        return 0;
}

void display(int a[],int n){
    int i;
    for(i = 0;i < n;i++){
        printf("%4d",a[i]);
    }
    printf("\n");
}
