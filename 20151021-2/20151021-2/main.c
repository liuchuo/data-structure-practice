//
//  main.c
//  20151021-2
//
//  Created by 欣 陈 on 15/10/21.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//B-树
#define m 4
typedef struct BTNode {
    int keynum;
    struct BTNode *parent;
    keyType data[m + 1];
    struct BTNode *ptr[m + 1];
}BTNode,*BTree;

//B-树的查找操作
typedef struct {
    BTNode *pt;
    int pos;
    int flag;
}result;

result BTreeSearch(BTree T,keyType k) {
    BTree p = T,q = NULL;
    int i = 0;
    int found = 0;
    result r;
    while(p && found) {
        i = Search(p,k);
        if(i > 0 && p->data[i].key == k.key)
            found = 1;
        else {
            q = p;
            p = p->ptr[i];
        }
    }
    if(found) {
        r.pt = p;
        r.flag = 1;
        r.pos = i;
    }
    else {
        r.pt = q;
        r.flag = 0;
        r.pos = i;
    }
    return r;
}
int Search(BTree T,KeyType k) {
    int i = 1;
    int n = T->keynum;
    while(i <= n && T->data[i].key <= k.key)
        i++;
    return i - 1;
}

//B-树的插入操作
void BTreeInsert(BTree *T,DataType k,BTree p,int i) {
    BTree ap = NULL,newroot;
    int finished = 0;
    int s,i;
    DataType rx;
    if(*T == NULL) {
        *T = (BTree)malloc(sizeof(BTNode));
        (*T)->keynum = 1;
        (*T)->parent = NULL;
        (*T)->data[1] = k;
        (*T)->ptr[0] = NULL;
        (*T)->ptr[1] = NULL;
    }
    else {
        rx = k;
        while(p && !finished) {
            Insert(&p,i,rx,ap);
            if(p->keynum < m)
                finished = 1;
            else {
                s = (m + 1) / 2;
                split(&p,&ap);
                rx = p->data[s];
                p = p->parent;
                if(p) {
                    i = Search(p,rx);
                }
            }
        }
        if(!finished) {
            nuwroot = (BTree)malloc(sizeof(BTNode));
            newroot->keynum = 1;
            newroot->data[1] = rx;
            newroot->ptr[0] = *T;
            newroot->ptr[1] = ap;
            *T = newroot;
        }
    }
}
void Insert(BTree *p,int i,DataType k,BTree ap) {
    int j;
    for(j = (*p)->keynum;j > i;j--) {
        (*p)->data[j + 1] = (*p)->data[j];
        (*p)->ptr[j + 1] = (*p)->ptr[j];
    }
    (*p)->data[i + 1].key = k.key;
    (*p)->ptr[i + 1] = ap;
    (*p)->keynum++;
}
void split(BTree *p,BTree *ap) {
    int i;
    int s = (m + 1) / 2;
    (*ap)->ptr[0] = (*p)->ptr[s];
    for(i = s + 1;i <= m;i++) {
        (*ap)->data[i - s] = (*p)->data[i];
        if((*ap)->ptr[i - s])
            (*ap)->ptr[i - s]->parent = *ap;
    }
    (*ap)->keynum = m - s;
    (*ap)->parent = (*ap)->parent;
    (*p)->keynum = s - 1;
}
