//
//  main.c
//  20150823-6
//
//  Created by 欣 陈 on 15/8/23.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//遍历线索二叉树
//1.在中序线索二叉树中查找结点的直接前驱
BiThrNode *InOrderPre(BiThrNode *p) {
    BiThrNode *pre;
    if(p->ltag == Thread)
        return p->lchild;
    else {
        pre = p->lchild;
        while(pre->rtag == Link)
            pre = pre->rchild;
        return pre;
    }
}

//2.在中序线索二叉树中查找结点的直接后继
BiThrNode *InOrderPost(BiThrNode *p) {
    BiThrNode *pre;
    if(p->rtag == Thread)
        return p->rchild;
    else {
        pre = p->rchild;
        while(pre->ltag == Link)
            pre = pre->lchild;
        return pre;
    }
}

//3.中序遍历线索二叉树
int InOrderTraverse(BiThrTree T,int (*visit)(BiThrTree e)) {
    BiThrTree p;
    p = T->lchild;
    while(p != T) {
        while(p->ltag == Link)
            p = p->lchild;
        if(!visit(p))
            return 0;
        while(p->rtag == Thread && p->rchild != T) {
            p = p->rchild;
            visit(p);
        }
        p = p->rchild;
    }
    return 1;
}
