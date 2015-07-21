//
//  main.c
//  20150721-1
//
//  Created by 欣 陈 on 15/7/21.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//串的模式匹配
//1.朴素模式匹配算法——Brute-Force
int B_FIndex(SeqString S,int pos,SeqString T){
    int i,j;
    i = pos - 1;
    while(i < S.length && j < T.length){
        if(S.str[i] == S.str[j]){
            i++;
            j++;
        }
        else{
            i = i - j + 1;
            j = 0;
        }
    }
    if(j >= T.length)
        return i - j + 1;
    else
        return -1;
}
