//
//  main.c
//  test
//
//  Created by 欣 陈 on 15/5/28.
//  Copyright (c) 2015年 欣 陈. All rights reserved.

//指针数组：是一个数组，只是数组中的每一个元素都是指针类型的数据
//指针数组常用来存储一些长度不等的字符串数据
//用指针数组保存字符串并将字符串打印输出
//数组保存的是各个字符串的首地址。
#include <stdio.h>
int main(){
    char *s[4] = {"C Programming Language","Asembly Language",
        "Data structure","Natural Language"};
    printf("%s",s[0]);
    return 0;
}
