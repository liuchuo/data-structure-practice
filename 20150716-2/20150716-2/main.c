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
int StrAssign(LinkString *S,char *cstr){
    int i,j,k;
    int len;
    Chunk *p,*q = NULL;
    len = (int)strlen(cstr);
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

//将串S中的字符复制到字符串cstr中
int ToChars(LinkString S,char **cstr){
    Chunk *p = S.head;
    int i;
    char *q;
    *cstr = (char *)malloc((S.length + 1) * sizeof(char));
    if(!cstr || !S.length)
        return 0;
    q = *cstr;
    while(p){
        for(i = 0;i < ChunkSize ;i++)
            if(p->ch[i] != stuff)
                *q++ = (p->ch[i]);
        p = p->next;
    }
    (*cstr)[S.length] = '\0';
    return 1;
}

//比较两个串的大小
int StrCompare(LinkString S,LinkString T){
    char *p,*q;
    int flag = 0;
    if(ToChars(S,&p))
        return 0;
    if(ToChars(T,&q))
        return 0;
    while(*p != '\0' && *q != '\0'){
        if(*p == *q){
            p++;
            q++;
        }
        else
            flag = *p - *q;
    }
    free(p);
    free(q);
    if(*p == '\0' || *q == '\0')
        return S.length - T.length;
    else
        return flag;
}

//将串T插入串S的第pos个位置
int StrInsert(LinkString *S,int pos,LinkString T){
    char *t1;
    char *s1;
    int i,j;
    int flag;
    if(pos < 1 || pos > S->length + 1)
        return 0;
    if(!ToChars(*S,&s1))
        return 0;
    if(!ToChars(T,&t1))
        return 0;
    j = (int)strlen(s1);
    s1 = (char *)realloc(s1,(j + 1 + strlen(t1)) * sizeof(char));
    for(i = j;i >= pos - 1;i--)
        s1[i + strlen(t1)] = s1[i];
    for(i = 0;i < strlen(t1);i++)
        s1[pos - 1 + i] = t1[i];
    InitString(S);
    flag = StrAssign(S,s1);
    free(t1);
    free(s1);
    return flag;
    
}


//将串S中的第pos个字符起的长度为len的子串删除
int StrDelete(LinkString *S,int pos,int len){
    char *str;
    int i;
    int flag = 0;
    if(pos < 1 || pos > S->length + 1 - len || len < 0)
        return 0;
    if(!ToChars(*S,&str))
        return 0;
    for(i = pos - 1 + len;i < (int)strlen(str);i++)
        str[i - len] = str[i];
    InitString(S);
    flag = StrAssign(S,str);
    free(str);
    return flag;
}

//清空串
void ClearString(LinkString *S){
    Chunk *p,*q;
    p = S->head;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    S->head = S->tail = NULL;
    S->length = 0;
}