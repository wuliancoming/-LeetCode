#include<stdio.h>
#include<stdlib.h>
typedef struct Node *ptr;
typedef ptr stack;
int isempty(stack s);//检测栈是否为空
stack creatstack();//创建一个栈
void makeempty(stack s);//使栈归空
void pop(stack s);//出栈 
void push(int m,stack s);//元素进栈 
int top(stack s);//返回栈顶元素 
struct Node//声明结构体
{
	int n;
	ptr next;
};
int isempty(stack s)//检测是否为空 
{
	return (s->next==NULL);//为空返回1否则返回0，与链表如出一辙 
}
stack creatstack()//创建一个空栈 
{
	stack s=(stack)malloc(sizeof(struct Node)); 
	if(s==NULL)
		printf("out of space\n");
	else
		s->next=NULL;
	makeempty(s);
	return s;
}
void makeempty(stack s)//使栈为空 
{
	if(s==NULL)
		printf("must creat a stack\n");
	else
		while(!isempty(s))
			pop(s);
}
void push(int m,stack s)//实现入栈操作 
{
	stack p;
	if(isempty(s))
		printf("empty\n");
	else
	{
		p->n=m;
		p->next=s->next;
		s->next=p;
	}
}
void pop(stack s)
{
	stack first;
	if(isempty(s))
		printf("empty stack");
	else
	{
		first=s->next;
		s->next=s->next->next;
		free(first);//释放空间 
	}
}
int  top(stack s)//返回栈顶元素 
{
	if(!isempty(s))
		return s->next->n;
	printf("empty");
	return 0;
}
