//
//  main.c
//  20150604-1
//
//  Created by 欣 陈 on 15/6/4.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

#include <stdio.h>
int main(){
    union exam{
        int a;
        float b;
    };
    union exam *p,x;
    p = &x;
    x.a = 3;
    printf("%d\n",p->a);
    p->b = 4.5;
    printf("%f\n",x.b);
    return 0;
}
