//
//  main.c
//  20150712-2
//
//  Created by 欣 陈 on 15/7/12.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//串的顺序存储结构
#include <stdio.h>
#define MaxLen 80
typedef struct{
    char str[MaxLen];
    int length;
}SeqString;

//串的赋值
void StrAssign(SeqString *S,char cstr[]){
    int i = 0;
    for(i = 0;cstr[i] != '\0';i++){
        S->str[i] = cstr[i];
    }
    S->length = i;
}

//判断串是否为空
int StrEmpty(SeqString S){
    if(S.length == 0)
        return 1;
    else
        return 0;
}

//求串的长度
int StrLength(SeqString S){
    return S.length;
}

//串的复制
void StrCopy(SeqString *T,SeqString S){
    int i;
    for(i = 0;i < S.length;i++){
        T->str[i] = S.str[i];
    }
    T->length = S.length;
}

//比较两个串的大小
int StrCompare(SeqString S,SeqString T){
    int i;
    for(i = 0;i < S.length && i < T.length;i++)
        if(S.str[i] != T.str[i])
            return (S.str[i] - T.str[i]);
    return(S.length - T.length);
}

//串的插入操作
int StrInsert(SeqString *S,int pos,SeqString T){
    int i;
    if(pos < 0 || pos - 1 > S->length){
        printf("插入位置不正确！");
        return 0;
    }
    if(S->length + T.length <= MaxLen){
        for(i = S->length + T.length - 1;i >= pos - 1 + T.length;i--){
            S->str[i] = S->str[i - T.length];
        }
        for(i = 0;i < T.length;i++){
            S->str[pos - 1 + i] = T.str[i];
        }
        S->length = S->length + T.length;
        return 1;
    }
    else
        if(pos + T.length <= MaxLen){
            for(i = MaxLen - 1;i > T.length + pos - 1;i--){
                S->str[i] = S->str[i - T.length];
            }
            for(i = 0;i < T.length;i++){
                S->str[pos - 1 + i] = T.str[i];
            }
            S->length = MaxLen;
            return 0;
        }
        else{
            for(i = 0;i < T.length;i++){
                S->str[pos - 1 + i] = T.str[i];
            }
            S->length = MaxLen;
            return 0;
        }
}

//删除串S中pos开始的len个字符。删除成功返回1，失败返回0
int StrDelete(SeqString *S,int pos,int len){
    int i;
    if(pos < 0 || len < 0 || pos + len - 1 > S->length){
        printf("删除位置不正确，参数len不合法");
        return 0;
    }
    else{
        for(i = pos + len;i <= S->length - 1;i--){
            S->str[i - len] = S->str[i];
        }
        S->length = S->length - len;
        return 1;
    }
}

//将串S连接再串T的末尾
int StrConcat(SeqString *T,SeqString S){
    int i,flag;
    if(T->length + S.length <= MaxLen){
        for(i = T->length;i < T->length + S.length;i++){
            T->str[i] = S.str[i - T->length];
        }
        T->length = T->length + S.length;
        flag = 1;
    }
    else
        if(T->length + S.length > MaxLen){
            for(i = T->length;i < MaxLen;i++){
                T->str[i] = S.str[i - T->length];
            }
            T->length = MaxLen;
            flag = 0;
        }
    return flag;
}

//清空串操作
void StrClear(SeqString *S){
    S->length = 0;
}
