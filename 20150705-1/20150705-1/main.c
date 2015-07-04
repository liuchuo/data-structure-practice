//
//  main.c
//  20150705-1
//
//  Created by 欣 陈 on 15/7/4.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//编写算法，实现双端队列的入队和出队操作
//要求：当队列满时，最多只能有一个存储空间为空
//在进行插入和删除元素时，队列中的其他元素不动
#define QueueSize 10
typedef char DataType;
typedef struct DQueue{
    DataType queue[QueueSize];
    int end1;
    int end2;
}DQueue;
int EnQueue(DQueue *DQ,DataType e,int tag){
    switch(tag){
        case 1:
            if((DQ->end1 - 1 + QueueSize) % QueueSize != DQ->end2){
                DQ->queue[DQ->end1] = e;
                DQ->end1 = (DQ->end1 - 1 + QueueSize) % QueueSize;
                return 1;
            }
            else{
                return 0;
            }
        case 2:
            if((DQ->end2 + 1 + QueueSize) % QueueSize != DQ->end1){
                DQ->queue[DQ->end2] = e;
                DQ->end2 = (DQ->end2 + 1 + QueueSize) % QueueSize;
                return 1;
            }
            else{
                return 0;
            }
    }
    return 0;
}

int DeQueue(DQueue *DQ,DataType *e,int tag){
    switch(tag){
        case 1:
            if(DQ->end1 != DQ->end2){
                DQ->end1 = (DQ->end1 + 1 + QueueSize) % QueueSize;
                *e = DQ->queue[DQ->end1];
                return 1;
            }
            else{
                return 0;
            }
        case 2:
            if(DQ->end2 != DQ->end1){
                DQ->end2 = (DQ->end2 - 1 + QueueSize) % QueueSize;
                *e = DQ->queue[DQ->end2];
                return 1;
            }
            else{
                return 0;
            }
    }
    return 0;
}
