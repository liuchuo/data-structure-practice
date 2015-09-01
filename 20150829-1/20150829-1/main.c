//编写算法，创建二叉树并将其线索化，要求查找该结点的直接前驱和直接后继
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef char DataType;
typedef enum {Link,Thread}PointerTag;
typedef struct Node {
    DataType data;
    struct Node *lchild,*rchild;
    PointerTag ltag,rtag;
}BiThrNode;
typedef BiThrNode *BiThrTree;

void CreateBitTree2(BiThrTree *T,char str[]);
void InThreading(BiThrTree p);
int InOrderThreading(BiThrTree *Thrt,BiThrTree T);
int InOrderTraverse(BiThrTree T,int (*visit)(BiThrTree e));
int Print(BiThrTree T);
BiThrNode *FindPoint(BiThrTree T,DataType e);
BiThrNode *InOrderPre(BiThrNode *p);
BiThrNode *InOrderPost(BiThrNode *p);
BiThrTree pre;
void DestroyBitTree(BiThrTree *T);
int main() {
    DataType ch;
    BiThrTree T,Thrt;
    BiThrNode *p,*pre,*post;
    CreateBitTree2(&T,"(A(B(D,E(H)),C(F(,I),G)))");
    printf("输出线索二叉树的结点、前驱及后继信息：\n");
    InOrderThreading(&Thrt,T);
    printf("序列  前驱标志  结点  后继标志\n");
    InOrderTraverse(Thrt,Print);
    printf("请输入要查找哪个结点的前驱和后继：");
    ch = getchar();
    p = FindPoint(Thrt,ch);
    pre = InOrderPre(p);
    printf("元素%c的中序直接前驱元素是：%c\n",ch,pre->data);
    post = InOrderPost(p);
    printf("元素%c的中序直接后继元素是：%c\n",ch,post->data);
    DestroyBitTree(&Thrt);
    return 0;
}

int Print(BiThrTree T) {
    static int k = 1;
    printf("%2d\t%s\t %2c\t %s\t\n",k++,T->ltag == 0 ? "Link" : "Thread",T->data,T->rtag == 1 ? "Thread" : "Link");
    return 1;
}

void DestroyBitTree(BiThrTree *T) {
    if(*T) {
        if((*T)->lchild)
            DestroyBitTree(&((*T))->lchild);
        if((*T)->rchild)
            DestroyBitTree(&((*T))->rchild);
        free(*T);
        *T = NULL;
    }
}

void CreateBiTree2(BiThrTree *T,char str[]) {
    char ch;
    BiThrTree stack[MaxSize];
    int top = -1;
    int flag = 0,k;
    BiThrNode *p;
    p = NULL;
    *T = NULL;
    k = 0;
    ch = str[k];
    while(ch != '\0') {
        switch(ch) {
            case '(' :
                stack[++top] = p;
                flag = 1;
                break;
            case ')' :
                top--;
                break;
            case ',' :
                flag = 2;
                break;
            default :
                p = (BiThrTree)malloc(sizeof(BiThrNode));
                p->data = ch;
                p->lchild = NULL;
                p->rchild = NULL;
                if(*T == NULL)
                    *T = p;
                else {
                    switch(flag) {
                        case 1 :
                            stack[top]->lchild = p;
                            break;
                        case 2 :
                            stack[top]->rchild = p;
                            break;
                    }
                    if(stack[top]->lchild)
                        stack[top]->ltag = Link;
                    if(stack[top]->rchild)
                        stack[top]->rtag = Link;
                }
        }
        ch = str[++k];
    }
}

BiThrNode *FindPoint(BiThrTree T,DataType e) {
    BiThrTree p;
    p = T->lchild;
    while(p != T) {
        while(p->ltag == Link)
            p = p->lchild;
        if(p->data == e)
            return p;
        while(p->rtag == Thread && p->rchild != T) {
            p = p->rchild;
            if(p->data == e)
                return p;
        }
        p = p->rchild;
    }
    return NULL;
}
