//
//  main.c
//  20150722-1
//
//  Created by 欣 陈 on 15/7/22.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//KMP算法
int KMP_Index(SeqString S,int pos,SeqString T,int next[]){
    int i,j;
    i = pos - 1;
    j = 0;
    while(i < S.length && j < T.length){
        if(j = -1 || S.str[i] == S.str[j]){
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if(j >= T.length)
        return i - T.length + 1;
    else
        return -1;
}

//求next函数的算法
void GetNext(SeqString T,int next[]){
    int j,k;
    j = 0;
    k = -1;
    next[0] = -1;
    while(j < T.length){
        if(k == -1 || T.str[j] == T.str[k]){
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
}

//改进的求next函数的算法
void GetNextVal(SeqString T,int nextval[]){
    int j,k;
    j = 0;
    k = -1;
    nextval[0] = -1;
    while(j < T.length){
        if(k == -1 || T.str[j] == T.str[k]){
            j++;
            k++;
            if(T.str[j] != T.str[k])
                nextval[j] = k;
            else
                nextval[j] = nextval[k];
        }
        else
            k = nextval[k];
    }
}
