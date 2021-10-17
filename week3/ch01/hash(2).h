#ifndef __HASHTABLE_H
#define __HASHTABLE_H
 

 
struct ListNode;
typedef struct ListNode *position;
typedef position list;
struct HashTable;
typedef struct HashTable *hashTable;
typedef int ElementType;
#define MINTABLESIZE 5
#define MAXTABLESIZE 20
 
 
hashTable initializeTable(int tablesize);
void destroyTable(hashTable H);
position find(ElementType key,hashTable H);
ElementType retrieve(position p);
int nextPrime(int tableSize);
int isPrime(int x);
void insert(ElementType key,hashTable H);
int Hash(ElementType key,int tableSize);
int Delete(ElementType key,hashTable H);
 
struct ListNode
{
	ElementType element;
	position next;
};
 
struct HashTable
{
	int tableSize;
	list *thelists;	//指向ListNode的指针的指针
};
 

#endif