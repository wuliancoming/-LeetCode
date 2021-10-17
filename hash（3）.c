
#include <stdio.h>
#include <stdlib.h>
 

typedef struct  
{
	int *elem; //数据元素存储基地址
	int count;//当前数据元素个数
}HashTable;
 
int m = 0;//散列表长，全局变量
 
//初始化散列表
int InitHashTable(HashTable *h)
{
	int i;
	m = HASHSIZE;
	h->elem = (int *)malloc(sizeof(int) *m);
	if (h->elem==NULL)
	{
		fprintf(stderr, "malloc() error.\n");
		return ERROR;
	}
	for (i=0;i<m;i++)
	{
		h->elem[i] = NULLKEY;
	}
 
	return OK;
}
 
//散列函数
int Hash(int key)
{
	return key % m;//除留余数法
}
 
//插入关键字进散列表
void InsertHash(HashTable *h, int key)
{
	int addr = Hash(key);//求散列地址
	while (h->elem[addr]!=NULLKEY)  //如果不为空，则冲突
	{
		addr = (addr + 1) % m;//开放地址法的线性探测
	}
 
	h->elem[addr] = key;  //直到有空位后插入关键字
}
 
//散列表查找关键字
int SearchHash(HashTable h, int key)
{
	int addr = Hash(key);
	while (h.elem[addr]!=key)
	{
		addr = (addr + 1) % m;
		if (h.elem[addr]==NULLKEY || addr==Hash(key))
		{
			//如果循环回原点
			printf("查找失败，%d不在Hash表中.\n", key);
			return UNSUCCESS;
		}
	}
 
	printf("查找成功,%d在Hash表第%d个位置.\n", key, addr);
	return SUCCESS;
}
 
int main(void)
{
	int i = 0;
	int num = 0;
	HashTable h;
 
	InitHashTable(&h);
 
	printf("未插入数据之前，Hash表中内容为：\n");
	for (i=0;i<HASHSIZE;i++)
	{
		printf("%d ", h.elem[i]);
	}
	printf("\\n");
 
	//插入数据
	printf("现在插入数据，请输入（A代表结束）.\n");
	while (num<HASHSIZE && scanf("%d",&i)==1 )
	{
		if (i=='a')
		{
			break;
		}
		num++;
		InsertHash(&h, i);
 
		if (num>HASHSIZE)
		{
			printf("插入的数据超过Hash表的大小\n");
			return ERROR;
		}
	}
 
	//打印插入数据后的Hash表的内容
	printf("插入数据后的Hash表的内容为：\n");
	for (i=0;i<HASHSIZE;i++)
	{
		printf("%d ", h.elem[i]);
	}
	printf("\n");
 
	printf("现在进行查询.\n");
	SearchHash(h, 12);
	SearchHash(h, 100);
 
	system("pause");
	return 0;
}