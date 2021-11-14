template <class T>
struct SplayTreeNode{
    T element;//关键字
    SplayTreeNode *LeftChild;//左孩子
    SplayTreeNode *RightChild;//右孩子
    int count;//该关键字出现的次数
    int sz;//子树中节点的数目

    //构造函数
    SplayTreeNode():count(1),sz(1) {LeftChild=RightChild=NULL;}
    SplayTreeNode(T& theElement):element(theElement),count(1),sz(1){LeftChild=RightChild=NULL;}
    SplayTreeNode(T& theElement,
                SplayTreeNode *theLeftChild,
                SplayTreeNode *theRightChild)
                :element(theElement),count(1),sz(1){LeftChild=theLeftChild;RightChild=theRightChild;}

    //复制构造函数
    SplayTreeNode(SplayTreeNode<T>* t){
        element=t->element;
        LeftChild=t->LeftChild;
        RightChild=t->RightChild;
        count=t->count;
        sz=t->sz;
    }
};
template <class T>
class SplayTree{
    friend class Solve;
    public:
        //构造函数
        SplayTree();
        //析构函数
        ~SplayTree();
        //返回树中节点个数
        int TreeSize(){return Size;}
        //更改根节点
        void ChangeRoot(SplayTreeNode<T>* t);
        //返回根节点
        SplayTreeNode<T>* TreeRoot(){return Root;}
        //删除t节点及其子树
        void DeleteTree(SplayTreeNode<T>* t);
        //左旋
        SplayTreeNode<T>* Left_Rotate(SplayTreeNode<T>* t);
        //右旋
        SplayTreeNode<T>* Right_Rotate(SplayTreeNode<T>* t);
        //伸展
        SplayTreeNode<T>* Splay(SplayTreeNode<T>* t,T key);
        //查找
        SplayTreeNode<T>* SearchNode(T& theElement);
        //返回最大
        SplayTreeNode<T>* MaxElement();
        //返回最小
        SplayTreeNode<T>* MinElement();
        //初始化
        void Init(vector<T> a);
        //插入
        void InsertNode(T& theElement);
        //删除
        bool EraseNode(T& theElement);
        //中序插入
        void InorderInsert(SplayTreeNode<T>* t);
        //拆分
        vector<SplayTreeNode<T>*> SplitTree(T& theElement);
        //合并
        SplayTreeNode<T>* MergeTree(vector<SplayTreeNode<T>* >);
        //层次遍历
        void LevelOrder(SplayTreeNode<T>* t);
        void LevelOrder();
        //可视化
        void Visualization();
        void Visualization(vector<SplayTreeNode<T>*> roots);
    private:
        //根节点
        SplayTreeNode<T> *Root;
        //节点数目
        int Size;
};
//左旋
template <class T>
SplayTreeNode<T>* SplayTree<T>::Left_Rotate(SplayTreeNode<T>* t){
    SplayTreeNode<T>* right=t->RightChild;
    t->RightChild=right->LeftChild;
    //更新各节点的子节点数目信息
    int PreTsz=(t==NULL)?0:t->sz,
        PreRsz=(right==NULL)?0:right->sz,
        PreLsz=(t->RightChild==NULL)?0:t->RightChild->sz;
    right->LeftChild=t;
    t->sz=PreTsz-PreRsz+PreLsz;
    right->sz=PreTsz;
    return right;
}

//右旋
template <class T>
SplayTreeNode<T>* SplayTree<T>::Right_Rotate(SplayTreeNode<T>* t){
    SplayTreeNode<T>* left=t->LeftChild;
    t->LeftChild=left->RightChild;
    //更新各节点的子节点数目信息
    int PreTsz=(t==NULL)?0:t->sz,
        PreLsz=(left==NULL)?0:left->sz,
        PreRsz=(t->LeftChild==NULL)?0:t->LeftChild->sz;
    left->RightChild=t;
    t->sz=PreTsz-PreLsz+PreRsz;
    left->sz=PreTsz;
    return left;
}

//伸展
template <class T>
SplayTreeNode<T>* SplayTree<T>::Splay(SplayTreeNode<T>* t,T key){
    //树为空退出
    if(t==NULL)
        return t;

    //创建两棵临时树
    //左树保存小于当前根节点的节点
    //右树保存大于当前根节点的节点
    SplayTreeNode<T> head;
    SplayTreeNode<T> *LeftTree,*RightTree;
    head.LeftChild=head.RightChild=NULL;
    LeftTree=RightTree=&head;

    while(key!=t->element){
        if(key<t->element){
            if(t->LeftChild==NULL)
                break;
            //右旋
            if(key<t->LeftChild->element){
                t=Right_Rotate(t);
            }
            if(t->LeftChild==NULL)
                break;
            //连接到右树
            RightTree->LeftChild=t;
            RightTree=t;
            t=t->LeftChild;
        }
        else{
            if(t->RightChild==NULL)
                break;
            //左旋
            if(key>t->RightChild->element)
                t=Left_Rotate(t);
            if(t->RightChild==NULL)
                break;
            //连接到左树
            LeftTree->RightChild=t;
            LeftTree=t;
            t=t->RightChild;
        }
    }

    //组装
    LeftTree->RightChild=t->LeftChild;
    RightTree->LeftChild=t->RightChild;
    t->LeftChild=head.RightChild;
    t->RightChild=head.LeftChild;
 //   Root=t;

    return t;
}
