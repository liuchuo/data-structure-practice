//
//  main.c
//  20151022-1
//
//  Created by 欣 陈 on 15/10/22.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//交换排序-冒泡排序
void BubbleSort(SqList *L,int n) {
    int i,j,flag;
    DataType t;
    for(i = 1;i <= n - 1 && flag;i++) {
        flag = 0;
        for(j = 1;j <= n - i;j++)
            if(L->data[j].key > L->data[j + 1].key) {
                t = L->data[j].key;
                L->data[j].key = L->data[j + 1].key;
                L->data[j + 1].key = t;
                flag = 1;
            }
    }
}

//交换排序-快速排序
int Partition(SqList *L,int low,int high) {
    DataType t;
    KeyType pivotkey;
    pivotkey = (*L).data[low].key;
    t = (*L).data[low];
    while(low < high) {
        while(low < high && (*L).data[high].key >= pivotkey)
            high--;
        if(low < high) {
            (*L).data[low] = (*L).data[high];
            low++;
        }
        while(low < high && (*L).data[low].key <= pivotkey)
            low++;
        if(low < high) {
            (*L).data[high] = (*L).data[low];
            high--;
        }
    }
    (*L).data[low] = t;
    return low;
}
void QuickSort(SqList *L,int low,int high) {
    int pivot;
    if(low < high) {
        pivot = Partition(L,low,high);
        QuickSort(L,low,pivot - 1);
        QuickSort(L,pivot + 1,high);
    }
}
