//
//  main.c
//  20150823-3
//
//  Created by 欣 陈 on 15/8/23.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//非递归遍历二叉树——基于栈的递归消除
//中序遍历二叉树的非递归算法实现
void InOrderTraverse(BiTree T) {
    BiTree stack[MaxSize];
    int top;
    BitNode *p;
    top = 0;
    p = T;
    while(p != NULL || top > 0) {
        while(p != NULL) {
            stack[top++] = p;
            p = p->lchild;
        }
        if(top > 0) {
            p = stack[--top];
            printf("%2c",p->data);
            p = p->rchild;
        }
    }
}

//后序遍历二叉树的非递归算法实现
void PostOrderTraverse(BiTree T) {
    BiTree stack[MaxSize];
    int top;
    BitNode *p,*q;
    top = 0;
    p = T;
    q = NULL;
    while(p != NULL || top > 0) {
        while(p != NULL) {
            stack[top++] = p;
            p = p->lchild;
        }
        if(top > 0) {
            p = stack[top - 1];
            if(p->rchild == NULL || p->rchild == q) {
                printf("%2c",p->data);
                q = p;
                p = NULL;
                top--;
            }
            else
                p = p->rchild;
        }
    }
}
