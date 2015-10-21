//
//  main.c
//  20151021-1
//
//  Created by 欣 陈 on 15/10/21.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//平衡二叉树
typedef struct BSTNode {
    DataType data;
    int bf;
    struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;

//平衡二叉排序树的插入算法
int InsertAVL(BSTree *T,DataType e,int *taller) {
    if(!*T) {
        *T = (BSTree)malloc(sizeof(BSTNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->bf = 0;
        *taller = 1;
    }
    else {
        if(e.key == (*T)->data.key) {
            *taller = 0;
            return 0;
        }
        if(e.key < (*T)->data.key) {
            if(!InsertAVL(&(*T)->lchild,e,taller))
                return 0;
            if(*taller) {
                switch((*T)->bf) {
                    case 1:
                        LeftBalance(T);
                        *taller = 0;
                        break;
                    case 0:
                        (*T)->bf = 1;
                        *taller = 1;
                        break;
                    case -1:
                        (*T)->bf = 0;
                        *taller = 0;
                }
            }
        }
        else {
            if(!InsertAVL(&(*T)->rchild,e,taller))
                return 0;
            if(*taller) {
                switch((*T)->bf) {
                    case 1:
                        (*T)->bf = 0;
                        *taller = 0;
                        break;
                    case 0:
                        (*T)->bf = -1;
                        *taller = 1;
                        break;
                    case -1:
                        RightBalance(T);
                        *taller = 0;
                }
            }
        }
    }
    return 0;
}

//LL型的平衡处理算法
void RightRotate(BSTree *p) {
    BSTree lc;
    lc = (*p)->lchild;
    (*p)->lchild = lc->rchild;
    lc->rchild = *p;
    (*p)->bf = lc->bf = 0;
    *p = lc;
}

//RR型的平衡处理算法
void LightRoatate(BSTree *p) {
    BSTree rc;
    rc = (*p)->rchild;
    (*p)->rchild = rc->lchild;
    rc->lchild = *p;
    *p = rc;
}

//LR的平衡处理算法
void LeftBalance(BSTree *T) {
    BSTree lc,rd;
    lc = (*T)->lchild;
    switch(lc->bf) {
        case 1:
            (*T)->bf = lc->bf = 0;
            RightRotate(T);
            break;
        case -1:
            rd = lc->rchild;
            switch(rd->bf) {
                case 1:
                    (*T)->bf = -1;
                    lc->bf = 0;
                    break;
                case 0:
                    (*T)->bf = lc->bf = 0;
                    break;
                case -1:
                    (*T)->bf = 0;
                    lc->bf = 1;
            }
            rd->bf = 0;
            LeftRotate(&(*T)->lchild);
            RightRotate(T);
    }
}

//RL型的平衡处理算法
void RightBalance(BSTree *T) {
    BSTree rc,rd;
    rc = (*T)->rchild;
    switch(rc->bf) {
        case -1:
            (*T)->bf = rc->bf = 0;
            LeftRotate(T);
            break;
        case 1:
            rd = rc->lchild;
            switch(rd->bf) {
                case -1:
                    (*T)->bf = 1;
                    rc->bf = 0;
                    break;
                case 0:
                    (*T)->bf = rc->bf = 0;
                    break;
                case 1:
                    (*T)->bf = 0;
                    rc->bf = -1;
            }
            rd->bf = 0;
            RightRotate(&(*T)->rchild);
            LeftRotate(T);
    }
}
