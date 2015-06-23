//
//  main.c
//  20150623-1
//
//  Created by 欣 陈 on 15/6/22.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//顺序循环队列的基本运算
//顺序循环队列类型描述
#include <stdio.h>
#define QueueSize 60
typedef int DataType;
typedef struct Squeue{
    DataType queue[QueueSize];
    int front,rear;
}SeqQueue;

//初始化队列
void InitQueue(SeqQueue *SCQ){
    SCQ->front = SCQ->rear = 0;
}

//判断队列是否为空
int QueueEmpty(SeqQueue SCQ){
    if(SCQ.front == SCQ.rear)
        return 1;
    else
        return 0;
}

//将队列e入队
int EnQueue(SeqQueue *SCQ,DataType e){
    if(SCQ->front == (SCQ->rear + 1) % QueueSize)
        return 0;
    SCQ->queue[SCQ->rear] = e;
    SCQ->rear = (SCQ->rear + 1) % QueueSize;
    return 1;
}

//将队头出队
int DeQueue(SeqQueue *SCQ,DataType *e){
    if(SCQ->front == SCQ->rear)
        return 0;
    else{
        *e = SCQ->queue[SCQ->front];
        SCQ->front = (SCQ->front + 1) % QueueSize;
        return 1;
    }
}

//取队头元素
int GetHead(SeqQueue SCQ,DataType *e){
    if(SCQ.front == SCQ.rear)
        return 0;
    else{
        *e = SCQ.queue[SCQ.front];
        return 1;
    }
}

//清空队列
void ClearQueue(SeqQueue *SCQ){
    SCQ->front = SCQ->rear = 0;
}
