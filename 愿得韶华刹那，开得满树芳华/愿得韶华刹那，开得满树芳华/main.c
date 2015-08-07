//
//  main.c
//  愿得韶华刹那，开得满树芳华
//
//  Created by 欣 陈 on 15/8/7.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//数组的存储结构、及其基本运算
#define MaxArraySize 3

#include <stdarg.h>
#include <stdlib.h>
typedef struct {
    DataType *base;
    int dim;    //数组的维数
    int *bounds; //数组的每一维之间的界限地址
    int *constants; //数组存储映像常量基地址
}Array;

int InitArray(Array *A,int dim) {
    int elemtotal = 1; //elemtotal是数组元素总数，初值为1
    int i;
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
