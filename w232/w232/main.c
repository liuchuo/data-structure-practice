//
//  main.c
//  w232
//
//  Created by 欣 陈 on 15/9/6.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//#include <stdio.h>
//int min(int *s,int n) {
//    int i;
//    int flag,hehe;
//    flag = -1;
//    int f = 100;
//    for(i = 0;i < n;i++) {
//        if(s[i] < f && i != hehe) {
//             f = s[i];
//            flag = i;
//        }
//    }
//    hehe = flag;
//    return flag;
//}
//
//int main() {
//    int s[8] = {5,3,4,1,0,-2,-1,8};
//    int s1,s2;
//    s1 = min(s,8);
//    s2 = min(s,8);
//    printf("s1=%d,s2=%d",s1,s2);
//    return 0;
//}
//
//int main() {
//    int i;
//    i = 1;
//    for(;i <= 5;++i) {
//        printf("%d\t",i);
//    }
//    return 0;
//}
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node{
    int element;
    struct  Node * next;
}Node;

//Initialize a link list.
Node * Init(Node * head){
    if(head == NULL){
        head = null;
    }
    
    head = (Node * ) malloc (sizeof (Node));
    return head;
}

//DestoryList a link list.
void Drop(Node * head){
    Node * p = head;
    while(p->next){
        head = p;
        p = p->next;
        free(head);
    }
}

//Clear a link list.
void Clear(Node * head){
    if(head->next){
        drop(head->next);
    }
}

//Link list whether is empty.
bool Empty(Node * head){
    return (head->next == 0)
}

//Get the length of the link list.
int Length(Node * head){
    Ndoe * p = head;
    int len = 0;
    while(p->next){
        len++;
        p = p->next;
    }
    return len;
}

/*
 //Find a element by index.
 int GetElement(Node * head, int index){
	
	if(index < 0 && index >= Length(head)){
 cout << "You input index are over flow" << endl;
	}
 
	Node * p = head;
	int i = 0;
	while(i <= index && p){
 
	}
 }
 */

int main(){
    Node * head;
    head = init(head);
}