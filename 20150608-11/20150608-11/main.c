//
//  main.c
//  20150608-11
//
//  Created by 欣 陈 on 15/6/8.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//用栈检验括号匹配问题,设计一个算法判断表达式的括号是否匹配
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
typedef char DataType;
typedef struct node{
    DataType data;
    struct node *next;
}LStackNode,*LinkStack;

void InitStack(LinkStack *top){
    if((*top = (LinkStack)malloc(sizeof(LStackNode))) == NULL)
        exit(-1);
    (*top)->next = NULL;
}

int PushStack(LinkStack top,DataType e){
    LStackNode *p;
    if((p = (LStackNode *)malloc(sizeof(LStackNode))) == NULL){
        printf("内存分配失败~、\n");
        exit(-1);
    }
    p->data = e;
    p->next = top->next;
    top->next = p;
    return 1;
}

int StackEmpty(LinkStack top){
    if(top->next == NULL)
        return 1;
    else
        return 0;
}

int GetTop(LinkStack top,DataType *e){
    LStackNode *p;
    p = top->next;
    if(!p){
        printf("栈已空");
        return 0;
    }
    *e = p->data;
    return 1;
}

int PopStack(LinkStack top,DataType *e){
    LStackNode *p;
    p = top->next;
    if(!p){
        printf("栈已空");
        return 0;
    }
    top->next = p->next;
    *e = p->data;
    free(p);
    return 1;
}


int Match(DataType e,DataType ch);
int main(){
    LinkStack S;
    char *p;
    DataType e;
    DataType ch[60];
    InitStack(&S);
    printf("请输入算术表达式 可以包含括号：\n");
    gets(ch);
    p = ch;
    while(*p){
        switch(*p){
            case'(':
            case'[':
            case'{':
                PushStack(S,*p++);
                break;
            case')':
            case']':
            case'}':
                if(StackEmpty(S)){
                    printf("缺少左括号。");
                    return 0;
                }
                else{
                    GetTop(S,&e);
                    if(Match(e,*p))
                        PopStack(S,&e);
                    else{
                        printf("左右括号不匹配");
                        return 0;
                    }
                }
            default:
                p++;
        }
    }
    if(StackEmpty(S))
        printf("括号匹配");
    else
        printf("缺少右括号");
    return 0;
}

int Match(DataType e,DataType ch){
    if(e == '(' && ch == ')')
        return 1;
    else
        if(e == '[' && ch == ']')
            return 1;
        else
            if(e == '{' && ch == '}')
                return 1;
            else
                return 0;
}
