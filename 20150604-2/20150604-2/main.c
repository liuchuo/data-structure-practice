//
//  main.c
//  20150604-2
//
//  Created by 欣 陈 on 15/6/4.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//一元多项式的表示与相乘
//a降幂排列，b升幂排列，计算两个结点的指数域相加，判断和k（指数范围）是否相等，相等就插入c中
//最后重新将链表b逆置
#include <stdio.h>
#include <stdlib.h>
typedef struct polyn{
    float coef;
    int expn;
    struct polyn *next;
}PolyNode,*PLinkList;

PLinkList CreatePolyn();
PolyNode *MultiplyPolyn(PLinkList A,PLinkList B);
PolyNode *Reverse(PLinkList head);

void OutPut(PLinkList head){
    PolyNode *p;
    p = head->next;
    while(p){
        printf("%8.1f",p->coef);
        if(p->expn){
            printf("x^%d",p->expn);
        }
        if(p->next && p->next->coef > 0){
            printf("+");
        }
        p = p->next;
    }
}

int main(){
    PLinkList A,B,C;
    A = CreatePolyn();
    printf("A(x) = ");
    OutPut(A);
    printf("\n");
    B = CreatePolyn();
    printf("B(x) = ");
    OutPut(B);
    printf("\n");
    C = MultiplyPolyn(A,B);
    printf("C(x) = A(x)*B(x) =");
    OutPut(C);
    printf("\n");
    return 0;
}

PLinkList CreatePolyn(){
    PolyNode *p,*q,*s;
    PolyNode *head = NULL;
    int expn2;
    float coef2;
    head = (PLinkList)malloc(sizeof(PolyNode));
    if(!head){
        return NULL;
    }
    head->coef = 0;
    head->expn = 0;
    head->next = NULL;
    do{
        printf("输入系数coef(系数和指数都为0结束):");
        scanf("%f",&coef2);
        printf("输入指数exp(系数和指数都为0结束):");
        scanf("%d",&expn2);
        if((long)coef2 == 0 && expn2 == 0){
            break;
        }
        s = (PolyNode *)malloc(sizeof(PolyNode));
        if(!s){
            return NULL;
        }
        s->expn = expn2;
        s->coef = coef2;
        q = head->next;
        p = head;
        while(q && expn2 < q->expn){
            p = q;
            q = q->next;
        }
        if(q == NULL || expn2 > q->expn){
            p->next = s;
            s->next = q;
        }
        else
            q->coef += coef2;
    }while(1);
    return head;
}

PolyNode *MultiplyPolyn(PLinkList A,PLinkList B){
    PolyNode *pa,*pb,*pc,*u,*head;
    int k,maxExp;
    float coef;
    head = (PLinkList)malloc(sizeof(PolyNode));
    if(!head){
        return NULL;
    }
    head->coef = 0.0;
    head->expn = 0;
    head->next = NULL;
    if(A->next != NULL && B->next != NULL){
        maxExp = A->next->expn + B->next->expn;
    }
    else{
        return head;
    }
    pc = head;
    B = Reverse(B);
    for(k = maxExp;k >= 0;k--){
        pa = A->next;
        while(pa != NULL && pa->expn > k){
            pa = pa->next;
        }
        pb = B->next;
        while(pb != NULL && pa != NULL && (pa->expn + pb->expn) < k){
            pb = pb->next;
        }
        coef = 0.0;
        while(pa != NULL && pb != NULL){
            if(pa->expn + pb->expn == k){
                coef += pa->coef * pb->coef;
                pa = pa->next;
                pb = pb->next;
            }
            else if(pa->expn + pb->expn > k){
                pa = pa->next;
            }
            else{
                pb = pb->next;
            }
        }
        if(coef != 0.0){
            u = (PolyNode *)malloc(sizeof(PolyNode));
            u ->coef = coef;
            u->expn = k;
            u->next = pc->next;
            pc->next = u;
            pc = u;
        }
    }
    B = Reverse(B);
    return head;
}

PolyNode *Reverse(PLinkList head){
    PolyNode *q,*r,*p=NULL;
    q = head->next;
    while(q){
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head->next = p;
    return head;
}
