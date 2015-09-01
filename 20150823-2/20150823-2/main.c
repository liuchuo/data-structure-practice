//
//  main.c
//  20150823-2
//
//  Created by 欣 陈 on 15/8/23.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//先序遍历二叉树的递归算法
void PreOrderTraverse(BiTree T) {
    if(T) {
        printf("%2c",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//中序遍历二叉树
void InOrderTraverse(BiTree T) {
    if(T) {
        InOrderTraverse(T->lchild);
        printf("%2c",T->data);
        InOrderTraverse(T->rchild);
    }
}


//后序遍历二叉树
void PostOrderTraverse(BiTree T) {
    if(T) {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        printf("%2c",T->data);
    }
}
