//
//  main.c
//  20150924-2
//
//  Created by 欣 陈 on 15/9/24.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//Kruskal（克鲁斯卡尔）算法，用到图的存储结构中的边集数组结构
#include <stdio.h>
typedef struct {
    int begin;
    int end;
    int weight;
}Edge;
#define MAXEDGE 15
#define MAXVEX 9
int Find(int *parent,int f);

void MiniSpanTree_Kruskal(MGraph G) {
    int i,n,m;
    Edge edges[MAXEDGE];
    int parent[MAXEDGE];//define a one-dimensional array to judge whether the edge to edge to form a loop
//the code of sorting the array from small to large order is omitted here
//Initialize the array:->
    for(i = 0;i < G.numEdges;i++) {
        parent[i] = 0;
    }
    for(i = 0;i < G.numEdges;i++) {
        n = Find(parent,edges[i].begin);
        m = Find(parent,edges[i].end);
        if(n != m) {
            parent[n] = m;
            printf("(%d , %d) %d",edges[i].begin,edges[i].end,edges[i].weight);
        }
    }
}

int Find(int *parent,int f) {
    while(parent[f] > 0)
        f = parent[f];
    return f;
}
