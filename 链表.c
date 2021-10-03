#include <stdio.h>
#include <stdlib.h>

typedef struct Node *Ptrtonode
{
    /* data */
};
typedef Ptrtonode List
typedef Ptrtonode Position
struct Node
{
    /* data */
    Elementtype  Element;
    Position Next;
};
/*测试链表是否为空*/
int IsEmpty(List L)
{
    return L->Next==NULL;
}
/*测试是否为链表结尾的函数*/
int IsLast(Position p,List L)
{
    return p->Next==NULL;
}
/*Find例程*/
Position Find(ElementType X,List L)
{
    Position P;
    P=L->Next;
    while (P != NULL && P->Element != X)
    {
        /* code */
        P=P->Next;
    }
    return P;
}

/*FindPrevious*/
Position
FindPrevious(List L,X)
{
    Position p;
    p=L;
    while (p->Next !=NULL&&p->Next->Element !=X)
    /*先判断p当前指向的next不为null，如果不是null就去找他的下一个结点Element是否等于x*/
    {
        p=p->Next;
    }
    return p;
}
/*链表的删除例程*/
void Delete(List L,ElementType Element)
{
    Position p,Tmpcell;
    /*Tmpcell是一个内存块，如果不使用它的话，地址丢失，p->next=p->next->next;
    free()*/
    p=FindPrevious(L,X)
    if (!IsLast(p,L))

    {
        /* code */
        Tmpcell=p->Next;
        p->Next=Tmpcell->Next;
        free(Tmpcell);
    }
    
}
/*链表的插入例程*/
void Insert (List L,ElementType X,Position p)
{
    Position TmpCell;
    TmpCell=(struct Node*)malloc(sizeof(struct Node));
    TmpCell->Element=X;
    TmpCell->Next=p->Next;/*先让TmpCell指向后面，再让p->Next指向tmpcell不然会丢失地址*/
    p->Next=TmpCell;
  
    
}
/*删除一个表*/
void Deletelist(List L)
{
    Position P,Tmp;
    P=L->Next;
    L->Next=NULL;
    while (
        P!=NULL
    )
    {
        /* code */
        Tmp=P->Next;
        free(P)
        P=Tmp;
    }
    
}