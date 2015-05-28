//
//  main.c
//  20150528-5
//
//  Created by 欣 陈 on 15/5/28.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//利用递归函数输出正整数和等于n的所有不增的和式
#include <stdio.h>
#define N 100
void rd(int a[],int i,int k);
int main(){
    int n,a[N];
    printf("请输入一个正整数n(1<=n<=20):");
    scanf("%d",&n);
    a[0] = n;
    printf("不增的和式分解结果：\n");
    rd(a,n,1);
    return 0;
}

// i表示本次递归调用要分解的数
// a[k]存放第k步分解出来的和数
// 在分解过程中，当分解出来的数j==i时，说明已经完成一个和式分解，应将和式输出；
// 在分解过程中，当分解出来的数j < i时，说明还有i - j需要进行第k + 1次分解

void rd(int a[],int i,int k){
    int j,p;
    for(j = i;j >= 1;j--){
        if(j <= a[k-1]){
            a[k] = j;
            if(j == i){
                printf("%d = %d",a[0],a[1]);
                for(p = 2;p <= k;p++)
                    printf(" + %d",a[p]);
                printf("\n");
            }
            else
                rd(a,i-j,k+1);
        }
    }
}
