#include "HashTable.h"
#include <stdio.h>
#include <stdlib.h>
 
/***************************分离链表法****************************/
 
/*构造出了一个指针数组，数组的每一个元素都指向一个链表*/
 
hashTable initializeTable(int tableSize)
{
	hashTable H;
	int i;
 
	if(tableSize<MINTABLESIZE)
	{
		printf("table is too small!\n");
		return NULL;
	}
	H=(struct HashTable*)malloc(sizeof(struct HashTable));
	if(H==NULL)
	{
		printf("out of space\n");
		return NULL;
	}
	H->tableSize=nextPrime(tableSize);	//11
	
	//创建指针数组	
	H->thelists=malloc(sizeof(list)*H->tableSize);	//指针数组,数组里不放数据，数据放在链表里
	
	if(H->thelists==NULL)
	{
		printf("out of space!\n");
		return NULL;
	}
	//创建指针数组元素指向的链表表头
	for(i=0;i<H->tableSize;i++)
	{	
		H->thelists[i]=(struct ListNode*)malloc(sizeof(struct ListNode));
		if(H->thelists[i]==NULL)
		{
			printf("out of space!\n");
			return NULL;
		}
		else
			H->thelists[i]->next=NULL;
	}
	return H;
}
 
int nextPrime(int tableSize)
{
	while(1)
	{
		if(isPrime(tableSize))
			return tableSize;
		else
			tableSize++;
	}
}
int isPrime(int x)
{
	int i;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}
 
void destroyTable(hashTable H)
{
	position h,p,q;
	int i;
	for(i=0;i<H->tableSize;i++)
	{
		h=H->thelists[i];
		p=h->next;
		while(p)
		{
			q=p->next;
			if(!q)
			{
				free(p);
				p=NULL;
			}
			else
			{
				free(p);
				p=q;
			}	
		}
	}
}
 
position find(ElementType key,hashTable H)
{
	position p;
	list L;
 
	L=H->thelists[Hash(key,H->tableSize)];
	p=L->next;
	while(p)
	{
		if(p->element==key)
			return p;
		p=p->next;
	}
	return NULL;
}
 
void insert(ElementType key,hashTable H)
{
	position pos,newcell;
	list L;
 
	pos=find(key,H);
	if(pos==NULL)	//错把pos=null当作判断条件，此条件永远为真。
	{
		newcell=(struct ListNode*)malloc(sizeof(struct ListNode));
		if(newcell==NULL)
		{
			printf("out of space\n");
			exit(-1);
		}
		else
		{
			L=H->thelists[Hash(key,H->tableSize)];
			newcell->next=L->next;	
			newcell->element=key;
			L->next=newcell;
		}
	}
}
 
int Hash(ElementType key,int tableSize)
{
	return key%tableSize;
}
 
int Delete(ElementType key,hashTable H)
{
	position pos,h,L;
	L=H->thelists[Hash(key,H->tableSize)];
	h=L->next;
	while(h!=NULL&&h->next&&h->next->element!=key)
		pos=pos->next;
	if(h==NULL)
	{
		printf("cant find that key!\n");
		return 0;
	}
	else
	{
		pos=h->next;
		h->next=pos->next;
		free(pos);
		return 1;
	}
}
 
ElementType retrieve(position p)
{
	return p->element;
}