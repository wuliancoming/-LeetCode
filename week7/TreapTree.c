typedef struct TreapNode* Tree;
typedef int ElementType;
struct TreapNode
{
    ElementType val; //结点值
    int priority;   //优先级
    Tree lchild;
    Tree rchild;
    TreapNode(int val=0,int priority=0) //默认构造函数
    {
        lchild=rchild=NULL;
        this->val=val;
        this->priority=priority;
    }
};
//左旋转
void left_rotate(Tree &node)
{
    Tree temp=node->rchild;
    node->rchild=temp->lchild;
    temp->lchild=node;
    node=temp;
}
//右旋转
void right_rotate(Tree &node)
{
    Tree temp=node->lchild;
    node->lchild=temp->rchild;
    temp->rchild=node;
    node=temp;
}
//插入函数
bool insert(Tree &root,ElementType val=0,int priority=0)
{
    Tree node=new TreapNode(val,priority);
    return insert_val(root, node);
}
//内部插入函数
//参数:根结点，需插入的结点
bool insert_val(Tree &root,Tree &node)
{
    if (!root)
    {
        root=node; //插入
        return true;
    }
    else if(root->val>node->val)
    {
       bool flag=insert_val(root->lchild, node);
        if (root->priority>node->priority) //检查是否需要调整
            right_rotate(root);
        return flag;
    }
    else if(root->val<node->val)
    {
        bool flag=insert_val(root->rchild, node);
        if (root->priority>node->priority) //检查是否需要调整
            left_rotate(root);
        return flag;
    }
    //已经含有该元素，释放结点
    delete node;
    return false;

}
