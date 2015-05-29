//
//  main.c
//  20150529-88
//
//  Created by 欣 陈 on 15/5/29.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//利用指向结构体的指针输出学生的基本信息
#include <stdio.h>
struct student{
    char *no;
    char *name;
    char sex;
    int age;
    float score;
}stu[3] = {{"13001","zhu tong",'m',22,90.0},
    {"13002","li hua",'f',21,82.0},
    {"13003","yang yang",'m',22,95.0}};
int main(){
    struct student *p;
    printf("学生基本情况表：\n");
    printf("学号      姓名          性别    年龄    成绩\n");
    for(p = stu;p < stu + 3;p++)
        printf("%-8s%8s%8c%8d%8.1f\n",p->no,p->name,p->sex,p->age,p->score);
}
