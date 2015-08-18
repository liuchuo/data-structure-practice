//
//  main.c
//  20150819-2
//
//  Created by 欣 陈 on 15/8/19.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//广义表L = (a1,a2,...,an),其中ai(i = 1,2,……,n)或是原子或是子表
//编写一个函数计算一个广义表的所有原子结点数据域之和
int Sum(GList L) {
    int m,n;
    if(L == NULL)
        return 0;
    else {
        if(L->tag == 0)
            n = L->atom - '0';
        else
            n = Sum(L->ptr.hp);
        if(L->ptr.tp != NULL)
            m = Sum(L->ptr.tp);
        else
            m = 0;
    }
    return m + n;
}
