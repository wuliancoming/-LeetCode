
#include<iostream>
//#include"Tree.h"
using namespace std;
struct treeNode
{
	char data;
	treeNode* firstChild;
	treeNode* nextSibling;
	treeNode(char value,treeNode* firstChild1=nullptr,treeNode* nextSibling1=nullptr)
	{
		data = value;
		firstChild = firstChild1;
		nextSibling = nextSibling1;
	}
};

int main()
{
	treeNode* Root = new treeNode('A');
	treeNode* movePtr = Root;
	movePtr->firstChild = new treeNode('B');
	movePtr->firstChild->nextSibling = new treeNode('C');
	movePtr->firstChild->nextSibling->nextSibling = new treeNode('D');
	movePtr->firstChild->firstChild = new treeNode('E');
	movePtr->firstChild->nextSibling->firstChild = new treeNode('F');
	movePtr->firstChild->nextSibling->firstChild->nextSibling = new treeNode('G');

	//测试
	treeNode* testPtr = Root;
	int count = 0;
	cout << "根结点是：";
	cout << testPtr->data << endl;
	testPtr = testPtr->firstChild;
	while (testPtr != nullptr)
	{
		count++;
		cout << "结点" << Root->data << "的第" << count << "个儿子为：" <<testPtr->data<< endl;
		testPtr = testPtr->nextSibling;
	}

	return 0;
}
