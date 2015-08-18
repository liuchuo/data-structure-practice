//
//  main.c
//  20150819-1
//
//  Created by 欣 陈 on 15/8/19.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//设广义表采用头尾链表存储结构，
//编写算法，建立一个广义表，病求出广义表的长度、深度和原子个数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char AtomType;

#define MaxLen 80
typedef struct{
    char str[MaxLen];
    int length;
}SeqString;

typedef enum{ATOM,LIST} ElemTag;

typedef struct {
    ElemTag tag;/*tag用于区分元素是原子还是子表*/
    union {
        AtomType atom;
        struct {
            struct GLNode *hp,*tp;/*hp指向表头，tp指向表尾*/
        }ptr;
    };
}*GList,GLNode;

void StrAssign(SeqString *S,char cstr[]){
    int i = 0;
    for(i = 0;cstr[i] != '\0';i++){
        S->str[i] = cstr[i];
    }
    S->length = i;
}

int StrEmpty(SeqString S){
    if(S.length == 0)
        return 1;
    else
        return 0;
}

int StrLength(SeqString S){
    return S.length;
}

void StrCopy(SeqString *T,SeqString S){
    int i;
    for(i = 0;i < S.length;i++){
        T->str[i] = S.str[i];
    }
    T->length = S.length;
}

int StrCompare(SeqString S,SeqString T){
    int i;
    for(i = 0;i < S.length && i < T.length;i++)
        if(S.str[i] != T.str[i])
            return (S.str[i] - T.str[i]);
    return(S.length - T.length);
}

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

void StrClear(SeqString *S){
    S->length = 0;
}



GLNode* GetHead(GList L){
    GLNode *p;
    if(!L){
        printf("该广义表是空表！");
        return NULL;
    }
    p = L->ptr.hp;
    if(!p)
        printf("该广义表的表头是空表");
    else if(p->tag == LIST)
        printf("该广义表的表头是非空的子表");
    else
        printf("该广义表的表头是原子");
    return p;
}

GLNode* GeTail(GList L){
    if(!L){
        printf("该广义表是空表！");
        return NULL;
    }
    return L->ptr.hp;//广义表不是空表，则表尾不可能是空表也不可能是原子
}

int GListLength(GList L){
    int length = 0;
    while(L){
        L = L->ptr.tp;
        length++;
    }
    return length;
}

void CopyList(GList *T,GList L) {
    if(!L)
        *T = NULL;
    else {
        *T = (GList)malloc(sizeof(GLNode));
        if(*T == NULL)
            exit(-1);
        (*T)->tag = L->tag;
        if(L->tag == ATOM)
            (*T)->atom = L->atom;
        else {
            CopyList(&((*T)->ptr.hp),L->ptr.hp);
            CopyList(&((*T)->ptr.tp),L->ptr.tp);
        }
    }
}

int GListDepth(GList L) {
    int max;
    int depth;
    GLNode *p;
    if(!L)
        return 1;
    if(L->tag == ATOM)
        return 0;
    for(max = 0,p = L;p;p = p->ptr.tp) {
        depth = GListDepth(p->ptr.hp);
        if(max < depth)
            max = depth;
    }
    return max + 1;
}


void CreateList(GList *L,SeqString S);
void DistributeString(SeqString *Str,SeqString *HeadStr);
void PrintGList(GList L);
int Sum3(GList L);
int GListAtomNum(GList L);
void StrPrint(SeqString S);
int main() {
    GList L,T;
    SeqString S;
    int depth,length;
    StrAssign(&S,"((a,b),(),(a,(b,c,d)),(a,e))");
    CreateList(&L,S);
    printf("广义表");
    PrintGList(L);
    length = GListLength(L);
    printf("\n广义表L的长度length = %2d\n",length);
    depth = GListLength(L);
    printf("广义表L的深度depth = %2d\n",depth);
    printf("广义表中等等原子个数:%2d\n",GListAtomNum(L));
    CopyList(&T,L);
    printf("由广义表L复制得到广义表T.\n广义表L的长度T的元素为:\n");
    PrintGList(T);
    length = GListLength(T);
    printf("\n广义表T的长度length = %2d\n",length);
    depth = GListDepth(T);
    printf("广义表T的深度是depth - %2d\n",depth);
    StrAssign(&S,"((3,4),S,((6,3)))");
    CreateList(&L,S);
    printf("广义表");
    StrPrint(S);
    GListAtomNum(L);
    printf("中的原子个数：%d\n",GListAtomNum(L));
    return 0;
}

int GListAtomNum(GList L) {
    if(L == NULL)
        return 0;
    if(L->tag == 0)
        return 1;
    else
        return GListAtomNum(L->ptr.hp) + GListAtomNum(L->ptr.tp);
}




//分离出表头和表尾 根据输入的字符串 通过找到串的第一个逗号，
//逗号之前的元素为表头，逗号之后的元素为表尾
void DistributeString(SeqString *Str,SeqString *HeadStr) {
    int len,i,k;
    SeqString Ch,Ch1,Ch2,Ch3;
    len = StrLength(*Str);
    StrAssign(&Ch1,",");
    StrAssign(&Ch2,"(");
    StrAssign(&Ch3,")");
    SubString(&Ch,*Str,1,1);
    for(i = 1,k = 0;(i <= len && StrCompare(Ch,Ch1)) || k != 0;i++) {
        SubString(&Ch,*Str,i,1);
        if(!StrCompare(Ch,Ch2))
            k++;
        else if(!StrCompare(Ch,Ch3))
            k--;
    }
    if(i <= len) {
        SubString(HeadStr,*Str,1,i - 2);
        SubString(Str,*Str,i,len - i + 1);
    }
    else {
        StrCopy(HeadStr,*Str);
        StrClear(Str);
    }
}

//创建广义表的算法
void CreateList(GList *L,SeqString S) {
    SeqString Sub,HeadSub,Empty;
    GList p,q;
    StrAssign(&Empty,"()");
    if(!StrCompare(S,Empty))
        *L = NULL;
    else {
        if(!(*L = (GList)malloc(sizeof(GLNode))))
            exit(-1);
        if(StrLength(S) == 1) {
            (*L)->tag = ATOM;
            (*L)->atom = S.str[0];
        }
        else {
            (*L)->tag = LIST;
            p = *L;
            SubString(&Sub,S,2,StrLength(S) - 2);
            do {
                DistributeString(&Sub,&HeadSub);
                CreateList(&(p->ptr.hp),HeadSub);
                q = p;
                if(!StrEmpty(Sub)) {
                    if(!(p = (GLNode *)malloc(sizeof(GLNode))))
                        exit(-1);
                    p->tag = LIST;
                    q->ptr.tp = p;
                }
            }while(!StrEmpty(Sub));
            q->ptr.tp = NULL;
        }
    }
}

//输出广义表
void PrintGList(GList L) {
    if(L) {
        if(L->tag == ATOM)
            printf("%c ",L->atom);
        else {
            PrintGList(L->ptr.hp);
            PrintGList(L->ptr.tp);
        }
    }
}