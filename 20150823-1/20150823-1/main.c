//
//  main.c
//  20150823-1
//
//  Created by 欣 陈 on 15/8/23.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//二叉链表及其基本运算
typedef struct Node {
    DataType data;
    struct Node *lchild;
    struct Node *rchild;
}*BiTree,BitNode;

//初始化二叉树
void InitBitTree(BiTree *T) {
    *T = NULL;
}

//销毁二叉树
void DestroyBitTree(BiTree *T) {
    if(*T) {
        if((*T)->lchild)
            DestroyBitTree(&((*T)->lchild));
        if((*T)->rchild)
            DestroyBitTree(&((*T)->rchild));
        free(*T);
        *T = NULL;
    }
}

//创建二叉树
void CreateBitTree(BiTree *T) {
    DataType ch;
    scanf("%c",&ch);
    if(ch == '#')
        *T = NULL;
    else {
        *T = (BiTree)malloc(sizeof(BitNode));
        if(!(*T))
            exit(-1);
        (*T)->data = ch;
        CreateBitTree(&((*T)->lchild));
        CreateBitTree(&((*T)->rchild));
    }
}

//二叉树的插入操作
int InsertChild(BiTree p,int LR,BiTree c) {
    if(p) {
        if(LR == 0) {
            q->rchild = q->lchild;
            p->lchild = c;
        }
        else {
            c->rchild = p->rchild;
            p->rchild = c;
        }
        return 1;
    }
    return 0;
}

//返回二叉树e的左孩子结点元素值
DataType LeftChild(BiTree T,DataType e) {
    BiTree p;
    if(T) {
        p = Point(T,e);
        if(p && p->lchild)
            return p->lchild->data;
    }
    return;
}

//返回二叉树e的右孩子结点元素值
DataType RightChild(BiTree T,DataType e) {
    BiTree p;
    if(T) {
        p = Point(T,e);
        if(p && p->rchild)
            return p->rchild->data;
    }
    return;
}

//返回二叉树给定结点的指针
BiTree Point(BiTree T,DataType e) {
    BiTree Q[MaxSize];
    int front = 0;
    int rear = 0;
    BitNode *p;
    if(T) {
        Q[rear] = T;
        rear++;
        while(front != rear) {
            p = Q[front];
            front++;
            if(p->data == e)
                return p;
            if(p->lchild) {
                Q[rear] = p->lchild;
                rear++;
            }
            if(p->rchild) {
                Q[rear] = p->rchild;
                rear++;
            }
        }
    }
    return NULL;
}

//删除子树操作
int DeleteLeftChild(BiTree p,int LR) {
    if(p) {
        if(LR == 0)
            DestroyBitTree(&(p->lchild));
        else
            DestroyBitTree(&(p->rchild));
        return 1;
    }
    return 0;
}
