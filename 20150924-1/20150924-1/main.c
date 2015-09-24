//
//  main.c
//  20150924-1
//
//  Created by 欣 陈 on 15/9/24.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//prim算法生成最小生成树
void MiniSpanTree_Prim(MGraph G) {
    int min,i,j,k;
    int adjvex[MAXVEX];
    int lowcost[MAXVEX];
    lowcost[0] = 0;
    adjvex[0] = 0;
    for(i = 1;i < G.numVertexes;i++) {
        lowcost = G.arc[0][i];
        adjvex[i] = 0;
    }
    for(i = 1;i < G.numVertexes;i++) {
        min = INFINITY;
        j = 1;
        k = 0;
        while(j < G.numVertexes) {
            if(lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        printf("(%d,%d)",adjvex[k],k);
        lowcost[k] = 0;
        for(j = 1;j < G.numVertexes;j++) {
            if(lowcost[j] != 0 && G,arc[k][j] < lowcost[j]) {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k;
            }
        }
    }
}
