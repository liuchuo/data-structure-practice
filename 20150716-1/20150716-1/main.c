//
//  main.c
//  20150716-1
//
//  Created by 欣 陈 on 15/7/16.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
//串的堆分配表示与实现
typedef struct{
    char *str;
    int length;
}HeapString;

//初始化堆串
void InitString(HeapString *S){
    S->length = 0;
    S->str = '\0';
}

//将字符串cstr中的字符赋给串S
void AssignString(HeapString *S,char cstr[]){
    int i = 0,len = 0;
    if(S->str)
        free(S->str);
    for(i = 0;cstr[i] != '\0';i++){
        len = i;
    }
    if(!i){
        S->length = 0;
        S->str = '\0';
    }
    else{
        S->str = (char *)malloc(len * sizeof(char));
        if(!S->str)
            exit(-1);
        for(i = 0;i < len;i++){
            S->str[i] = cstr[i];
        }
        S->length = len;
    }
}

//复制串
void StrCopy(HeapString *T,HeapString S){
    int i;
    T->str = (char *)malloc(S.length * sizeof(char));
    if(!T->str)
        exit(-1);
    for(i = 0;i < S.length;i++){
        T->str[i] = S.str[i];
    }
    T->length = S.length;
}

//在S中第pos个位置插入T
int StrInsert(HeapString *S,int pos,HeapString T){
    int i;
    if(pos < 0 || pos - 1 > S->length){
        printf("position is incorrect\n");
        return 0;
    }
    S->str = (char *)realloc(S->str,(S->length + T.length) * sizeof(char));
    if(!S->str){
        printf("Memory allocation failure");
        return 0;
    }
    for(i = S->length - 1;i >= pos - 1;i--){
        S->str[i + T.length] = S->str[i];
    }
    for(i = 0;i < T.length;i++){
        S->str[pos - 1 + i] = T.str[i];
    }
    S->length = T.length + S->length;
    return 1;
}

//删除S中pos开始的len个字符
int StrDelete(HeapString *S,int pos,int len){
    int i;
    char *p;
    if(pos < 0 || len < 0 || pos + len - 1 > S->length){
        printf("position is incorrect");
        return 0;
    }
    p = (char *)malloc(S->length - len);
    if(!p)
        exit(-1);
    for(i = 0;i < pos - 1;i++){
        p[i] = S->str[i];
    }
    for(i = pos - 1;i < S->length - len;i++){
        p[i] = S->str[i + len];
    }
    S->length = S->length - len;
    free(S->str);
    S->str = p;
    return 1;
}

//将串S连接在串T的末尾
int StrConcat(HeapString *T,HeapString S){
    int i;
    T->str = (char *)realloc(T->str,(T->length + S.length) * sizeof(char));
    if(!T->str){
        printf("Memory allocation failure");
        exit(-1);
    }
    for(i = T->length;i < T->length + S.length;i++){
        T->str[i] = S.str[i - T->length];
        T->length = T->length + S.length;
    }
    return 1;
}

//销毁串
void StrDestory(HeapString *S){
    if(S->str){
        free(S->str);
    }
    S->str = '\0';
    S->length = 0;
}
