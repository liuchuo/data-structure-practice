//
//  main.c
//  20150712-1
//
//  Created by 欣 陈 on 15/7/12.
//  Copyright (c) 2015年 欣 陈. All rights reserved.
//

//栈和队列：动画模拟停车场管理系统
#include <stdio.h>
#include <stdlib.h>//the function of malloc
#include <time.h>//get system time
#include <windows.h>//set the information of cursor 'malllco'

#define MaxSize 5
#define PRICE 0.05
#define BASEPRICE 0.5
#define Esc 27//exit system(escape)
#define Exit 3//end a conversation
#define Stop 1//park car
#define Drive 2//pick up car

int jx = 0,jy = 32;

//Node:time
typedef struct{
    int hour;
    int minute;
}Time,*PTime;

//Node:the information of car
typedef struct{
    int num;//license plate
    Time arrtime;
}CarNode;

//define a stack to imitate parking lot
typedef struct{
    CarNode stack[MaxSize];
    int top;
}SqStackCar;

//Node:queue
typedef struct node{
    int num;//license plate
    struct node *next;
}QueueNode;

//define a queue to imitate line up
typedef struct{
    QueueNode *front,*rear;
}LinkQueueCar;

//function declaration
PTime get_time();
CarNode getcarInfo();
void qingping(int a);
void gotoxy(int x,int y);
void printlog(Time t,int n,int io,char ab,int po,double f);
void printstop(int a,int num,int x0,int y0);
void printleave(int a,int po,int num);

void InitSeqStack(SqStackCar *s){
    s->top = -1;
}

int push(SqStackCar *s,CarNode x){
    if(s->top == MaxSize - 1)
        return(0);
    else{
        s->stack[++s->top] = x;
        return(1);
    }
}

CarNode pop(SqStackCar *s){
    CarNode x;
    if(s->top < 0){
        x.num = 0;
        x.arrtime.hour = 0;
        x.arrtime.minute = 0;
        return(x);
    }
    else{
        s->top--;
        return(s->stack[s->top+1]);
    }
}

void InitLinkQueue(LinkQueueCar *q){
    q->front = (QueueNode *)malloc(sizeof(QueueNode));
    if(q->front != NULL){
        q->rear = q->front;
        q->front->next = NULL;
        q->front->num = 0;
    }
}

void EnLinkQueue(LinkQueueCar *q,int x){
    QueueNode *p;
    p = (QueueNode *)malloc(sizeof(QueueNode));
    p->num = x;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
    q->front->num++;
}

int DeLinkQueue(LinkQueueCar *q){
    QueueNode *p;
    int n;
    if(q->front == q->rear)
        return(0);
    else{
        p = q->front->next;
        q->front->next = p->next;
        if(p->next == NULL)
            q->rear = q->front;
        n = p->num;
        free(p);
        q->front->num--;
        return(n);
    }
}

/************车辆到达***************/
//参数：停车栈 停车队列 车辆信息
//返回值：空
//功能：对传入的车辆进行入栈 栈满则入队列
void Arrive(SqStackCar *stop,LinkQueueCar *lq,CarNode x){
    int f;
    f = push(stop,x);
    if(f == 0){
        EnLinkQueue(lq,x.num);
        printstop(1,lq->front->num,0,23);
        printlog(x.arrtime,x.num,1,'B',lq->front->num,0);
        qingping(0);
        printf("您的车停在便道%d号车位上\n",lq->front->num);
    }
    else{
        printstop(0,stop->top+1,0,23);
        printlog(x.arrtime,x.num,1,'P',stop->top + 1,0);
        qingping(0);
        printf("您的车在停车场%d号车位上\n",stop->top + 1);
    }
    qingping(1);
    printf("按任意键继续");
    getchar();
}
/***************** 车辆离开 *********************/
// 参数：停车栈指针s1，暂存栈指针s2，停车队列指针p，车辆信息x
// 返回值：空
// 功能：查找栈中s1的x并出栈，栈中没有则查找队p中并出队，打印离开收费信息
void Leave(SqStackCar *s1,SqStackCar *s2,LinkQueueCar *p,CarNode x){
    double fee = 0;
    int position = s1->top + 1;
    int n,f = 0;
    CarNode y;
    QueueNode *q;
    while((s1->top > -1)&&(f != 1)){
        y = pop(s1);
        if(y.num != x.num){
            n = push(s2,y);
            position--;
        }
        else
            f = 1;
    }
    if(y.num == x.num){
        gotoxy(33,17);
        printf("%d:%-2d",(x.arrtime.hour-y.arrtime.hour),
               (x.arrtime.minute-y.arrtime.minute));
        fee = ((x.arrtime.hour-y.arrtime.hour) * 60 +
               (x.arrtime.minute - y.arrtime.minute)) * PRICE + BASEPRICE;
        gotoxy(48,17);
        printf("%2.1f元\n",fee);
        qingping(0);
        printf("确认您的车辆信息");
        qingping(1);
        printf("按任意键继续");
        getchar();
        while(s2->top > -1){
            y = pop(s2);
            f = push(s1,y);
        }
        n = DeLinkQueue(p);
        if(n != 0){
            y.num = n;
            y.arrtime = x.arrtime;
            f = push(s1,y);
            printleave(p->front->num + 1,position,s1->top + 1);
            printlog(x.arrtime,x.num,0,'P',position,fee);
            printlog(y.arrtime,y.num,1,'P',s1->top + 1,0);
        }
        else{
            printleave(0,position,s1->top + 2);
            printlog(x.arrtime,x.num,0,'P',position,fee);
        }
    }
    else{
        while(s2->top > -1){
            y = pop(s2);
            f = push(s1,y);
        }
        q = p->front;
        f = 0;
        position = 1;
        while(f == 0 && q->next != NULL){
            if(q->next->num != x.num){
                q = q->next;
                position++;
            }
            else{
                q->next = q->next->next;
                p->front->num--;
                if(q->next == NULL)
                    p->rear = p->front;
                gotoxy(33,17);
                printf("0:0");
                gotoxy(48,17);
                printf("0元");
                qingping(0);
                printf("您的车将离开便道");
                qingping(1);
                printf("按任意键继续");
                getchar();
                printleave(-1,position,p->front->num + 1);
                printlog(x.arrtime,x.num,0,'B',position,0);
                f = 1;
            }
            if(f == 0){
                qingping(0);
                printf("停车场和便道上均无您的车");
                qingping(1);
                printf("按任意键继续");
                getch();
            }
        }
    }
}

/*获取系统时间*/
//返回PTime类型
PTime get_time(){
    Time *t;
    time_t timer;
    struct tm *tblock;
    t = (Time *)malloc(sizeof(Time));
    timer = time(NULL);
    tblock = localtime(&timer);
    t->minute = tblock->tm_min;
    t->hour = tblock->tm_hour;
    return t;
}

/*移动光标*/
//使光标移动到(x,y)点
void gotoxy(int x,int y){
    COORD coord;
    coord.X = x;
    coord.Y = y + 3;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

/*画图*/
//画出系统界面
void panitPL(){
    int i,j,x,y,a[2][4] = {2,0,0,1,-2,0,0,-1};
    gotoxy(20,4);
    printf("************对话框****************");
    x = 18,y = 6;
    for(i = 0;i < 2;i++){
        for(j = 0;j < 20;j++){
            x += a[i][0];
            y += a[i][1];
            gotoxy(x,y);
            printf("==");
        }
        x += a[i][0];
        y += a[i][1];
        gotoxy(x,y);
        if(i == 0){
            printf("◥");
        }
        else{
            printf("◣");
        }
        for(j = 0;j < 12;j++){
            x += a[i][2];
            y += a[i][3];
            gotoxy(x,y);
            printf("▍");
        }
        x += a[i][2];
        y += a[i][3];
        gotoxy(x,y);
        if(i == 0){
            printf("◢");
        }
        else{
            printf("◤");
        }
    }
    gotoxy(22,8);
    printf("小张：");
    gotoxy(22,11);
    printf("顾客：");
    gotoxy(22,14);
    printf("************停车信息**************");
    gotoxy(23,15);
    printf("车牌号:");
    gotoxy(42,15);
    printf("时间:");
    gotoxy(23,17);
    printf("停车时长：");
    gotoxy(42,17);
    printf("收费：");
}

/*清屏函数*/
void qingping(int a){
    if(a == 0){
        gotoxy(23,8);
        printf("                                        ");
        gotoxy(28,9);
        printf("                                        ");
        gotoxy(28,8);
    }
    else
        if(a == 1){
            gotoxy(28,11);
            printf("                                        ");
            gotoxy(28,12);
            printf("                                        ");
            gotoxy(28,13);
            printf("                                        ");
            gotoxy(28,11);
        }
        else{
            gotoxy(31,15);
            printf("                                        ");
            gotoxy(48,15);
            printf("                                        ");
            gotoxy(33,17);
            printf("                                        ");
            gotoxy(48,17);
            printf("                                        ");
            gotoxy(31,15);
        }
}

//用上下键移动选择
int getkey(){
    char c;
    int x = 28;
    int y = 11;
    while(1){
        gotoxy(x,11);
        printf("      ");
        gotoxy(x,12);
        printf("      ");
        gotoxy(x,13);
        printf("      ");
        gotoxy(x,y);
        printf(">>");
        c = getch();
        if(c == 13)
            return y-10;
        if(c != 32)
            continue;
        c = getch();
        if(c == 72)
            if(y > 11)
                y--;
        if(c == 80)
            if(y < 13)
                y++;
    }
}

//输入车辆信息
CarNode getcarInfo(){
    PTime T;
    CarNode x;
    qingping(0);
    printf("请输入您的车牌号\n");
    qingping(1);
    printf("在下面输入车辆信息");
    qingping(2);
    scanf("%d",&(x.num));
    T = get_time();
    x.arrtime = *T;
    gotoxy(48,15);
    printf("%d:%d",x.arrtime.hour,x.arrtime.minute);
    getch();
    return x;
}

//打印停车场
void printcar(){
    gotoxy(0,20);
    printf("=======================================================◥");
    printf("                出场暂放区 | 1   2   3   4   5           ▌");
    printf("-------------------------------------------------------▌");
    printf("                    主车道                              ▌");
    printf("-------------------------------------------------------▌");
    printf("12  11 10  9  8  7  6  5  4  3  2  1                   ▌");
    printf("==============================================◥        ▌");
    printf("                                               ▎       ▌");
    printf("                                    ==========◢        ▌");
    printf("                                   |  1  2  3  4  5    ▌");
    printf("                                    ==================◢ ");
    printf("                    停车场管理日志\n\n");
    printf(" 时间    车牌号   进(1)/出(0)   车位（B便道P停车场） 收费（元）");
}

//打印日志记录
void printlog(Time t,int n,int io;char ab,int po,double f){
    jy++;
    gotoxy(jx,jy);
    printf(" 时间    车牌号   进(1)/出(0)   车位（B便道P停车场） 收费（元）");
    if(io == 0)
        printf("                                             / %2.1f",f);
    gotoxy(jx,jy);
    printf("                /   %d    /     %c:%d",io,ab,po);
    gotoxy(jx,jy);
    printf("%d:%d   /     %d",t.hour,t.minute,n);
}
void printstop(int a,int num,int x0,int y0){
    static char *car = "【 ▇ 】";
    int x0 = 0,y0 = 23;
    int x = 0,y = 28;
    if(a == 0){
        x = (num + 6) * 6;
        for(;x0 < 72;x0++){
            gotoxy(x0,y0);
            printf("%s",car);
            Sleep(30);
            gotoxy(x0,y0);
            printf("        ");
        }
        for(;y0 < y;y0++){
            gotoxy(x0,y0);
            printf("%s",car);
            Sleep(100);
            gotoxy(x0,y0);
            printf("        ");
        }
        for(;x0 > x;x0--){
            gotoxy(x0,y0);
            printf("%s",car);
            Sleep(50);
            gotoxy(x0,y0);
            printf("        ");
        }
        gotoxy(x,y);
        printf("%s",car);
    }
    else{
        x = (12 - num) * 6;
        y = y - 3;
        for(;x0 < x;x0++){
            gotoxy(x0,y0);
            printf("%s",car);
            Sleep(30);
            gotoxy(x0,y0);
            printf("        ");
        }
        gotoxy(x,y);
        printf("%s",car);
    }
}

void printleave(int a,int po,int num){
    static char *car = "【 ▇ 】";
    int x0 = 0,y0 = 23;
    int x = 0,y = 28;
    int i;
    if(a == -1){
        x = (12 - po) * 6;
        y = y - 3;
        gotoxy(x,y);
        printf("    ");
        gotoxy(x,y - 2);
        printf("%s",car);
        Sleep(100);
        if(12 > num){
            gotoxy((12 - num) * 6,y);
            printf("        ");
        }
        gotoxy(x,y);
        printf("%s",car);
        for(;x > x0;x--){
            gotoxy(x,y - 2);
            printf("%s",car);
            Sleep(30);
            gotoxy(x,y - 2);
            printf("        ");
        }
    }
    else{
        i = num + 1;
        for(;num > po;num--){
            x = (num + 6) * 6;
            y = 28;
            for(;x < 72;x++){
                gotoxy(x,y);
                printf("%s",car);
                Sleep(30);
                gotoxy(x,y);
                printf("        ");
            }
            for(;y > 21;y--){
                gotoxy(x,y);
                printf("%s",car);
                Sleep(50);
                gotoxy(x,y);
                printf("        ");
            }
            for(;x > (i - num + 6) * 6;x--){
                gotoxy(x,y);
                printf("%s",car);
                Sleep(30);
                gotoxy(x,y);
                printf("        ");
            }
            gotoxy(x,y);
            printf("%s",car);
        }
        x = (po + 6) * 6;
        y = 28;
        for(;x < 72;x++){
            gotoxy(x,y);
            printf("%s",car);
            Sleep(50);
            gotoxy(x,y);
            printf("        ");
        }
        for(;y > 23;y--){
            gotoxy(x,y);
            printf("%s",car);
            Sleep(50);
            gotoxy(x,y);
            printf("        ");
        }
        for(;x > 0;x--){
            gotoxy(x,y);
            printf("%s",car);
            Sleep(30);
            gotoxy(x,y);
            printf("        ");
        }
        num++;
        for(;i - num > 0;num++){
            x = (i - num + 6) * 6;
            y = 21;
            for(;x < 72;x++){
                gotoxy(x,y);
                printf("%s",car);
                Sleep(30);
                gotoxy(x,y);
                printf("        ");
            }
            for(;y < 28;y++){
                gotoxy(x,y);
                printf("%s",car);
                Sleep(50);
                gotoxy(x,y);
                printf("        ");
            }
            for(;x > (num - i + 6) * 6;x--){
                gotoxy(x,y);
                printf("%s",car);
                Sleep(30);
                gotoxy(x,y);
                printf("        ");
            }
            gotoxy(x,y);
            printf("%s",car);
        }
        if(a > 0){
            x = 66;
            y = 25;
            gotoxy(x,y);
            printf("        ");
            gotoxy(x,y - 2);
            printf("%s",car);
            Sleep(100);
            if(12 > a){
                gotoxy((12 - a) * 6,y);
                printf("        ");
            }
            if(a > 1){
                gotoxy(x,y);
                printf("%s",car);
            }
            printstop(0,i - 1,x,y - 2);
        }
    }
}

int main(){
    int i,a;
    char c;
    SqStackCar s1,s2;
    LinkQueueCar p;
    InitSeqStack(&s1);
    InitSeqStack(&s2);
    InitLinkQUeue(&p);
    printf("                    停车场管理系统\n\n");
    printf("***********************  欢迎光临  *********************");
    printf("    收费标准：基础费0.5元，每分钟收取0.05元，收费精确到0.1元");
    printf("    PS:车牌号由阿拉伯数字组成");
    panitPL();
    printfcar();
    gotoxy(0,-3);
    c = 0;
    while(1){
        for(i = 2;i > -1;i--){
            qingping(i);
        }
        printf("按ESC退出系统，其他键开始对话");
        c = getch();
        if(c == Esc){
            qingping(0);
            break;
        }
        
        while(1){
            qingping(2);
            gotoxy(28,8);
            printf("欢迎来到停车场！我是管理员小张。");
            gotoxy(28,9);
            printf("请您按丄丅选择需要的服务        ")；
            gotoxy(28,11);
            printf("  1.我要停车");
            gotoxy(28,12);
            printf("  2.我要取车");
            gotoxy(28,13);
            printf("  3.结束对话");
            a = getkey();
            if(a == Exit){
                printf("结束服务。");
                break;
            }
            switch(a){
                case Stop:
                    Arrive(&s1,&p,getcarInfo());
                    break;
                case Drive;
                    Leave(&s1,&s2,getcarInfo());
                    break;
            }
        }
    }
    return 0;
}
