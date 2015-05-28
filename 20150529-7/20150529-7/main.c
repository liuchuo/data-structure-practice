//
//  main.c
//  20150529-7
//
//  Created by 欣 陈 on 15/5/28.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//指向数组元素的指针
//用指针引用数组元素并打印输出
#include <stdio.h>
int main(){
    int a[5] = {10,20,30,40,50};
    int *aptr;
    int i;
    aptr = &a[0];
    for(i = 0;i < 5;i++)
        printf("a[%d] = %d\n",i,a[i]);
    for(i = 0;i < 5;i++)
        printf("*(a + %d) = %d\n",i,*(a+i));
    for(i = 0;i < 5;i++)
        printf("aptr[%d] = %d\n",i,aptr[i]);
    for(i = 0;i < 5;i++)
        printf("*(aptr + %d) = %d\n",i,*(aptr+i));
    return 0;
}
