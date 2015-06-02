//
//  main.c
//  20150602-3
//
//  Created by 欣 陈 on 15/6/2.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//查找链表中倒数第k个位置上的结点，输出这个结点的数据域
//定义两个指针p和q，p先动k个单位，之后q和p一起移动
//当p到了表尾结点的时候，q就是要找的结点
#include <stdio.h>
typedef struct LNode{
    int data;
    struct LNode *link;
}*LinkList;

int SearchNode(LinkList list,int k){
    LinkList p,q;
    int count = 0;
    p = list->link;
    q = list->link;
    while(p != NULL){
        if(count < k){
            count++;
        }
        else{
            q = q->link;
        }
        p = p->link;
    }
    if(count < k){
        return 0;
    }
    else{
        printf("链表中倒数第%d个结点的元素值为%d\n",k,q->data);
        return 1;
    }
}
