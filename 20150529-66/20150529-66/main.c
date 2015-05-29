//
//  main.c
//  20150529-66
//
//  Created by 欣 陈 on 15/5/29.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//求两个数的最大公约数
#include <stdio.h>
int GCD(int m,int n);
int main(){
    int a,b,v;
    printf("请输入两个数~a,b：");
    scanf("%d,%d",&a,&b);
    v = GCD(a,b);
    printf("最大公约数为%d",v);
    return 0;
}

int GCD(int m,int n){
    int r;
    r = m;
    do{
        m = n;
        n = r;
        r = m % n;
    }while(r);
    return n;
}
