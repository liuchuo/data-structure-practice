//
//  main.c
//  20150529-5
//
//  Created by 欣 陈 on 15/5/29.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//函数指针数组：存放指针的数组，这些指针是指向函数的
#include <stdio.h>
void f1(int n);
void f2(int n);
void f3(int n);
int main(){
    void (*f[3])() = {f1,f2,f3};
    int flag;
    printf("请输入1，2，3，结束程序请输入0.\n");
    scanf("%d",&flag);
    while(flag){
        if(flag == 1 || flag == 2 || flag == 3){
            f[flag - 1](flag);
        printf("请输入1，2，3，结束程序请输入0.\n");
        scanf("%d",&flag);
        }
        else{
            printf("请输入合法的数：");
            scanf("%d",&flag);
        }
    }
    printf("结束程序！\n");
    return 0;
}

void f1(int n){
    printf("咩哈哈行你好我是函数%d~~~\n",n);
}

void f2(int n){
    printf("啦啦啦你好我是函数%d~~~~~\n",n);
}

void f3(int n){
    printf("= = = hello我是函数%d~~~\n",n);
}

