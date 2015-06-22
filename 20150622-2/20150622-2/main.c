//
//  main.c
//  20150622-2
//
//  Created by 欣 陈 on 15/6/22.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//n阶乘递归函数
int fact(int n){
    if(n == 1)
        return 1;
    else
        return n*fact(n-1);
}



//Ackerman递归函数
int Ack(int m,int n){
    if(m == 0)
        return n + 1;
    else
        if(n == 0)
            return Ack(m - 1,1);
        else
            return Ack(m - 1,Ack(m,n - 1));
}
