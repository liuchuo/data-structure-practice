//
//  main.c
//  20150707-1
//
//  Created by 欣 陈 on 15/7/7.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//栈和队列：动画模拟停车场管理系统
#include <stdio.h>
#include <stdlib.h>//the function of malloc
#include <time.h>//get system time
#include <windows.h>//set the information of cursor 'malllco'

#define MaxSize 5
#define PRICE 0.05
#define BASEPRICE 0.5
#define Esc 27//exit system(escape)
#define Exit 3//end a conversation
#define Stop 1//park car
#define Drive 2//pick up car

int jx = 0,jy = 32;

//Node:time
typedef struct{
    int hour;
    int minute;
}Time,*PTime;

//Node:the information of car
typedef struct{
    int num;//license plate
    Time arrtime;
}CarNode;

//define a stack to imitate parking lot
typedef struct{
    CarNode stack[MaxSize];
    int top;
}SqStackCar;

//Node:queue
typedef struct node{
    int num;//license plate
    struct node *next;
}QueueNode;

//define a queue to imitate line up
typedef struct{
    QueueNode *front,*rear;
}LinkQueueCar;

//function declaration
