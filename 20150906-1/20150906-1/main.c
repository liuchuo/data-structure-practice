//编写算法，已知先序序列(E,B,A,C,F,H,G,I,K,J)和中序序列(A,B,C,D,E,F,G,H,I,J,K),
//中序序列(A,B,C,D,E,F,G,H,I,J,K)和后续序列(A,C,D,B,G,J,K,I,H,F,E),构造一颗二叉树
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 100
typedef struct Node {
    char data;
    struct Node *lchild,*rchild;
}BitNode,*BiTree;
void CreateBiTree1(BiTree *T,char *pre,char *in,int len);
void CreateBiTree2(BiTree *T,char *in,char *post,int len);
void Visit(BiTree T,BiTree pre,char e,int i);
void PrintLevel(BiTree T);
void PrintTLR(BiTree T);
void PrintLRT(BiTree T);

int main() {
    BiTree T;
    BiTree ptr = NULL;
    char ch;
    int len;
    char pre[MaxSize],in[MaxSize],post[MaxSize];
    T = NULL;
    printf("由先序序列和中序序列构造二叉树：\n");
    printf("请你输入先序的字符串序列：");
    gets(pre);
    printf("请你输入中序的字符串序列：");
    gets(in);
    len = (int)strlen(pre);
    CreateBiTree1(&T,pre,in,len);
    printf("你建立的二叉树后序遍历结果是：\n");
    PrintLRT(T);
    printf("\n你建立的二叉树层次遍历结果是：\n");
    PrintLevel(T);
    printf("\n");
    printf("请输入你要访问的结点:");
    ch = getchar();
    getchar();
    Visit(T,ptr,ch,1);
    printf("由中序和后序序列构造二叉树：\n");
    printf("请你输入中序的字符串序列：");
    gets(in);
    printf("请你输入后序的字符串序列：");
    gets(post);
    len = (int)strlen(post);
    CreateBiTree2(&T,in,post,len);
    printf("你建立的二叉树先序遍历结果是：\n");
    PrintTLR(T);
    printf("\n你建立的二叉树层次遍历结果是：\n");
    PrintLevel(T);
    printf("\n");
    printf("请输入你要访问的结点：");
    ch = getchar();
    getchar();
    Visit(T,ptr,ch,1);
    return 0;
}

void PrintLevel(BiTree T) {
    BiTree Queue[MaxSize];
    int front,rear;
    if(T == NULL)
        return;
    front = -1;
    rear = 0;
    Queue[rear] = T;
    while(front != rear) {
        front++;
        printf("%4c",Queue[front]->data);
        if(Queue[front]->lchild != NULL) {
            rear++;
            Queue[rear] = Queue[front]->lchild;
        }
        if(Queue[front]->rchild != NULL) {
            rear++;
            Queue[rear] = Queue[front]->rchild;
        }
    }
}

void PrintTLR(BiTree T) {
    if(T != NULL) {
        printf("%4c",T->data);
        PrintTLR(T->lchild);
        PrintTLR(T->rchild);
    }
}

void PrintLRT(BiTree T) {
    if(T != NULL) {
        PrintLRT(T->lchild);
        PrintLRT(T->rchild);
        printf("%4c",T->data);
    }
}

void Visit(BiTree T,BiTree pre,char e,int i) {
    if(T == NULL && pre == NULL) {
        printf("\n尚未建立二叉树，先建立再进行访问！\n");
        return;
    }
    if(T == NULL)
        return;
    else if(T->data == e) {
        if(pre != NULL) {
            printf("%2c的双亲结点是：%2c\n",e,pre->data);
            printf("%2c结点在%2d层上\n",e,i);
        }
        else
            printf("%2c位于第1层，无双亲结点！\n",e);
    }
    else {
        Visit(T->lchild,T,e,i+1);
        Visit(T->rchild,T,e,i+1);
    }
}

void CreateBiTree1(BiTree *T,char *pre,char *in,int len) {
    int k;
    char *temp;
    if(len <= 0) {
        *T = NULL;
        return;
    }
    *T = (BitNode *)malloc(sizeof(BitNode));
    (*T)->data = *pre;
    for(temp = in;temp < in + len;temp++)
        if(*pre == *temp)
            break;
    k = (int)(temp - in);
    CreateBiTree1(&((*T)->lchild),pre + 1,in,k);
    CreateBiTree1(&((*T)->rchild),pre + 1 + k,temp + 1,len - 1 - k);
}

void CreateBiTree2(BiTree *T,char *in,char *post,int len) {
    int k;
    char *temp;
    if(len <= 0){
        *T = NULL;
        return;
    }
    for(temp = in;temp < in + len;temp++)
        if(*(post + len - 1) == *temp) {
            k =(int)(temp - in);
            (*T) = (BitNode *)malloc(sizeof(BitNode));
            (*T)->data = *temp;
            break;
        }
    CreateBiTree2(&((*T)->lchild),in,post,k);
    CreateBiTree2(&((*T)->rchild),in + k + 1,post + k,len - k - 1);
}