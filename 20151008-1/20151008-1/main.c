//
//  main.c
//  20151008-1
//
//  Created by 欣 陈 on 15/10/8.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//插值查找
int Search3(int *a,int n,int key) {
    int low,high,mid;
    low = 1;
    high = n;
    while(low <= high) {
        mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]);
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
