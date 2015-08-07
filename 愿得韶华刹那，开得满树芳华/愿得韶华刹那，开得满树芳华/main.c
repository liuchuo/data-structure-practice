//
//  main.c
//  愿得韶华刹那，开得满树芳华
//
//  Created by 欣 陈 on 15/8/7.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//数组的存储结构、及其基本运算
#define MaxArraySize 3
typedef int DataType;
#include <stdarg.h>//stdarg.h 头文件定义了一个变量类型 va_list 和三个宏，这三个宏可用于在参数个数未知（即参数个数可变）时获取函数中的参数。可变参数的函数通在参数列表的末尾是使用省略号(,...)定义的
#include <stdlib.h>
typedef struct {
    DataType *base;
    int dim;    //数组的维数
    int *bounds; //数组的每一维之间的界限地址
    int *constants; //数组存储映像常量基地址
}Array;

int InitArray(Array *A,int dim,...) {
    int elemtotal = 1; //elemtotal是数组元素总数，初值为1
    int i;
    va_list ap;
    if(dim < 1 || dim > MaxArraySize)
        return 0;
    A->dim = dim;
    A->bounds = (int *)malloc(dim * sizeof(int));
    if(!A->bounds)
        exit(-1);
        va_start(ap,dim);
        for(i = 0;i < dim;i++){
            A->bounds[i] = va_arg(ap,int);
            if(A->bounds[i] < 0)
                return -1;
            elemtotal *= A->bounds[i];
        }
    va_end(ap);
    A->base = (DataType *)malloc(elemtotal * sizeof(DataType));
    if(!A->base)
        exit(-1);
        A->constants = (int *)malloc(dim * sizeof(int));
        if(!A->constants)
            exit(-1);
            A->constants[dim - 1] = 1;
            for(i = dim -2;i >= 0;--i)
                A->constants[i] = A->bounds[i + 1] * A->constants[i + 1];
                return 1;
}

/*
 1	void va_start(va_list ap, last_arg)
 这个宏初始化 ap 变量，它与 va_arg 和 va_end 宏是一起使用的。last_arg 是最后一个传递给函数的已知的固定参数，即省略号之前的参数。
 2	type va_arg(va_list ap, type)
 这个宏检索函数参数列表中类型为 type 的下一个参数。
 3	void va_end(va_list ap)
 这个宏允许使用了 va_start 宏的带有可变参数的函数返回。如果在从函数返回之前没有调用 va_end，则结果为未定义。
 */
