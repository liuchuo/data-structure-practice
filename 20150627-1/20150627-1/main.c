//
//  main.c
//  20150627-1
//
//  Created by 欣 陈 on 15/6/27.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//舞伴配对的问题
#include <stdio.h>
#define QueueSize 60
typedef struct{
    char name[20];
    char sex;
}Person;

typedef Person DataType;

typedef struct Squeue{
    DataType queue[QueueSize];
    int front;
    int rear;
}SeqQueue;

void InitQueue(SeqQueue *SCQ){
    SCQ->front = SCQ->rear = 0;
}

int QueueEmpty(SeqQueue SCQ){
    if(SCQ.front == SCQ.rear)
        return 1;
    else
        return 0;
}

int EnQueue(SeqQueue *SCQ,DataType e){
    if(SCQ->front == (SCQ->rear + 1) % QueueSize)
        return 0;
    SCQ->queue[SCQ->rear] = e;
    SCQ->rear = (SCQ->rear + 1) % QueueSize;
    return 1;
}

int DeQueue(SeqQueue *SCQ,DataType *e){
    if(SCQ->front == SCQ->rear)
        return 0;
    else{
        *e = SCQ->queue[SCQ->front];
        SCQ->front = (SCQ->front + 1) % QueueSize;
        return 1;
    }
}

int GetHead(SeqQueue SCQ,DataType *e){
    if(SCQ.front == SCQ.rear)
        return 0;
    else{
        *e = SCQ.queue[SCQ.front];
        return 1;
    }
}

void DancePartner(DataType dancer[],int num){
    int i;
    DataType p;
    SeqQueue Mdancers,Fdancers;
    InitQueue(&Mdancers);
    InitQueue(&Fdancers);
    for(i = 0;i < num;i++){
        p = dancer[i];
        if(p.sex == 'F'){
            EnQueue(&Fdancers,p);
        }
        else{
            EnQueue(&Mdancers,p);
        }
    }
    printf("配对成功的舞伴分别是：");
    while(!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers)){
        DeQueue(&Fdancers,&p);
        printf("%s\t",p.name);
        DeQueue(&Mdancers,&p);
        printf("%s\n",p.name);
    }
    if(!QueueEmpty(Fdancers)){
        printf("还有%d名女士等待下一轮舞曲.\n",DancerCount(Fdancers));
        GetHead(Fdancers,&p);
        printf("%s将在下一轮中最先得到舞伴.",p.name);
    }
    else if(!QueueEmpty(Mdancers)){
        printf("还有%d名先生等待下一轮舞曲.\n",DancerCount(Mdancers));
        GetHead(Mdancers,&p);
        printf("%s将在下一轮中最先得到舞伴.",p.name);
    }
}

int DancerCount(SeqQueue Q){
    return(Q.rear-Q.front+QueueSize) % QueueSize;
}

int main(){
    int i,n;
    DataType dancer[30];
    printf("请输入舞池中排队的人数：");
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        printf("姓名：");
        scanf("%s",dancer[i].name);
        getchar();
        printf("性别：");
        scanf("%s",&dancer[i].sex);
    }
    return 0;
}