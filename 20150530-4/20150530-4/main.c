//
//  main.c
//  20150530-4
//
//  Created by 欣 陈 on 15/5/30.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//链表应用举例：一元多项式的相加，依次输入两个多项式，编写程序求两个多项式的和
//创建多项式
#include <stdio.h>
#include <stdlib.h>
struct node{
    int exp;
    float coef;
    struct node *next;
};
typedef struct node ListNode;

ListNode *Createpoly(){
    ListNode *h = NULL,*p,*q = NULL;
    int e;
    float c;
    printf("请输入系数和指数：");
    scanf("%f,%d",&c,&e);
    while(c != 0 || e != 0){
        p = (ListNode *)malloc(sizeof(ListNode));
        p->coef = c;
        p->exp = e;
        p->next = NULL;
        if(h == NULL){
            h = p;
        }
        else{
            q->next = p;
        }
        q = p;
        printf("请输入系数和指数：");
        scanf("%f,%d",&c,&e);
    }
    return h;
}

//输出多项式
void disppoly(ListNode *h){
    ListNode *p;
    p = h;
    while(p != NULL){
        if(p->exp == 0){
            printf("%f",p->coef);
        }
        else{
            printf("%fx^%d",p->coef,p->exp);
        }
        p = p->next;
        if(p != NULL){
            printf("+");
        }
    }
    printf("\n");
}

//求两个多项式的和~
ListNode *addpoly(ListNode *h1,ListNode *h2){
    ListNode *s1,*s2,*s = NULL;
    ListNode *r = NULL,*p;
    float c;
    int e;
    s1 = h1;
    s2 = h2;
    while((s1 != NULL) && (s2 != NULL)){
        if(s1->exp == s2->exp){
            c = s1->coef+s2->coef;
            e = s1->exp;
            s1 = s1->next;
            s2 = s2->next;
        }
        else if(s1->exp > s2->exp){
                c = s1->coef;
                e = s1->exp;
                s1 = s1->next;
            }
            else{
                c = s2->coef;
                e = s2->exp;
                s2 = s2->next;
            }
        if(c != 0){
            p = (ListNode *)malloc(sizeof(ListNode));
            p->coef = c;
            p->exp = e;
            p->next = NULL;
            if(s == NULL){
                s = p;
            }
            else{
                r->next = p;
            }
            r = p;
        }
    }
    while(s1 != NULL){
        c = s1->coef;
        e = s1->exp;
        s1 = s1->next;
        if(c != 0){
            p = (ListNode *)malloc(sizeof(ListNode));
            p->coef = c;
            p->exp = e;
            p->next = NULL;
            if(s == NULL){
                s = p;
            }
            else{
                r->next = p;
            }
            r = p;
        }
    }
    while(s2 != NULL){
        c = s2->coef;
        e = s2->exp;
        s2 = s2->next;
        if(c != 0){
            p = (ListNode *)malloc(sizeof(ListNode));
            p->coef = c;
            p->exp = e;
            p->next = NULL;
            if(s == NULL){
                s = p;
            }
            else{
                r->next = p;
            }
            r = p;
        }
    }
    return s;
}

//释放链表所占用的内存单元
void deletepoly(ListNode *h){
    ListNode *p,*r;
    r = h;
    while(r != NULL){
        p = r->next;
        free(r);
        r = p;
    }
}

//主函数
int main(){
    ListNode *head1,*head2,*head;
    printf("创建第一个多项式：\n");
    head1 = Createpoly();
    printf("创建第二个多项式：\n");
    head2 = Createpoly();
    printf("将两个多项式相加：\n");
    head = addpoly(head1,head2);
    disppoly(head);
    deletepoly(head);
    return 0;
}
