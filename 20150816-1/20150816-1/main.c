//
//  main.c
//  20150816-1
//
//  Created by 欣 陈 on 15/8/16.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//特殊矩阵的压缩存储
//设计一个算法trans将b中元素按列为主序连续存放在数组c中
void trans(int b[],int c[],int n){
    int step = n;
    int count = 0;
    int i = 0,j = 0,k;
    for(k = 0;k < n * (n + 1) / 2;k++){
        count++;
        c[j * (j + 1) / 2 + i] = b[k];
        if(count == step){
            step--;
            count = 0;
            i++;
            j = n - step;
        }
        else
            j++;
    }
}