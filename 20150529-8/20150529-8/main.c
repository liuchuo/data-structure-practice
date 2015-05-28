//
//  main.c
//  20150529-8
//
//  Created by 欣 陈 on 15/5/28.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//指针数组：是一个数组，只是数组中的每一个元素都是指针类型的数据
//指针数组常用来存储一些长度不等的字符串数据
//用指针数组保存字符串并将字符串打印输出
//数组保存的是各个字符串的首地址。
#include <stdio.h>
int main(){
    char *s[4] = {"C Programming Language","Asembly Language",
        "Data structure","Natural Language"};
    int i;
    char *aptr;
    printf("第一种方法输出：通过指针数组的数组名输出字符串:\n");
    for(i = 0;i < 4;i++)
        printf("第%d个字符串：%s\n",i+1,s[i]);
    printf("第二种方法输出：通过指向数组的指针输出字符串：\n");
    for(aptr = s[0],i = 0;i < 4;aptr = s[i]){
        printf("第%d个字符串：%s\n",i+1,aptr);
        i++;
    }
}
