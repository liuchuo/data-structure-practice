//
//  main.c
//  20151022-3
//
//  Created by 欣 陈 on 15/10/22.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//归并排序-2路归并排序算法
void Merge(DataType s[],DataType t[],int low,int mid,int high) {
    int i,j,k;
    i = low;
    j = mid + 1;
    k = low;
    while(i <= mid && j <= high) {
        if(s[i].key <= s[j].key)
            t[k] = s[i++];
        else
            t[k] = s[j++];
        k++;
    }
    while(i <= mid)
        t[k++] = s[i++];
    while(j <= high)
        t[k++] = s[j++];
}

void MergeSort(DataType s[],DataType t[],int low,int high) {
    int mid;
    DataType t2[MaxSize];
    if(low == high)
        t[low] = s[low];
    else {
        mid = (low + high) / 2;
        MergeSort(s,t2,low,mid);
        MergeSort(s,t2,mid + 1;high);
        Merge(t2,t,low,mid,high);
    }
}
