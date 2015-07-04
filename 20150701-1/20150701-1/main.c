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

int QueueEmpty(LinkQueue rear){
    if(rear->next == rear)
        return 1;
    else
        return 0;
}

int EnQueue(LinkQueue *rear,DataType e){
    LQNode *s;
    s = (LQNode *)malloc(sizeof(LQNode));
    if(!s){
        exit(-1);
    }
    s->data = e;
    s->next = (*rear)->next;
    (*rear)->next = s;
    *rear = s;
    return 1;
}

int DeQueue(LinkQueue *rear,DataType *e){
    LQNode *f,*p;
    if(*rear == (*rear)->next)
        return 0;
    else{
        f = (*rear)->next;
        p = f->next;
        if(p == *rear){
            *rear = (*rear)->next;
            (*rear)->next = *rear;
        }
        else{
            f->next = p->next;
        }
        *e = p->data;
        free(p);
        return 1;
    }
}

int main(){
    LinkQueue LQueue1,LQueue2;
    LSNode *LStack1,*LStack2;
    char str1[] = "ABCDEDCBA";
    char str2[] = "XYWBWXY";
    char q1,s1,q2,s2;
    int i;
    InitQueue(&LQueue1);
    InitQueue(&LQueue2);
    InitStack(&LStack1);
    InitStack(&LStack2);
    for(i = 0;i < strlen(str1);i++){
        EnQueue(&LQueue1,str1[i]);
        PushStack(LStack1,str1[i]);
    }
    for(i = 0;i < strlen(str2);i++){
        EnQueue(&LQueue2,str2[i]);
        PushStack(LStack2,str2[i]);
    }
    printf("字符序列1：%s\n",str1);
    printf("出队序列    出栈序列\n");
    int flag = 1;
    while(!StackEmpty(LStack1)){
        DeQueue(&LQueue1,&q1);
        PopStack(LStack1,&s1);
        printf("%5c",q1);
        printf("%10c\n",s1);
        if(q1 != s1){
            printf("字符序列1不是回文！");
            //return 0;
            flag = 0;
            break;
        }
    }
    //printf("字符序号1是回文。\n");
    if(flag) {
      printf("字符序号1是回文。\n");
    }
    
    
    printf("字符序列2：%s\n",str2);
    printf("出队序列    出栈序列\n");
    while(!StackEmpty(LStack2)){
        DeQueue(&LQueue2,&q2);
        PopStack(LStack2,&s2);
        printf("%5c",q2);
        printf("%10c\n",s2);
        if(q2 != s2){
            printf("字符序列2不是回文！");
            return 0;
        }
    }
    printf("字符序号2是回文。\n");
    return 0;
}


