//约瑟夫问题。有n个小朋友，编号分别为1，2，...，n，按序号围城一个圆圈
//他们按顺时针方向从编号为k的人由1开始报数，报数为m的人出列，它的下一个人重新从1开始报数
//数到m的人出列，照这样重复下去，直到所有人都出列，编写一个算法，输入n、k和m，按照出列顺序输出序号
#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct Node{
    DataType data;
    struct Node *prior;
    struct Node *next;
}DListNode,*DLinkList;
DLinkList CreateDCList(int n);
void Josephus(DLinkList head,int n,int m,int k);

int main(){
    DLinkList h;
    int n,k,m;
    printf("输入环中人的个数n=");
    scanf("%d",&n);
    printf("输入开始报数的人的编号k=");
    scanf("%d",&k);
    printf("报数为m的人出列m=");
    scanf("%d",&m);
    h = CreateDCList(n);
    Josephus(h,n,m,k);
    return 0;
}

void Josephus(DLinkList head,int n,int m,int k){
    DListNode *p,*q;
    int i;
    p = head;
    q = NULL;
    for(i = 1;i < k;i++){
        q = p;
        p = p->next;
    }
    while(p->next != p){
        for(i = 1;i < m;i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        p->next->prior = q;
        printf("%3d",p->data);
        free(p);
        p = q->next;
    }
    printf("%4d",p->data);
}

DLinkList CreateDCList(int n){
    DLinkList head;
    DListNode *s,*q;
    head = NULL;
    q = NULL;
    int i;
    for(i = 1;i <= n;i++){
        s = (DListNode *)malloc(sizeof(DListNode));
        s->data = i;
        s->next = NULL;
        if(head == NULL){
            head = s;
            s->next = head;
            s->prior = head;
        }
        else{
            s->next = q->next;
            q->next = s;
            s->prior = q;
            head->prior = s;
        }
        q = s;
    }
    return head;
}
