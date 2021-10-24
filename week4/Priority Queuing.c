#include"Priority Queuing.h"


int main()
{
PNode head;
InitPQueue(&head);
Item item = { 3, 6 };
Push(&head, item);
item.data = 5;
item.prio = 3;
Push(&head, item);
item.data = 1;
item.prio = 8;
Push(&head, item);
item.data = 5;
item.prio = 1;
Push(&head, item);
item.data = 5;
item.prio = 3;
Push(&head, item);
ShowQueue(&head);
while (!IsEmpty(&head))
{
Pop(&head, &item);
printf("优先级：%d\n", item.prio);
printf("数据：%d\n", item.data);
}
Destroy(&head);
return 0;
}


//初始化队列
void InitPQueue(PQueue pQueue)
{
if (NULL == pQueue)
return;
pQueue->next = NULL;
}


//从堆中申请一个节点的内存空间
PNode* BuyNode(Item item)
{
PNode *pTmp = (PNode*)malloc(sizeof(PNode));
pTmp->item = item;
pTmp->next = NULL;
return pTmp;
}


//入队
void Push(PQueue pQueue, Item item)
{
PNode *pTmp = BuyNode(item);
PNode *pPre = pQueue;
PNode *pCur = pQueue->next;
while (NULL != pCur)
{
if (pCur->item.prio > item.prio)
{
pTmp->next = pCur;
pPre->next = pTmp;
return;
}
else
{
pPre = pCur;
pCur = pCur->next;
}
}
pPre->next = pTmp;
}


//出队，从队首(front)出
bool Pop(PQueue pQueue, Item *pItem)
{
if (!IsEmpty(pQueue))
{
PNode *pTmp = pQueue->next;
*pItem = pTmp->item;
pQueue->next = pTmp->next;
free(pTmp);
return true;
}
return false;
}


//获取队列长度
int GetPQueueLen(PQueue pQueue)
{
int iCount = 0;
PNode *pCur = pQueue->next;
while (NULL != pCur)
{
++iCount;
pCur = pCur->next;
}
return iCount;
}


//输出队列所有元素
void ShowQueue(PQueue pQueue)
{
PNode *pCur = pQueue->next;
while (NULL != pCur)
{
printf("优先级：%d\n", pCur->item.prio);
printf("数据：%d\n", pCur->item.data);
pCur = pCur->next;
}
printf("\n");
}


//队列为空则返回true
bool IsEmpty(PQueue pQueue)
{
return pQueue->next == NULL;
}


//获取队首元素
bool GetFront(PQueue pQueue, Item *pItem)
{
if (!IsEmpty(pQueue))
{
*pItem = pQueue->item;
return true;
}
return false;
}


//销毁队列(释放所有节点的内存空间)
void Destroy(PQueue pQueue)
{
PNode *pCur = pQueue->next;
while (NULL != pCur)
{
pQueue = pCur->next;
free(pCur);
pCur = pQueue;
}
}
————————————————
版权声明：本文为CSDN博主「kang___xi」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/kang___xi/article/details/53427199
