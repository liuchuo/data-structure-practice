//
//  main.c
//  20151009-1
//
//  Created by 欣 陈 on 15/10/9.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//斐波纳契查找
int Fibonacci_Search(int *a,int n,int key) {
    int low,high,mid,i,k;
    low = 1;
    high = n;
    k = 0;
    while(n > F[k] - 1)
        k++;
    for(i = n;i < F[k] - 1;i++)
        a[i] = a[n];
    while(low <= high) {
        mid = low + F[k - 1] - 1;
        if(key < a[mid]) {
            high = mid - 1;
            k = k - 1;
        }
        else
            if(key > a[mid]) {
                low = mid + 1;
                k = k - 2;
            }
            else {
                if(mid <= n)
                    return mid;
                else
                    return n;
            }
    }
    return 0;
}
