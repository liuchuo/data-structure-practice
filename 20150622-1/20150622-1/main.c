//
//  main.c
//  20150622-1
//
//  Created by 欣 陈 on 15/6/22.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//斐波那契数列：迭代方法
//#include <stdio.h>
//int main(){
//    int i;
//    int a[40];
//    a[0] = 0;
//    a[1] = 1;
//    printf("%d\t%d\t",a[0],a[1]);
//    for(i = 2;i < 40;i++){
//        a[i] = a[i - 1] + a[i - 2];
//        printf("%d\t",a[i]);
//    }
//    return 0;
//}

//递归方法
#include <stdio.h>
int Fib(int n){
    if(n==0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return Fib(n-1)+Fib(n-2);
}

int main(){
    int i;
    for(i = 0;i < 40;i++)
        printf("%d\t",Fib(i));
    return 0;
}
