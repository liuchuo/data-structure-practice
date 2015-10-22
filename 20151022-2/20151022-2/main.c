//
//  main.c
//  20151022-2
//
//  Created by 欣 陈 on 15/10/22.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//选择排序-简单选择排序
void SelectSort(Sqlist *L,int n) {
    int i,j,k;
    DataType t;
    for(i = 1;i <= n-1;i++) {
        j = i;
        for(k = i + 1;k <=n;k++) {
            if(L->data[k].key < L->data[j].key)
                j = k;
        }
        if(j != i) {
            t = L->data[i];
            L->data[i] = L->data[j];
            L->data[j] = t;
        }
    }
}



//选择排序-堆排序
//建立大顶堆
void CreateHeap(SqList *H,int n) {
    int i;
    for(i = n / 2;i >= 1;i--)
        AdjustHeap(H,i,n);
}

void AdjustHeap(SqList *H,int s,int m) {
    DataType t;
    int j;
    t = (*H).data[s];
    for(j = 2 * s;j <= m;j *= 2) {
        if(j < m && (*H).data[j].key < (*H).data[j + 1].key)
            j++;
        if(t.key > (*H).data[j].key)
            break;
        (*H).data[s] = (*H).data[j];
        s = j;
    }
    (*H).data[s] = t;
}

//调整堆
void HeapSort(SqList *H) {
    DataType t;
    int i;
    CreateHeap(H,H->length);
    for(i = (*H).length;i > 1;i--) {
        t = (*H).data[1];
        (*H).data[1] = (*H).data[i];
        (*H).data[i] = t;
    }
}
