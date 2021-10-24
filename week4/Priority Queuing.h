#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef struct _Item
{
int data;  //数据
int prio;  //优先级，值越小，优先级越高
}Item;
typedef struct _PNode
{
Item item;
struct _PNode *next;
}PNode, *PQueue;

void InitPQueue(PQueue pQueue); //初始化队列
PNode* BuyNode(Item item); //从堆中申请一个节点的内存空间
void Push(PQueue pQueue, Item item); //入队，从队尾(rear)入
bool Pop(PQueue pQueue, Item *pItem); //出队，从队首(front)出
int GetPQueueLen(PQueue pQueue); //获取队列长度
void ShowQueue(PQueue pQueue); //输出队列所有元素
bool IsEmpty(PQueue pQueue); //队列为空则返回true
bool GetFront(PQueue pQueue, Item *pItem); //获取队首元素
void Destroy(PQueue pQueue); //销毁队列(释放所有节点的内存空间)


