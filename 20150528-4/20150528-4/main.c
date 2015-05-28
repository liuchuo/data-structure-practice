//
//  main.c
//  20150528-4
//
//  Created by 欣 陈 on 15/5/28.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//利用递归求n个数中的最大者
#include <stdio.h>
#define N 200
int findmax(int a[],int n);
int main(){
    int a[N],n,i;
    printf("请输入n的值:");
    scanf("%d",&n);
    printf("请依次输入%d个数：\n",n);
    for(i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    printf("在这%d个数中，最大的元素是%d",n,findmax(a,n));
    return 0;
}

int findmax(int a[],int n){
    int m;
    if(n <= 1)
        return a[0];
    else{
        m = findmax(a,n-1);
        return a[n-1] >= m ? a[n-1] : m;
    }
}
