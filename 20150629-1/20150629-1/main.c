//
//  main.c
//  20150629-1
//
//  Created by 欣 陈 on 15/6/29.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//链式队列存储结构
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct QNode{
    DataType data;
    struct QNode* next;
}LQNode,*QueuePtr;

typedef struct{
    QueuePtr front;
    QueuePtr rear;
}LinkQueue;

// 初始化链式队列
void InitQueue(LinkQueue *LQ){
    LQ->front = LQ->rear = (LQNode*)malloc(sizeof(LQNode));
    if(LQ->front == NULL)
        exit(-1);
    LQ->front->next = NULL;
}

//判断队列是否为空
int QueueEmpty(LinkQueue LQ){
    if(LQ.rear->next == NULL)
        return 1;
    else
        return 0;
}
