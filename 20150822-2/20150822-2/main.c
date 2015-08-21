//
//  main.c
//  20150822-2
//
//  Created by 欣 陈 on 15/8/22.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//第三篇 非线性数据结构 第9章 树
//树的存储结构
//1.双亲表示法
typedef int DataType;
#define MaxSize 200

typedef struct Pnode {
    DataType data;
    int parent;
}PNode;

typedef struct {
    PNode node[MaxSize];
    int num;
}PTree;


//孩子表示法
typedef struct CNode {//孩子结点
    int child;
    struct CNode *next;
}ChildNode;

typedef struct {//表头结构
    DataType data;
    ChildNode *firstchild;
}DataNode;

typedef struct {//孩子表示法
    DataNode node[MaxSize];
    int num,root;
}CTree;


//孩子兄弟表示法（树的二叉链表表示法）(树的最常用的存储结构)
//（包含一个数据域和两个指针域，指针域分别指向第一个孩子结点和下一个兄弟结点）
// data  firstchild  nextsibling
typedef struct CSNode {
    DataType data;
    struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;
