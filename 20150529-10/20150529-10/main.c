//
//  main.c
//  20150529-10
//
//  Created by 欣 陈 on 15/5/29.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//内存的动态分配与释放
#include <stdlib.h>
#include <stdio.h>
int main(){
    int *p;
    p = (int *)malloc(sizeof(int) * 20);
    *(p + 2) = 10;
    *(p + 3) = 20;
    printf("%d\n%d\n",*(p + 3),*(p + 2));
    free(p);
    return 0;
}