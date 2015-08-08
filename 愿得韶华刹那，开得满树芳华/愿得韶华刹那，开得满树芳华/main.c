//
//  main.c
//  愿得韶华刹那，开得满树芳华
//
//  Created by 欣 陈 on 15/8/7.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

///数组的存储结构、及其基本运算
#define MaxArraySize 3
typedef int DataType;
#include <stdarg.h>//stdarg.h 头文件定义了一个变量类型
//va_list 和三个宏，这三个宏可用于在参数个数未知（即参数个数可变）时获取函数中的参数。
//可变参数的函数通在参数列表的末尾是使用省略号(,...)定义的
#include <stdlib.h>
typedef struct {
    DataType *base;
    int dim;    //数组的维数
    int *bounds; //数组的每一维之间的界限地址
    int *constants; //数组存储映像常量基地址
}Array;

int InitArray(Array *A,int dim,...) {/*使用变长参数表传递参数，
                                      即用...表示形式参数，这种变长的形式参数主要用于参数不确定的情况，
                                      数组可能是二维的，也可能是三维的，参数的个数也就会不同，在这种情况下，
                                      就需要在被调用函数的形式参数列表中使用变长形式参数。在函数的形式参数表中，
                                      至少要有一个固定的参数在变长的形式参数表的前面。*/
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

//可变参数标准宏头文件
#include "stdarg.h"

//申明va_list数据类型变量ap，该变量访问变长参数列表中的参数。即定义了一个可变参数的指针ap
va_list ap;
//调用va_start(ap,dim)使ap指向dim的下一个参数，即第一个变长参数
va_start(ap,dim);
//然后调用va_arg(ap,int)返回可变参数的值
va_arg(ap,type);
//关闭本次对变长参数列表的访问。
va_end(ap);

//数组定位
int LocateArray(Array A,va_list ap,int *offset){
    int i,instand;
    *offset = 0;
    for(i = 0;i < A.dim;i++){
        instand = va_arg(ap,int);
        if(instand < 0 || instand >= A.bounds[i])
            return 0;
        *offset = A.constants[i] * instand;
    }
    return 1;
}

//数组的赋值
int AssignValue(Array A,DataType e,...){
    va_list ap;
    int offset;
    va_start(ap,e);
    if(LocateArray(A,ap,&offset) == 0)
        return 0;
    va_end(ap);
    *(A.base + offset) = e;
    return 1;
}

//返回数组中指定的元素。
int GetValue(DataType *e,Array A,...){
    va_list ap;
    int offset;
    va_start(ap,A);
    if(LocateArray(A,ap,&offset) == 0)
        return 0;
    va_end(ap);
    *e = *(A.base + offset);
    return 1;
}


//销毁数组
void DestroyArray(Array *A){
    if(A->base)
        free(A->base);
    if(A->bounds)
        free(A->bounds);
    if(A->constants)
        free(A->constants);
    A->base = A->bounds = A->constants = NULL;
    A->dim = 0;
}
