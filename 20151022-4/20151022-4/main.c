//
//  main.c
//  20151022-4
//
//  Created by 欣 陈 on 15/10/22.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//基数排序
#define MaxNumKey 6
#define Radix 10
#define MaxSize 100
typedef int KeyType;
typedef struct {
    KeyType key[MaxNumKey];
    int next;
}SListCell;
typedef struct {
    SListCell data[MaxSize];
    int keynum;
    int length;
}SList;
typedef int addr[Radix];

//基数排序的分配算法
void Distribute(SListCell data[],int i,addr f,addr r) {
    int j,p;
    for(j = 0;j < Radix;j++)
        f[j] = 0;
    for(p = data[0].next;p;p = data[p].next) {
        j = trans(data[p].key[i]);
        if(!f[j])
            f[j] = p;
        else
            data[r[j]].next = p;
        r[j] = p;
    }
}

//基数排序的收集算法
void Collect(SListCell data[],addr f,addr r) {
    int j,t;
    for(j = 0;!f[j];j++);
    data[0].next = f[j];
    t = r[j];
    while(j < Radix - 1) {
        for(j = j + 1;j < Radix - 1 && !f[j];j++);
        if(f[j]) {
            data[t].next = f[j];
            t = r[j];
        }
    }
    data[t].next = 0;
}

//基数排序的= =
void RadixSort(SList *L) {
    int i;
    addr f,r;
    for(i = 0;i < (*L).keynum;i++) {
        Distribute((*L).data,i,f,r);
        Collect((*L).data,f,r);
    }
}