//
//  main.c
//  20150816-4
//
//  Created by 欣 陈 on 15/8/16.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//稀疏矩阵的转置 算法二（稀疏矩阵的快速转置）
void FastTransposeMatrix(TriSeqMatrix M,TriSeqMatrix *N) {
    int i,k,t,col,*num,*position;
    num = (int *)malloc((M.n+1) * sizeof(int));
    position = (int *)malloc((M.n+1) * sizeof(int));
    N->n = M.m;
    N->m = M.n;
    N->len = M.len;
    if(N->len) {
        for(col = 0;col < M.n;col++)
            num[col] = 0;
        for(t = 0;t < N.len;t++)
            num[M.data[t].j]++;//扫描每个三元组，每个三元组对应的列的num数不断+1
        position[0] = 0;
        for(col = 1;col < M.n;col++)
            position[col] = position[col - 1] + num[col - 1];
        for(i = 0;i < M.len;i++){
            col = M.data[i].j;
            k = position[col];
            N->data[k].i = M.data[i].j;
            N->data[k].j = M.data[i].i;
            N->data[k].e = M.data[i].e;
            position[col]++;
        }
    }
    free(num);
    free(position);
}

//销毁矩阵
void DestroyMatrix(TriSeqMatrix *M){
    M->m = M->n = M->len = 0;
}
