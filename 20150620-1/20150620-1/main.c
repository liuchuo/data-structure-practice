//
//  main.c
//  20150620-1
//
//  Created by 欣 陈 on 15/6/20.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//迷宫求解问题：要用一个先进后出的栈来保存从入口到当前位置的路径
//定义墙元素值为0，可通过路径为1，不能通过的路径为-1
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int x;
    int y;
}PosType;
typedef struct {
    int ord;
    PosType seat;
    int di;
}DataType;

#define MaxLENGTH 40
#define StackSize 100

typedef struct{
    DataType stack[StackSize];
    int top;
}SeqStack;

void InitStack(SeqStack *S){
    S->top = 0;
}

int StackEmpty(SeqStack S){
    if(S.top == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int GetTop(SeqStack S,DataType *e){
    if(S.top == 0){
        printf("栈已空~\n");
        return 0;
    }
    else{
        *e = S.stack[S.top - 1];
        return 1;
    }
}

int PushStack(SeqStack *S,DataType e){
    if(S->top >= StackSize){
        printf("栈已满，不能将元素入栈~\n");
        return 0;
    }
    else{
        S->stack[S->top] = e;
        S->top++;
        return 1;
    }
}

int PopStack(SeqStack *S,DataType *e){
    if(S->top == 0){
        printf("栈中已经没有元素，不能进行出栈操作~\n");
        return 0;
    }
    else{
        S->top--;
        *e = S->stack[S->top];
        return 1;
    }
}

int StackLength(SeqStack S){
    return S.top;
}

void ClearStack(SeqStack *S){
    S->top = 0;
}

typedef int MazeType[MaxLENGTH][MaxLENGTH];
MazeType m;
int x,y;
PosType begin,end;
int curstep = 1;

void Print(){
    int i,j;
    for(i = 0;i < x;i++){
        for(j = 0;j < y;j++){
            printf("%3d",m[i][j]);
        }
        printf("\n");
    }
}

void Init(int k){
    int i,j,x1,y1;
    printf("请输入迷宫的行数，列数（包括外墙）：");
    scanf("%d,%d",&x,&y);
    for(i = 0;i < y-1;i++){
        m[0][i] = 0;
        m[x - 1][i] = 0;
    }
    for(i = 0;i < y-1;i++){
        m[i][0] = 0;
        m[x - 1][i] = 0;
    }
    for(i = 1;i < x-1;i++){
        for(j = 1;j < y-1;j++){
            m[i][j] = k;
        }
    }
    printf("请输入迷宫内墙单元数：");
    scanf("%d",&j);
    printf("请一次输入迷宫内墙每个单元的行数，列数：\n");
    for(i = 1;i <= j;i++){
        scanf("%d,%d",&x1,&y1);
        m[x1][y1] = 0;
    }
    printf("迷宫结构如下：\n");
    Print();
    printf("请输入入口的行数，列数：");
    scanf("%d,%d",&begin.x,&begin.y);
    printf("请输入出口的行数，列数：");
    scanf("%d,%d",&end.x,&end.y);
}

int Pass(PosType b){
    if(m[b.x][b.y] == 1)
        return 1;
    else
        return 0;
}

void FootPrint(PosType a){
    m[a.x][a.y] = curstep;
}

void NextPos(PosType *c,int di){
    PosType direc[4] = {{0,1},{1,0},{0,-1},{-1,0}};
    (*c).x += direc[di].x;
    (*c).y += direc[di].y;
}

void MarkPrint(PosType b){
    m[b.x][b.y] = -1;
}

int MazePath(PosType start,PosType end){
    SeqStack S;
    PosType curpos;
    DataType e;
    InitStack(&S);
    curpos = start;
    do{
        if(Pass(curpos)){
            FootPrint(curpos);
            e.ord = curstep;
            e.seat = curpos;
            e.di = 0;
            PushStack(&S,e);
            curstep++;
            if(curpos.x == end.x && curpos.y == end.y){
                return 1;
            }
            NextPos(&curpos,e.di);
        }
        else{
            if(!StackEmpty(S)){
                PopStack(&S,&e);
                curstep--;
                while(e.di == 3 && !StackEmpty(S)){
                    MarkPrint(e.seat);
                    PopStack(&S,&e);
                    curstep--;
                }
                if(e.di < 3){
                    e.di++;
                    PushStack(&S,e);
                    curstep++;
                    curpos = e.seat;
                    NextPos(&curpos,e.di);
                }
            }
        }
    }while(!StackEmpty(S));
    return 0;
}

int main(){
    Init(1);
    if(MazePath(begin,end)){
        printf("此迷宫从入口到出口的一条路径如下：\n");
        Print();
    }
    else{
        printf("此迷宫没有从入口到出口的路径~\n");
    }
    return 0;
}
