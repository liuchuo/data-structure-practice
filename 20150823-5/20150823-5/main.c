//
//  main.c
//  20150823-5
//
//  Created by 欣 陈 on 15/8/23.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//线索二叉树
typedef enum{Link,Thread}PointerTag;
typedef struct Node {
    DataType data;
    struct Node *lchild,*rchild;
    PointerTag ltag,rtag;
}*BiThrTree,BiThrNode;

//中序线索二叉树
BiThrTree pre;
int InOrderThreading(BiThrTree *Thrt,BiThrTree T) {
    if(!(*Thrt = (BiThrTree)malloc(sizeof(BiThrNode))))
        exit(-1);
    (*Thrt)->ltag = Link;
    (*Thrt)->rtag = Thread;
    (*Thrt)->rchild = *Thrt;
    if(!T)
        (*Thrt)->lchild = *Thrt;
    else {
        (*Thrt)->lchild = T;
        pre = *Thrt;
        InThreading(T);
        pre->rchild = *Thrt;
        pre->rtag = Thread;
        (*Thrt)->rchild = pre;
    }
    return 1;
}

void InThreading(BiThrTree p) {
    if(p) {
        InThreading(p->lchild);
        if(!p->lchild) {
            p->ltag = Thread;
            p->lchild = pre;
        }
        if(!pre->rchild) {
            pre->rtag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}
