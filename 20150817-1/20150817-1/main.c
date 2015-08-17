//
//  main.c
//  20150817-1
//
//  Created by 欣 陈 on 15/8/17.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//第八章_广义表
//广义表的头尾链表存储结构
typedef enum{ATOM,LIST}ElemTag;
typedef struct {
    ElemTag tag;/*tag用于区分元素是原子还是子表*/
    union {
        AtomType atom;
        struct {
            struct GLNode *hp,*tp;/*hp指向表头，tp指向表尾*/
        }ptr;
    };
}*GList,GLNode;
