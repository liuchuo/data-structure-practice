//
//  main.c
//  20150529-3
//
//  Created by 欣 陈 on 15/5/29.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//函数指针：指向函数的指针
//通过一个函数求两个数的乘积，并通过函数指针调用该函数
#include <stdio.h>
int Mult(int a,int b);
int main(){
    int a,b;
    int (*func)(int,int);
    printf("请输入两个数a,b:");
    scanf("%d,%d",&a,&b);
    printf("第一种调用方法：调用函数名：\n");
    printf("%d * %d = %d\n",a,b,Mult(a,b));
    func = Mult;
    printf("第二种调用方法，函数指针调用：\n");
    printf("%d * %d = %d\n",a,b,(*func)(a,b));
    return 0;
}

int Mult(int a,int b){
    return a*b;
}
