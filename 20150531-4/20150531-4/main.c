//
//  main.c
//  20150531-4
//
//  Created by 欣 陈 on 15/5/31.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//设计一个在时间和空间两方面都尽可能高校的算法，将R中保存的序列循环左移p个位置
//即把（x0,x1,x2,...,xn-1）变换为（xp,xp+1,...,x0,x1,...,xp）
#include <stdio.h>
void Reverse(int R[],int left,int right){
    int i,j;
    int t;
    i = left;
    j = right;
    while(i < j){
        t = R[i];
        R[i] = R[j];
        R[j] = t;
        i++;
        j--;
    }
}

void LeftShift(int R[],int n,int p){
    if(p > 0 && p < n){
        Reverse(R,0,n-1);
        Reverse(R,0,n - 1 - p);
        Reverse(R,n - p,n - 1);
    }
}

int main(){
    int R[] = {0,1,2,3,4,5,6,7,8,9};
    int k;
    for(k = 0;k < 10;k++){
        printf("%d  ",R[k]);
    }
    printf("\n");
    LeftShift(R,10,2);
    for(k = 0;k < 10;k++){
        printf("%d  ",R[k]);
    }
    printf("\n");
    return 0;
}