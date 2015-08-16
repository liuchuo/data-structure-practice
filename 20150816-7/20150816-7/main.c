//
//  main.c
//  20150816-7
//
//  Created by 欣 陈 on 15/8/16.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//稀疏矩阵的十字链表表示与实现 - 添加down 和 right指针域
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct OLNode{
    int i;
    int j;
    DataType e;
    struct OLNode *right,*down;
}OLNode,*OLink;

typedef struct{
    OLink *rowhead;
    OLink *colhead;
    int m;
    int n;
    int len;
}CrossList;

//init
void InitMatrix(CrossList *M){
    M->rowhead = M->colhead = NULL;
    M->m = M->n = M->len = 0;
}

//insert
void InsertMatrix(CrossList *M,OLink p){
    OLink q;
    q = M->rowhead[p->i];
    if(!q || p->j < q->j){
        p->right = M->rowhead[p->i];
        M->rowhead[p->i] = p;
    }
    else{
        while(q->right && q->right->j < p->j)
            q = q->right;
        p->right = q->right;
        q->right = p;
    }
    q = M->colhead[p->j];
    if(!q || p->i < q->i){
        p->down = M->colhead[p->j];
        M->colhead[p->j] = p;
    }
    else{
        while(q->down && q->down->i < p->i)
            q = q->down;
        p->down = q->down;
        q->down = p;
    }
    M->len++;
}

//destroy
void DestroyMatrix(CrossList *M){
    int i;
    OLink p,q;
    for(i = 0;i < M->m;i++){
        p = *(M->rowhead + i);
        while(p){
            q = p;
            p = p->right;
            free(q);
        }
    }
    free(M->rowhead);
    free(M->colhead);
    InitMatrix(M);
}
