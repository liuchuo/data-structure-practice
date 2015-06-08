//
//  main.c
//  20150608-12
//
//  Created by 欣 陈 on 15/6/8.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//中缀表达式变为后缀表达式
/*  6+(7 - 1) * 3 + 10 / 2
 ((6 + ((7 - 1) * 3)) + (10 / 2))
 6 7  1 - 3 * + 10 2/+
 利用栈计算该后缀表达式的值*/
#include <stdio.h>
#include <string.h>
typedef char DataType;
#define MaxSize 50
#define StackSize 100
typedef struct{
    DataType stack[StackSize];
    int top;
}SeqStack;

typedef struct{
    float data[MaxSize];
    int top;
}OpStack;

void InitStack(SeqStack *S){
    S->top = 0;
}

int StackEmpty(SeqStack S){
    if(S.top == 0)
        return 1;
    else
        return 0;
}

int GetTop(SeqStack S,DataType *e){
    if(S.top <= 0){
        printf("栈已空~");
        return 0;
    }
    else{
        *e = S.stack[S.top - 1];
        return 1;
    }
}

int PushStack(SeqStack *S,DataType e){
    if(S->top >= StackSize){
        printf("栈已满~");
        return 0;
    }
    else{
        S->stack[S->top] = e;
        S->top++;
        return 1;
    }
}

int PopStack(SeqStack *S,DataType *e){
    if(S->top == 0){
        printf("栈已空不能出栈");
        return 0;
    }
    else{
        S->top--;
        *e = S->stack[S->top];
        return 1;
    }
}

int StackLength(SeqStack S){
    return S.top;
}

void ClearStack(SeqStack *S){
    S->top = 0;
}

void TranslateExpress(char s1[],char s2[]);
float ComputeExpress(char s[]);

int main(){
    char a[MaxSize],b[MaxSize];
    float f;
    printf("请输入一个算数表达式：\n");
    gets(a);
    printf("中缀表达式为%s\n",a);
    TranslateExpress(a,b);
    printf("后缀表达式为%s\n",b);
    f = ComputeExpress(b);
    printf("计算结果:%f\n",f);
    return 0;
}

float ComputeExpress(char a[]){
    OpStack S;
    int i = 0;
    int value;
    float x1,x2;
    float result;
    S.top = -1;
    while(a[i] != '\0'){
        if(a[i] != ' ' && a[i] >= '0' && a[i] <= '9'){
            value = 0;
            while(a[i] != ' '){
                value = 10 * value + a[i] - '0';
                i++;
            }
            S.top++;
            S.data[S.top] = value;
        }
        else{
            switch(a[i]){
                case '+':
                    x1 = S.data[S.top];
                    S.top--;
                    x2 = S.data[S.top];
                    S.top--;
                    result = x1 + x2;
                    S.top++;
                    S.data[S.top] = result;
                    break;
                case '-':
                    x1 = S.data[S.top];
                    S.top--;
                    x2 = S.data[S.top];
                    S.top--;
                    result = x2 - x1;
                    S.top++;
                    S.data[S.top] = result;
                    break;
                case '*':
                    x1 = S.data[S.top];
                    S.top--;
                    x2 = S.data[S.top];
                    S.top--;
                    result = x2 * x1;
                    S.top++;
                    S.data[S.top] = result;
                    break;
                case '/':
                    x1 = S.data[S.top];
                    S.top--;
                    x2 = S.data[S.top];
                    S.top--;
                    result = x2 / x1;
                    S.top++;
                    S.data[S.top] = result;
                    break;
            }
            i++;
        }
    }
    if(S.top != -1){
        result = S.data[S.top];
        S.top--;
        if(S.top == -1){
            return result;
        }
        else{
            printf("表达式错误");
            return -1;
        }
    }
    return 0;
}

void TranslateExpress(char str[],char exp[]){
    SeqStack S;
    char ch;
    DataType e;
    int i = 0;
    int j = 0;
    InitStack(&S);
    ch = str[i];
    i++;
    while(ch != '\0'){
        switch(ch){
            case '(' :
                PushStack(&S,ch);
                break;
            case ')':
                while(GetTop(S,&e) && e!= '('){
                    PopStack(&S,&e);
                    exp[j] = e;
                    j++;
                    exp[j] = ' ';
                    j++;
                }
                PopStack(&S,&e);
                break;
            case '+':
            case '-':
                while(!StackEmpty(S) && GetTop(S,&e) && e!='('){
                    PopStack(&S,&e);
                    exp[j] = e;
                    j++;
                    exp[j] = ' ';
                    j++;
                }
                PushStack(&S,ch);
                break;
            case '*':
            case '/':
                while((!StackEmpty(S) && GetTop(S,&e)) && (e == '/' || e == '*')){
                    PopStack(&S,&e);
                    exp[j] = e;
                    j++;
                    exp[j] = ' ';
                    j++;
                }
                PushStack(&S,ch);
                break;
            case ' ':
                break;
            default:
                while(ch >= '0' && ch <= '9'){
                    exp[j] = ch;
                    j++;
                    ch = str[i];
                    i++;
                }
                i--;
                exp[j] = ' ';
                j++;
        }
        ch = str[i];
        i++;
    }
    while(!StackEmpty(S)){
        PopStack(&S,&e);
        exp[j] = e;
        j++;
        exp[j] = ' ';
        j++;
    }
    exp[j] = '\0';
}
