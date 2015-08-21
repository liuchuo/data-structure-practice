//
//  main.c
//  20150821-1
//
//  Created by 欣 陈 on 15/8/21.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//广义表的扩展线性链表表示与实现
#include <stdio.h>
#include <stdlib.h>
typedef int AtomType;
typedef enum{ATOM,LIST}ElemTag;
typedef struct {
    ElemTag tag;
    union {
        AtomType atom;
        struct GLNode *hp;
    }ptr;
    struct GLNode *tp;
}*GList,GLNode;

GLNode* GetHead(GList L) {
    GLNode *p;
    p = L->ptr.hp;
    if(!p) {
        printf("空表。");
        return NULL;
    }
    else if(p->tag == LIST)
        printf("表头为非空的子表。");
    else
        printf("表头是原子。");
    return p;
}

GLNode* GeTail(GList L) {
    GLNode *p,*tail;
    p = L->ptr.hp;
    if(!p) {
        printf("空表。");
        return NULL;
    }
    tail = (GLNode *)malloc(sizeof(GLNode));
    tail->tag = LIST;
    tail->ptr.hp = p->tp;
    tail->tp = NULL;
    return tail;
}

int GListLength(GList L) {
    int length = 0;
    GLNode *p = L->ptr.hp;
    while(p) {
        length++;
        p = p->tp;
    }
    return length;
}

void CopyList(GList *T,GList L) {
    if(!L)
        *T = NULL;
    else {
        *T = (GList)malloc(sizeof(GLNode));
        if(*T == NULL)
            exit(-1);
        (*T)->tag = L->tag;
        if(L->tag == ATOM)
            (*T)->ptr.atom = L->ptr.atom;
        else
            CopyList(&((*T)->ptr.hp),L->ptr.hp);
        if(L->tp == NULL)
            (*T)->tp = L->tp;
        else
            CopyList(&((*T)->tp),L->tp);
    }
}


int GListDepth(GList L) {
    int max,depth;
    GLNode *p;
    if(L->tag == LIST && L->ptr.hp == NULL)
        return 1;
    if(L->tag == ATOM)
        return 0;
    p = L->ptr.hp;
    for(max = 0;p;p = p->tp) {
        depth = GListDepth(p);
        if(max < depth)
            max = depth;
    }
    return max + 1;
}
