//
//  main.c
//  20150528-3
//
//  Created by 欣 陈 on 15/5/28.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//调用递归求n!的算法
#include <stdio.h>
long factorial(int n);
int main(){
    int num;
    for(num = 0;num < 10;num++){
        printf("%d!=%ld\n",num,factorial(num));
    }
    return 0;
}

long factorial(int n){
    if(n == 0)
        return 1;
    else
        return n*factorial(n - 1);
}
