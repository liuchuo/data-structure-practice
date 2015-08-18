//
//  main.c
//  20150818-1
//
//  Created by 欣 陈 on 15/8/18.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
typedef int AtomType;
typedef enum{ATOM,LIST}ElemTag;
typedef struct {
    ElemTag tag;/*tag用于区分元素是原子还是子表*/
    union {
        AtomType atom;
        struct {
            struct GLNode *hp,*tp;/*hp指向表头，tp指向表尾*/
        }ptr;
    };
}*GList,GLNode;

//求广义表的表头
GLNode* GetHead(GList L){
    GLNode *p;
    if(!L){
        printf("该广义表是空表！");
        return NULL;
    }
    p = L->ptr.hp;
    if(!p)
        printf("该广义表的表头是空表");
    else if(p->tag == LIST)
        printf("该广义表的表头是非空的子表");
    else
        printf("该广义表的表头是原子");
    return p;
}

//求广义表的表尾
GLNode* GeTail(GList L){
    if(!L){
        printf("该广义表是空表！");
        return NULL;
    }
    return L->ptr.hp;//广义表不是空表，则表尾不可能是空表也不可能是原子
}

//求广义表的长度
int GListLength(GList L){
    int length = 0;
    while(L){
        L = L->ptr.tp;
        length++;
    }
    return length;
}

//由广义表L复制得到广义表T
void CopyList(GList *T,GList L) {
    if(!L)
        *T = NULL;
    else {
        *T = (GList)malloc(sizeof(GLNode));
        if(*T == NULL)
            exit(-1);
        (*T)->tag = L->tag;
        if(L->tag == ATOM)
            (*T)->atom = L->atom;
        else {
            CopyList(&((*T)->ptr.hp),L->ptr.hp);
            CopyList(&((*T)->ptr.tp),L->ptr.tp);
        }
    }
}

//求广义表的深度
int GListDepth(GList L) {
    int max;
    int depth;
    GLNode *p;
    if(!L)
        return 1;
    if(L->tag == ATOM)
        return 0;
    for(max = 0,p = L;p;p = p->ptr.tp) {
        depth = GListDepth(p->ptr.hp);
        if(max < depth)
            max = depth;
    }
    return max + 1;
}