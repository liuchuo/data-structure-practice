//
//  main.c
//  20150602-4
//
//  Created by 欣 陈 on 15/6/2.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//循环单链表
//合并两个循环单链表
LinkList Link(LinkList head1,LinkList head2){
    ListNode *p,*q;
    p = head1;
    while(p->next != head1){
        p = p->next;
    }
    q = head2;
    while(q->next != head2){
        q = q->next;
    }
    p->next = head2->next;
    q->next = head1;
    return head1;
}
