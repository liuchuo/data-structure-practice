//
//  main.c
//  20150529-9
//
//  Created by 欣 陈 on 15/5/29.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//建立一个教师和学生基本情况登记表，其中教师基本情况由编号、姓名、性别、年龄、职业和职称构成
//学生基本情况由编号、姓名、性别、年龄、职业和班级构成
#include <stdio.h>
typedef struct{
    int num;
    char name[20];
    char sex[4];
    int age;
    int job;
    union{
        int class;
        char prof[20];
    }category;
}STAFFER;
int main(){
    STAFFER staf[20];
    int i;
    for(i = 0;i < 3;i++){
        printf("编号：\n");
        scanf("%d",&staf[i].num);
        printf("姓名：\n");
        scanf("%s",staf[i].name);
        printf("性别：\n");
        scanf("%s",staf[i].sex);
        printf("年龄：\n");
        scanf("%d",&staf[i].age);
        printf("职业（0表示学生，1表示教师）:\n");
        scanf("%d",&staf[i].job);
        if(staf[i].job == 0){
            printf("班级：\n");
            scanf("%d",&staf[i].category.class);
        }
        else if(staf[i].job == 1){
            printf("职称：\n");
            scanf("%s",staf[i].category.prof);
        }
    }
    printf("编号      姓名      性别      年龄   职业    职称/班级\n");
    for(i = 0;i < 3;i++){
        if(staf[i].job == 0){
            printf("%7d%8s%6s%7d%7s%7d\n",staf[i].num,staf[i].name,
                   staf[i].sex,staf[i].age,"学生",staf[i].category.class);
        }
        else if(staf[i].job == 1){
            printf("%7d%8s%6s%7d%7s%7s\n",staf[i].num,staf[i].name,
                   staf[i].sex,staf[i].age,"老师",staf[i].category.prof);
        }
    }
    return 0;
}
