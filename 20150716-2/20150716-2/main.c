//
//  main.c
//  20150716-2
//
//  Created by 欣 陈 on 15/7/16.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//串的块链式存储表示与实现
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ChunkSize 10
#define stuff '#'

typedef struct Chunk{
    char ch[ChunkSize];
    struct Chunk *next;
}Chunk;

typedef struct{
    Chunk *head;
    Chunk *tail;
    int length;
}LinkString;

//初始化块链串
void InitString(LinkString *S){
    S->length = 0;
    S->head = S->tail = NULL;
}

//串的赋值
int StringAssign(LinkString *S,char *cstr){
    int i,j,k;
    int len;
    Chunk *p,*q = NULL;
    len = strlen(cstr);
    if(!len)
        return 0;
    S->length = len;
    j = len / ChunkSize;
    if(len % ChunkSize)
        j++;
    for(i = 0;i < j;i++){
        p = (Chunk *)malloc(sizeof(Chunk));
        if(!p)
            return 0;
        for(k = 0;k < ChunkSize && *cstr;k++)
            *(p->ch + k) = *cstr++;
        if(i == 0)
            S->head = p = q;
        else{
            q->next = p;
            q = p;
        }
        if(!*cstr){
            S->tail = q;
            q->next = NULL;
            for(;k < ChunkSize;k++)
                *(q->ch + k) = stuff;
        }
    }
    return 1;
}
