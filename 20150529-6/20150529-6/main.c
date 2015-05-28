//
//  main.c
//  20150529-6
//
//  Created by 欣 陈 on 15/5/28.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//利用变量和指针变量存取数据。
#include <stdio.h>
int main(){
    int q = 12;
    int *qptr;
    qptr = &q;
    printf("q的地址是：%p\n qptr的内容是%p\n",&q,qptr);
    printf("q的值是：%d\n *qptr值是：%d\n",q,*qptr);
    printf("&*qptr = %p,*&qptr = %p\n",&*qptr,*&qptr);
    return 0;
}
