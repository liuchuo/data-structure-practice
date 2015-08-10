//
//  main.c
//  20150810-1
//
//  Created by 欣 陈 on 15/8/10.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//利用数组的基本运算对数组进行初始化，然后输出数组的值
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
typedef int DataType;
#define MaxArraySize 3

typedef struct{
    DataType *base;
    int dim;
    int *bounds;
    int *constants;
}Array;

int InitArray(Array *A,int dim,...){
    int elemtotal = 1;
    int i;
    va_list ap;
    if(dim < 1 || dim > MaxArraySize)
        return 0;
    A->dim = dim;
    A->bounds = (int *)malloc(dim * sizeof (int));
    if(!A->bounds)
        exit(-1);
    va_start(ap,dim);
    for(i = 0;i < dim;++i){
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
    for(i = dim - 2;i >= 0;--i)
        A->constants[i] = A->bounds[i + 1] * A->constants[i + 1];
    return 1;
}

int LocateArray(Array A,va_list ap,int *offset){
    int i,instand;
    *offset = 0;
    for(i = 0;i < A.dim;i++){
        instand = va_arg(ap,int);
        if(instand < 0 || instand >= A.bounds[i])
            return 0;
        *offset += A.constants[i] * instand;
    }
    return 1;
}

int AssignValue(Array A,DataType e,...){
    va_list ap;
    int offset;
    va_start(ap,e);
    if(LocateArray(A,ap,&offset) == 0)
        return 0;
    va_end(ap);
    *(A.base + offset) = 0;
    return 1;
}

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


int main(){
    Array A;
    int i,j,k;
    int dim = 3;
    int bound1 = 5;
    int bound2 = 3;
    int bound3 = 2;
    DataType e;
    InitArray(&A,dim,bound1,bound2,bound3);
    printf("数组A的各维的长度是：");
    for(i = 0;i < dim;i++)
        printf("%3d",A.bounds[i]);
    printf("数组A的常量基址是：");
    for(i = 0;i < dim;i++)
        printf("%3d",A.constants[i]);
    printf("\n%d * %d * %d的数组元素如下：\n",bound1,bound2,bound3);
    for(i = 0;i < bound1;i++){
        for(j = 0;j < bound2;j++){
            for(k = 0;k < bound3;k++){
                AssignValue(A,100 * i + 10 * j + k,i,j,k);
                GetValue(&e,A,i,j,k);
                printf("A[%d][%d][%d] = %3d\t",i,j,k,e);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("按照数组的线性序列输出元素，即利用基地址输出元素：\n");
    for(i = 0;i < bound1 * bound2 * bound3;i++){
        printf("第%d个元素 = %3d\t",i + 1,A.base[i]);
        if((i + 1) % bound2 == 0)
            printf("\n");
    }
    DestroyArray(&A);
    return 0;
}
