
//假设一个字符序列为{a,b,c,d},对应的权重为{2,3,6,8},构造一颗哈夫曼树，然后输出相应的哈夫曼编码
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define infinity 65535
typedef struct {
    unsigned int weight;
    unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;

typedef char **HuffmanCode;

int Min(HuffmanTree t,int n);
void Select(HuffmanTree *t,int n,int *s1,int *s2);
void HuffmanCoding(HuffmanTree *HT,HuffmanCode *HC,int *w,int n);

//查找权值最小和次小的两个结点
int Min(HuffmanTree t,int n) {
    int i,flag;
    flag = 0;
    int f = infinity;
    for(i = 1;i <= n;i++) {
        if(t[i].weight < f && t[i].parent == 0) {
            f = t[i].weight;
            flag = i;
        }
    }
    t[flag].parent = 1;
    return flag;
}

//在n个结点中选择两个权值最小的结点序号，其中s1最小，s2次小
void Select(HuffmanTree *t,int n,int *s1,int *s2) {
    *s1 = Min(*t,n);
    *s2 = Min(*t,n);
}

//从根节点到叶子结点求哈夫曼编码
void HuffmanCoding(HuffmanTree *HT,HuffmanCode *HC,int *w,int n) {
    int s1,s2,i,m;
    unsigned int r,cdlen;
    char *cd;
    HuffmanTree p;
    if(n <= 1)
        return;
    m = 2*n - 1;
    *HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
    for(p = *HT + 1,i = 1;i <= n;i++,p++,w++) {
        (*p).weight = *w;
        (*p).parent = 0;
        (*p).lchild = 0;
        (*p).rchild = 0;
    }
    for(;i <= m;i++,p++) {
        (*p).parent = 0;
    }
    for(i = n + 1;i <= m;i++) {
        Select(HT,i - 1,&s1,&s2);
        (*HT)[s1].parent = (*HT)[s2].parent = i;
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }
    
    /*从根节点到叶子结点求哈夫曼编码并保存在HC中*/
    *HC = (HuffmanCode)malloc((n + 1) * sizeof(char*));
    cd = (char *)malloc(n * sizeof(char));
    r = m;
    cdlen = 0;
    for(i = 1;i <= m;i++) {
        (*HT)[i].weight = 0;
    }
    while(r) {
        if((*HT)[r].weight == 0) {
            (*HT)[r].weight = 1;
            if((*HT)[r].lchild != 0){
                r = (*HT)[r].lchild;
                cd[cdlen++] = '0';
            }
            else if((*HT)[r].rchild == 0) {
                (*HC)[r] = (char *)malloc((cdlen + 1) * sizeof(char));
                cd[cdlen] = '\0';
                strcpy((*HC)[r],cd);
            }
        }
        else if((*HT)[r].weight == 1) {
            (*HT)[r].weight = 2;
            if((*HT)[r].rchild != 0) {
                r = (*HT)[r].rchild;
                cd[cdlen++] = '1';
            }
        }
        else {
            r = (*HT)[r].parent;
            --cdlen;
        }
    }
    free(cd);
}

int main() {
    HuffmanTree HT;
    HuffmanCode HC;
    int *w,n,i;
    printf("请输入叶子结点的个数:");
    scanf("%d",&n);
    w = (int *)malloc(n * sizeof(int));
    for(i = 0;i < n;i++) {
        printf("请输入第%d个结点的权值：",i + 1);
        scanf("%d",w + i);
    }
    HuffmanCoding(&HT,&HC,w,n);
    for(i = 1;i <= n;i++) {
        printf("哈夫曼编码：");
        puts(HC[i]);
    }
    for(i = 1;i < n;i++) {
        free(HC[i]);
    }
    free(HC);
    free(HT);
    return 0;
}


