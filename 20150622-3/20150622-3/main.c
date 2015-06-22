//
//  main.c
//  20150622-3
//
//  Created by 欣 陈 on 15/6/22.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//消除递归-利用栈实现的非递归方法
#include <stdio.h>
#define MaxSize 100
int fact(int n);
int main(){
    int f,n;
    printf("请输入一个正整数(n<15): ");
    scanf("%d",&n);
    f = fact(n);
    printf("利用栈非递归实现n的阶乘: ");
    printf("n!=%d\n",f);
}

int fact(int n){
    int s[MaxSize][2],top = -1;
    top++;
    s[top][0] = n;
    s[top][1] = 0;
    do{
        if(s[top][0] == 1){
            s[top][1] = 1;
            printf("n = %d\t,fact = %d\n",s[top][0],s[top][1]);
        }
        if(s[top][0] > 1 && s[top][1] == 0){
            top++;
            s[top][0] = s[top-1][0] - 1;
            s[top][1] = 0;
            printf("n = %d\t,fact = %d\n",s[top][0],s[top][1]);
        }
        if(s[top][1] != 0){
            s[top-1][1] = s[top][1] * s[top-1][0];
            printf("n = %d\t,fact = %d\n",s[top-1][0],s[top-1][1]);
            top--;
        }
    }while(top > 0);
    return s[0][1];
}
