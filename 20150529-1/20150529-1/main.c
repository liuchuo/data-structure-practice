//
//  main.c
//  20150529-1
//
//  Created by 欣 陈 on 15/5/29.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//利用指针数组实现对一组变量的值按照从小到大排序，排序时交换指向变量的指针值
#include <stdio.h>
void bubble(int *a[],int n);
int main(){
    int a,b,c,d,e,f,i;
    int *vp[] = {&a,&b,&c,&d,&e,&f};
    printf("请输入a，b，c，d，e，f的值：");
    scanf("%d,%d,%d,%d,%d,%d",&a,&b,&c,&d,&e,&f);
    bubble(vp,sizeof(vp) / sizeof(vp[0]));
    for(i = 0;i < sizeof(vp) / sizeof(vp[0]);i++)
        printf("%4d",*vp[i]);
    printf("\n");
    return 0;
}

void bubble(int *a[],int n){
    int i,j,flag,t;
    for(i = 0;i < n-1;i++){
        flag = 0;
        for(j = 0;j < n-1-i;j++){
            if(*a[j] > *a[j+1]){
                t = *a[j];
                *a[j] = *a[j+1];
                *a[j+1] = t;
                flag = 1;
            }
        }
        if(flag == 0)
            return;
    }
}
