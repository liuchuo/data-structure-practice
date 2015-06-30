//
//  main.c
//  20150630-1
//
//  Created by 欣 陈 on 15/6/30.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//将元素e入队的算法实现如下
int EnQueue(LinkQueue *LQ,DataType e){
    LQNode *S;
    s = (LQNode*)malloc(sizeof(LQNode));
    if(!s)
        exit(-1);
    s->data = e;
    s->next = NULL;
    LQ->rear->next = s;
    LQ->rear = s;
    return 1;
}
