//
//  main.c
//  20150822-1
//
//  Created by 欣 陈 on 15/8/22.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//编写一个算法，判断两个广义表是否相等（采用扩展线性链表存储结构）

#include <stdio.h>
#include <stdlib.h>
typedef char AtomType;
typedef enum{ATOM,LIST}ElemTag;
typedef struct {
    ElemTag tag;
    union {
        AtomType atom;
        struct GLNode *hp;
    }ptr;
    struct GLNode *tp;
}*GList,GLNode;

#define MaxLen 80
typedef struct{
    char str[MaxLen];
    int length;
}SeqString;

void CreateList(GList *L,SeqString S);
void DistributeString(SeqString *Str,SeqString *HeadStr);
void PrintGList(GList L);
int StrDelete(SeqString *S,int pos,int len);
int StrLength(SeqString S);
int StrCompare(SeqString S,SeqString T);
void StrCopy(SeqString *T,SeqString S);
void StrClear(SeqString *S);
void StrAssign(SeqString *S,char cstr[]);
int EqualGList(GList P,GList Q);
int main() {
    GList S,T,R;
    int flag;
    SeqString S1,T1,R1;
    StrAssign(&S1,"(a,(b,c,d),e,((f)))");
    StrAssign(&T1,"(a,(b,c,d),e,((f)))");
    StrAssign(&R1,"(a,(b,c),d,e,((f)))");
    CreateList(&S,S1);
    CreateList(&T,T1);
    CreateList(&R,R1);
    printf("\n广义表S为：\n");
    PrintGList(S);
    printf("\n广义表T为：\n");
    PrintGList(T);
    printf("\n广义表R为：\n");
    PrintGList(R);
    flag = EqualGList(S,T);
    if(flag == 1)
        printf("\nS和T相同。\n");
    else
        printf("\nS和T不同。\n");
    flag = EqualGList(R,T);
    if(flag == 1)
        printf("\nR和T相同。\n");
    else
        printf("\nR和T不同。\n");
    return 0;
}


int StrEmpty(SeqString S){
    if(S.length == 0)
        return 1;
    else
        return 0;
}
void StrAssign(SeqString *S,char cstr[]){
    int i = 0;
    for(i = 0;cstr[i] != '\0';i++){
        S->str[i] = cstr[i];
    }
    S->length = i;
}

int StrLength(SeqString S) {
    return S.length;
}

void StrCopy(SeqString *T,SeqString S) {
    int i;
    for(i = 0;i < S.length;i++){
        T->str[i] = S.str[i];
    }
    T->length = S.length;
}

int StrCompare(SeqString S,SeqString T) {
    int i;
    for(i = 0;i < S.length && i < T.length;i++)
        if(S.str[i] != T.str[i])
            return (S.str[i] - T.str[i]);
    return(S.length - T.length);
}

int StrDelete(SeqString *S,int pos,int len) {
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

void StrClear(SeqString *S) {
    S->length = 0;
}

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


//两个广义表相等的含义是指两个广义表具有相等的结构，对应的原子结点的数据域值也相等
int EqualGList(GList P,GList Q) {
    int flag = 1;
    if(P != NULL && Q != NULL) {
        if(P->tag == 0 && Q->tag != 0)
            flag = 0;
        if(P->tag != 0 && Q->tag == 0)
            flag = 0;
        if(P->tag == 0 && Q->tag == 0) {
            if(P->ptr.atom != Q->ptr.atom)
                flag = 0;
        }
        if(P->tag == 1 && Q->tag == 1)
            flag = EqualGList(P->ptr.hp,Q->ptr.hp);
        if(flag)
            flag = EqualGList(P->tp,Q->tp);
    }
    else {
        if(P == NULL && Q != NULL)
            flag = 0;
        if(P != NULL && Q == NULL)
            flag = 0;
    }
    return flag;
}

//创建广义表
void CreateList(GList *L,SeqString S) {
    SeqString Sub,HeadSub,Empty;
    GList p;
    StrAssign(&Empty,"()");
    if(!(*L = (GList)malloc(sizeof(GLNode))))
        exit(-1);
    if(!StrCompare(S,Empty)) {
        (*L)->tag = LIST;
        (*L)->ptr.hp = (*L)->tp = NULL;
    }
    else {
        if(StrLength(S) == 1) {
            (*L)->tag = ATOM;
            (*L)->ptr.atom = S.str[0];
            (*L)->tp = NULL;
        }
        else {
            (*L)->tag = LIST;
            (*L)->tp = NULL;
            SubString(&Sub,S,2,StrLength(S) - 2);
            DistributeString(&Sub,&HeadSub);//分离表头和表尾
            CreateList(&((*L)->ptr.hp),HeadSub); //递归调用生成广义表
            p = (*L)->ptr.hp;
            while(!StrEmpty(Sub)) { //当表尾不为空
                DistributeString(&Sub,&HeadSub);
                CreateLIst(&(p->tp),HeadSub);
                p = p->tp;
            }
        }
    }
}

//输出广义表的实现代码
void PrintGList(GList L) {
    if(L->tag == LIST) {
        printf("(");
        if(L->ptr.hp == NULL)
            printf(" ");
        else
            PrintGList(L->ptr.hp); //递归输出表头
        printf(")");
    }
    else
        printf("%c",L->ptr.atom);
    if(L->tp != NULL) {
        printf(",");
        PrintGList(L->tp);
    }
}
