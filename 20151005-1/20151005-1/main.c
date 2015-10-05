//
//  main.c
//  20151005-1
//
//  Created by 欣 陈 on 15/10/5.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//迪杰斯特拉（Dijkstra）算法
//是从一个顶点到其余各顶点的最短路径算法，解决的是有向图中最短路径问题。迪杰斯特拉算法主要特点是以起始点为中心向外层层扩展，直到扩展到终点为止。
//一步步求得从顶点到任意一个点的最短路径，然后层层用最小值相加得到更远顶点的最短路径
#define MAXVEX 9
#define INFINITY 65535
typedef int Pathmatirx[MAXVEX];
typedef int ShortPathTable[MAXVEX];
void ShortestPath_Dijkstra(MGraph G,int v0,Pathmatirx *P,ShortPathTable *D) {
    int v,w,k,min;
    int final[MAXVEX];
    for(v = 0;v < G.numVertexes;v++) {
        final[v] = 0;
        (*D)[v] = G.matirx[v0][v];
        (*P)[v] = 0;
    }
    (*D)[v0] = 0;
    final[v0] = 1;
    for(v = 1;v < G.numVertexes;v++) {
        min = INFINITY;
        for(w = 0;w < G.numVertexes;w++) {
            if(!final[w] && (*D)[w] < min) {
                k = w;
                min = (*D)[w];
            }
        }
        final[k] = 1;
        for(w = 0;w < G.numVertexes;w++) {
            if(!final[w] && (min + G.matirx[k][w] < (*D)[w])) {
                (*D)[w] = min + G.matirx[k][w];
                (*P)[w] = k;
            }
        }
    }
}
