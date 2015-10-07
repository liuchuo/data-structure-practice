//
//  main.c
//  20151007-1
//
//  Created by 欣 陈 on 15/10/7.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//顺序查找
int Sequential_Search(int *a,int n,int key) {
    int i;
    for(i = 1;i <= n;i++) {
        if(a[i] == key)
            return i;
        else
            return 0;
    }
}




//顺序表查找的优化:有哨兵顺序的查找
int Sequential_Search2(int *a,int n,int key) {
    int i;
    a[0] = key;
    i = n;
    while(a[i] != key)
        i--;
    return i;
}



//折半查找（二分查找）
int Binary_Search(int *a,int n,int key) {
    int low,high,mid;
    low = 1;
    high = n;
    while(low <= high) {
        mid = (low + high) / 2;
        if(key <= a[mid])
            high = mid - 1;
        else
            if(key > a[mid])
                low = mid + 1;
            else
                return mid;
    }
    return 0;
}
