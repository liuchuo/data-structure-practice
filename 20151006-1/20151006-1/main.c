//
//  main.c
//  20151006-1
//
//  Created by 欣 陈 on 15/10/6.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//拓扑排序算法
//in data firstedge
//边表结点
typedef struct EdgeNode {
    int adjvex;
    int weight;
    struct EdgeNode *next;
}EdgeNode;
//顶点表结点
typedef struct VertexNode {
    int in;
    int data;
    EdgeNode *firstedge;
}VertexNode,AdjList[MAXVEX];
typedef struct {
    AdjList adjList;
    int numVertexes,numEdges;
}graphAdjList,*GraphAdjList;

Status TopologicalSort(GraphAdjList GL) {
    EdgeNode *e;
    int i,k,gettop;
    int top = 0;
    int count = 0;
    int *stack;//建栈存储入度为0的点
    stack = (int *)malloc(GL->numVertexes* sizeof(int));
    for(i = 0;i < GL->numVertexes;i++) {
        if(GL->adjList[i].in == 0)
            stack[++top] = i;
    }
    while(top != 0) {
        gettop = stack[top--];
        printf("%d -> ",GL->adjList[gettop].data);
        count++;
        for(e = GL->adjList[gettop].firstedge; e ;e = e->next) {
            k = e->adjvex;
            if(!(--GL->adjList[k].in))
                stack[++top] = k;
        }
    }
    if(count < GL->numVertexes)
        return -1;
    else
        return 1;
}
