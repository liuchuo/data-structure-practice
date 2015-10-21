//
//  main.c
//  20151021-3
//
//  Created by 欣 陈 on 15/10/21.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//排序
#define MaxSize 100
typedef int KeyType;
typedef struct {
    KeyType key;
}DataType;
typedef struct {
    DataType data[MaxSize];
    int length;
}Sqlist;

//插入排序-直接插入排序
void InsertSort(SqList *L) {
    int i,j;
    DataType t;
    for(i = 1;i < L->length;i++) {
        t = L->data[i + 1];
        j = i;
        while (j > 0 && t.key < L->data[j].key) {
            L->data[j + 1] = L->data[j];
            j--;
        }
        L->data[j + 1] = t;
    }
}

//插入排序-折半插入排序
void BinInsertSort(SqList *L) {
    int i,j,mid,low,high;
    DataType t;
    for(i = 1;i < L->length;i++) {
        t = L->data[i + 1];
        while(low <= high) {
            mid = (low + high) / 2;
            if(L->data[mid].key > t.key)
                high = mid - 1;
            else
                low = mid + 1;
        }
        for(j = i;j >= low;j--)
            L->data[j + 1] = L->data[j];
        L->data[low] = t;
    }
}

//插入排序-希尔排序
void ShellInsert(SqList *L,int c) {
    int i,j;
    DataType t;
    for(i = c + 1;i <= L->length;i++) {
        if(L->data[i].key <= L->data[i - c].key) {
            t = L->data[i];
            for(j = i - c;j > 0 && t.key < L->data[j].key;j = j - c)
                L->data[j + c] = L->data[j];
            L->data[j + c] = t;
        }
    }
}

void ShellInsertSort(SqList *L,int delta[],int m) {
    int i;
    for(i = 0;i < m;i++)
        ShellInsert(L,delta[i]);
}
