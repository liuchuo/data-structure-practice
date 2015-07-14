//
//  main.c
//  20150713-1
//
//  Created by 欣 陈 on 15/7/13.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//顺序串应用举例
//要求编写一个删除字符串“abcdeabdbcdaaabdecdf”中所有子串“abd”的程序
#include <stdio.h>
#include <string.h>
#define MaxLen 60
typedef struct{
    char str[MaxLen];
    int length;
}SeqString;


int Index(SeqString *S1,SeqString *S2){
    int i = 0,j,k;
    while(i < S1->length){
        j = 0;
        if(S1->str[i] == S2->str[j]){
            k = i + 1;
            j++;
            while(k < S1->length && j < S2->length
                  && S1->str[k] == S2->str[j]){
                k++;
                j++;
            }
            if(j == S2->length)
                break;
            else
                i++;
        }
        else
            i++;
    }
    if(i >= S1->length)
        return -1;
    else
        return i + 1;
}

int DelSubString(SeqString *S,int pos,int n){
    int i;
    if(n + pos > S->length){
        return 0;
    }
    for(i = pos - 1 + n;i < S->length;i++){
        S->str[i - n] = S->str[i];
    }
    S->length = S->length - n;
    S->str[S->length] = '\0';
    return 1;
}

void CreateString(SeqString *S,char str[]){
    strcpy(S->str,str);
    S->length = strlen(str);
}

int StrLength(SeqString *S){
    return S->length;
}

void DelAllString(SeqString *S1,SeqString *S2){
    int n;
    n = Index(S1,S2);
    while(n >= 0){
        DelSubString(S1,n,StrLength(S2));
        n = Index(S1,S2);
    }
}

void StrPrint(SeqString S){
    int i;
    for(i = 0;i < S.length;i++){
        printf("%c",S.str[i]);
    }
    printf("\n");
}

int main(){
    SeqString S1,S2;
    char str[MaxLen];
    printf("字符串：");
    gets(str);
    CreateString(&S1,str);
    printf("子串：");
    gets(str);
    CreateString(&S2,str);
    DelAllString(&S1,&S2);
    printf("删除所有子串后的字符串：");
    StrPrint(S1);
    return 0;
}

