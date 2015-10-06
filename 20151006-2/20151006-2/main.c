//
//  main.c
//  20151006-2
//
//  Created by 欣 陈 on 15/10/6.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//关键路径算法
int *etv,*ltv;
int *stack2;
int top2;
//求拓扑序列，计算数组 etv 和 stack2的值
Status TopologicalSort(GraphAdjList GL) {
    EdgeNode *e;
    int i,k,gettop;
    int top = 0;
    int count = 0;
    int *stack;
    stack = (int *)malloc(GL->numVertexes * sizeof(int));
    for(i = 0;i < GL->numVertexes;i++) {
        if(GL->adjList[i].in == 0)
            stack[++top = i];
    }
    top2 = 0;
    etv = (int *)malloc(GL->numVertexes * sizeof(int));
    for(i = 0;i < GL->numVertexes;i++)
        etv[i] = 0;
    stack2 = (int *)malloc(GL->numVertexes * sizeof(int));
    while(top != 0){
        gettop = stack[top--];
        count++;
        stack2[++top2] = gettop;
        for(e = GL->adjList[gettop].firstedge; e ;e = e->next) {
            k = e->adjvex;
            if(!(--GL->adjList[k].in))
                stack[++top] = k;
            if((etv[gettop] + e->weight) > etv[k])
                etv[k] = etv[gettop] + e->weight;
        }
    }
    if(count < GL->numVertexes)
        return -1;
    else
        return 1;
}
//求关键路径，GL 为有向网，输出 GL 的各项关键活动
void CriticalPath(GraphAdjLIst GL) {
    EdgeNode *e;
    int i,gettop,k,j;
    int ete,lte;
    TopologicalSort(GL);
    ltv = (int *)malloc(GL->numVertexes * sizeof(int));
    for(i = 0; i < GL->numVertexes;i++) {
        ltv[i] = etv[GL->numVertexes - 1];
    }
    while(top2 != 0) {
        gettop = stack2[top--];
        for(e = GL->adjList[gettop].firstedge; e ;e = e->next) {
            k = e->adjvex;
            if(ltv[k] - e->weight < ltv[gettop])
                ltv[gettop] = ltv[k] - e->weight;
        }
    }
    for(j = 0;j < GL->numVertexes;j++) {
        for(e = GL->adjList[j].firstedge; e ;e = e->next) {
            k = e->adjvex;
            ete = etv[j];
            lte = ltv[k] - e->weight;
            if(ete = lte)
                printf(" <v%d,v%d> length: %d ,",GL->adjList[j].data,GL->adjLIst[k].data,e->weight);
        }
    }
}
