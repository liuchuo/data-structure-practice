//
//  main.c
//  20150701-1
//
//  Created by 欣 陈 on 15/7/2.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//链式队列举例
//编写一个算法，判断任意给定的字符序列是否为回文。所谓回文是指以中间字符为基准两边字符完全相同
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char DataType;
typedef struct snode{
    DataType data;
    struct snode *next;
}LSNode;

typedef struct QNode{
    DataType data;
    struct QNode *next;
}LQNode,*LinkQueue;

void InitStack(LSNode **head){
    if((*head = (LSNode*)malloc(sizeof(LSNode))) == NULL){
        printf("分配结点不成功~");
        exit(-1);
    }
    else
        (*head)->next = NULL;
}

int StackEmpty(LSNode *head){
    if(head->next == NULL)
        return 1;
    else
        return 0;
}

int PushStack(LSNode *head,DataType e){
    LSNode *s;
    if((s = (LSNode*)malloc(sizeof(LSNode))) == NULL)
        exit(-1);
    else{
        s->data = e;
        s->next = head->next;
        head->next = s;
        return 1;
    }
}

int PopStack(LSNode *head,DataType *e){
    LSNode *s = head->next;
    if(StackEmpty(head))
        return 0;
    else{
        head->next = s->next;
        *e = s->data;
        free(s);
        return 1;
    }
}

void InitQueue(LinkQueue *rear){
    if((*rear = (LQNode*)malloc(sizeof(LQNode))) == NULL)
        exit(-1);
    else
        (*rear)->next = *rear;
}
