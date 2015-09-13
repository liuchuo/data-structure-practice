//
//  main.c
//  20150913-1
//
//  Created by 欣 陈 on 15/9/13.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//冒泡排序
void bubble_sort(int a[],int n) {
    int i,j,temp;
    for(j = 0;j < n - 1;j++)
        for(i = 0;i < n - 1 - j;i++) {
            if(a[i] > a[i + 1]) {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
}



//选择排序
void select_sort(int a[],int n) {
    int i,j,min,temp;
    for(i = 0;i < n - 1;i++) {
        min = i;
        for(j = i + 1;j < n;j++) {
            if(a[j] < a[min])
                min = j;
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}



//快速排序
void quick_sort(int a[],int left,int right) {
    if(left < right) {
        int key = a[left];
        int low = left;
        int high = right;
        while(low < high) {
            while(low < high && a[high] > key) {
                high--;
            }
            a[low] = a[high];
            while(low < high && a[low] < key) {
                low++;
            }
            a[high] = a[low];
        }
        a[low] = key;
        quick_sort(a,left,low - 1);
        quick_sort(a,low + 1,right);
    }
}

void quick_sort(int a[],int left,int right) {
    if(left >= right) {
        return;
    }
    int i = left;
    int j = right;
    int key = a[left];
    
    while(i < j) {
        while(i < j && key <= a[j]) {
            j--;
        }
        a[i] = a[j];
        
        while(i < j && key >= a[i]) {
            i++;
        }
        a[j] = a[i];
    }
    a[i] = key;
    quick_sort(a,left,i - 1);
    quick_sort(a,i + 1,right);
}
