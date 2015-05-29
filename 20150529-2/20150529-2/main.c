//
//  main.c
//  20150529-2
//
//  Created by 欣 陈 on 15/5/29.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//数组指针
#include <stdio.h>
int main(){
    int row,col;
    int a[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int (*p)[4];
    p = a;
    for(row = 0;row < 3;row++){
        for(col = 0;col < 4;col++)
            printf("a[%d][%d] = %d\n",row,col,*(*(p + row) + col));
        printf("\n");
    }
    for(p = a,row = 0;p < a+3;p++,row++){
        for(col = 0;col < 4;col++)
            printf("(*p[%d])[%d] = %p\n",row,col,((*p) + col));
        printf("\n");
    }
    for(p = a,row = 0;p < a+3;p++,row++){
        for(col = 0;col < 4;col++)
            printf("(*p[%d])[%d] = %d\n",row,col,((*p) + col));
        printf("\n");
    }
    return 0;
}
