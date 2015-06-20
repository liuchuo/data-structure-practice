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
typedef int MazeType[MaxLENGTH][MaxLENGTH];
MazeType m;
int x,y;
PosType begin,end;
int curstep = 1;

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
    prinf("请输入出口的行数，列数：");
    scanf("%d,%d",&end.x,&end.y);
}

void Print(){
    int i,j;
    for(i = 0;i < x;i++){
        for(j = 0;j < y;j++){
            printf("%3d",m[i][j]);
        }
        printf("\n");
    }
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
            
        }
    }
}
