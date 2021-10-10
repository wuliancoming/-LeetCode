#include<iostream>
#include<stdio.h>
using namespace std;
template <class DataType>
struct BiNode
{
    DataType data;
    BiNode<DataType> * lchild,*rchild;
};

template <class DataType>
class BiTree
{
public:
    BiTree(){root = Create(root);}
    ~BiTree(){Release(root);}
    void PreOrder(){PreOrder(root);}	//前序遍历
    void InOrder(){InOrder(root);}		//中序遍历
    void PostOrder(){PostOrder(root);}	//后序遍历
private:
    BiNode<DataType> * root;
    BiNode<DataType> * Create(BiNode<DataType> *bt);
    void Release(BiNode<DataType> *bt);
    void PreOrder(BiNode<DataType> *bt);
    void InOrder(BiNode<DataType> *bt);
    void PostOrder(BiNode<DataType> *bt);
};
template <class DataType>
BiNode<DataType> *BiTree<DataType>::Create(BiNode<DataType> *bt)
{
    DataType ch;
    cin>>ch;
    if(ch == '#') bt = NULL;
    else{
        bt = new BiNode<DataType>;
        bt->data = ch;
        bt->lchild = Create(bt->lchild);
        bt->rchild = Create(bt->rchild);
    }
    return bt;
}
template <class DataType>
void BiTree<DataType>::Release(BiNode<DataType> *bt)
{
    if(bt != NULL){
        Release(bt->lchild);
        Release(bt->rchild);
        delete bt;
    }
}
template <class DataType>
void BiTree<DataType>::PreOrder(BiNode<DataType> *bt)
{
    if(bt == NULL) return;
    else{
        cout<<bt->data;
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}
template <class DataType>
void BiTree<DataType>::InOrder(BiNode<DataType> *bt)
{
    if(bt == NULL) return;
    else{
        InOrder(bt->lchild);
        cout<<bt->data;
        InOrder(bt->rchild);
    }
}
template <class DataType>
void BiTree<DataType>::PostOrder(BiNode<DataType> *bt)
{
    if(bt == NULL) return;
    else{
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        cout<<bt->data;
    }
}
