//
//  main.c
//  20150815-3
//
//  Created by 欣 陈 on 15/8/16.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

// 稀疏矩阵的转置 算法一
void TransposeMatrix(TriSeqMatrix M,TriSeqMatrix *N) {
    int i,k,col;
    N->m = M.n;
    N->n = M.m;
    N->len = M.len;
    if(N->len) {
        k = 0;
        for(col = 0;col < M.n;col++)
            for(i = 0;i < M.len;i++)
                if(M.data[i].j == col) {
                    N->data[k].i = M.data[i].j;
                    N->data[k].j = M.data[i].i;
                    N->data[k].e = M.data[i].e;
                    k++;
                }
    }
}
