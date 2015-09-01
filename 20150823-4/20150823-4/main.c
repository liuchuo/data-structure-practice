//
//  main.c
//  20150823-4
//
//  Created by 欣 陈 on 15/8/23.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//按层次输出二叉树
void LevelPrint(BiTree T) {
    BiTree queue[MaxSize];
    BitNode *p;
    int front,rear;
    front = rear = -1;
    rear++;
    queue[rear] = T;
    while(front != rear) {
        front = (front + 1) % MaxSize;
        p = queue[front];
        printf("%c ",p->data);
        if(p->lchild != NULL) {
            rear = (rear + 1) % MaxSize;
            queue[rear] = p->lchild;
        }
        if(p->rchild != NULL) {
            rear = (rear + 1) % MaxSize;
            queue[rear] = p->rchild;
        }
    }
}


//计算二叉树的叶子结点个数
int LeafNum(BiTree T) {
    if(!T)
        return 0;
    else
        if(!T->lchild && !T->rchild)
            return 1;
        else
            return LeafNum(T->lchild) + LeafNum(T->child);
}

//求二叉树的非叶子结点个数
int NotLeafNum(BiTree T) {
    if(!T)
        return 0;
    else if(!T->lchild && !T->rchild)
        return 0;
    else
        NotLeafNum(T->child) + NotLeafNum(T->rchild) + 1;
}

//计算二叉树的所有结点数
int AllNodes(BiTree T) {
    if(!T)
        return 0;
    else if(!T->lchild && !T->rchild)
        return 1;
    else
        return AllNodes(T->lchild) + AllNodes(T->rchild) + 1;
}

//计算二叉树的深度
int BitTreeDepth(BiTree T) {
    if(T == NULL)
        return 0;
    return BitTreeDepth(T->lchild) > BitTreeDepth(T->rchild) ? 1 + BitTreeDepth(T->lchild) : 1 + BitTreeDepth(T->rchild);
}

//求叶子结点的最大最小枝长
void MaxMinLeaf(BiTree T,int *max,int *min) {
    int m1,m2,n1,n2;
    if(T == NULL) {
        *max = 0;
        *min = 0;
    }
    else {
        MaxMinLeaf(T->lchild,m1,n1);
        MaxMinLeaf(T->rchild,m2,n2);
        *max = (m1 > m2 ? m1 : m2) + 1;
        *min = (m1 < m2 ? m1 : m2) + 1;
    }
}

//判断两颗二叉树是否相似
int BiTree_Like(BiTree t1,BiTree t2) {
    if(t1 == NULL && t2 == NULL)
        return 1;
    if((t1 !== NULL && t2 == NULL) || ((t1 == NULL && t2 != NULL))
       return 0;
       if(BiTree_Like(t1->lchild,t2->lchild))
       return (BiTree_Like(t1->rchild,t2->rchild));
       else
       return 0;
       }
       
       //交换二叉树的左右子树
       void BiTree_Swap(BiTree T) {
           BiTree p;
           if(T != NULL) {
               if(T->lchild != NULL || T->rchild != NULL) {
                   p = T->lchild;
                   T->lchild = T->rchild;
                   T->rchild = p;
               }
               if(T->lchild != NULL)
                   BiTree_Swap(T->lchild);
               if(T->rchild != NULL)
                   BiTree_Swap(T->rchild);
           }
       }
       
       
       //求根结点到r结点之间的路径
       void path(BiTree root,BitNode *r) {
           BitNode *p,*q;
           int i,top = 0;
           BitNode *s[StackSize];
           q = NULL;
           p = root;
           while(p != NULL || top != 0) {
               while(p != NULL) {
                   top++;
                   if(top > StackSize)
                       exit(-1);
                   s[top] = p;
                   p = p->lchild;
               }
               if(top > 0) {
                   p = s[top];
                   if(p->rchild == NULL || p->rchild == q) {
                       if(p == r) {
                           for(i = 1;i <= top;i++)
                               printf("%4d",s[i]->data);
                           top = 0;
                       }
                       else {
                           q = p;
                           top--;
                           p = NULL;
                       }
                   }
                   else
                       p = p->rchild;
               }
           }
       }
