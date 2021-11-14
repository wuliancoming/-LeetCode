class RedBlackTreeNode {
    public int val;
    public RedBlackTreeNode left;
    public RedBlackTreeNode right;
    // 记录节点颜色的color属性，暂定true表示红色
    public boolean color;
    // 为了方便迭代插入，所需的parent属性
    public RedBlackTreeNode parent;

    // 一些构造函数，根据实际需求构建
    public RedBlackTreeNode() {
    }
}
public class RedBlackTree {
    // 当前红黑树的根节点，默认为null
    private RedBlackTreeNode root;
}
public void leftRotate(RedBlackTreeNode p) {
    // 在当前节点不为null时，才进行左旋操作
    if (p != null) {
        // 先记录p的右儿子
        RedBlackTreeNode rightChild = p.right;

        // 1. 空出右儿子的左子树
        p.right = rightChild.left;
        // 左子树不为空，需要更新父节点
        if (rightChild.left != null) {
            rightChild.left.parent = p;
        }

        // 2. 空出根节点的父节点
        rightChild.parent = p.parent;
        // 父节点指向右儿子
        if (p.parent == null) { // 右儿子成为新的根节点
            this.root = rightChild;
        } else if (p == p.parent.left) { // 右儿子成为父节点的左儿子
            p.parent.left = rightChild;
        } else { // 右儿子成为父节点的右儿子
            p.parent.right = rightChild;
        }

        // 3. 右儿子和根节点成功会师，根节点成为左子树
        rightChild.left = p;
        p.parent = rightChild;
    }
}
public void rightRotate(RedBlackTreeNode p) {
    if (p != null) {
        // 记录p的左儿子
        RedBlackTreeNode leftChild = p.left;

        // 1. 空出左儿子的右子树
        p.left = leftChild.right;
        // 右子树不为空，需要更新父节点
        if (leftChild.right != null) {
            leftChild.right.parent = p;
        }

        // 2. 空出根节点的父节点
        leftChild.parent = p.parent;
        // 父节点指向左儿子
        if (p.parent == null) { // 左儿子成为整棵树根节点
            this.root = leftChild;
        } else if (p.parent.left == p) { // 左儿子成为父节点左儿子
            p.parent.left = leftChild;
        } else { // 左儿子成为父节点的右儿子
            p.parent.right = leftChild;
        }

        // 3. 顺利会师
        leftChild.right = p;
        p.parent = leftChild;
    }
}
public void fixAfterInsert(RedBlackTreeNode x) {
    // 新插入的节点，默认为红色
    x.color = RED;

    // p不为null、不是整棵树的根节点、父亲为红色，需要调整
    while (x != null && this.root != x && x.parent.color == RED) {
        // 父亲是祖父的左儿子
        if (parentOf(x) == parentOf(parentOf(x)).left) {
            // 父亲和叔叔都是红色
            RedBlackTreeNode uncle = parentOf(parentOf(x)).right;
            if (uncle.color == RED) {
                // 父亲和叔叔都变成黑色
                parentOf(x).color = BLACK;
                uncle.color = BLACK;
                // 祖父变成红色，继续从祖父开始进行调整
                parentOf(parentOf(x)).color = RED;
                x = parentOf(parentOf(x));
            } else { // 叔叔为黑色
                // 自己是父亲的右儿子，需要对父亲左旋
                if (x == parentOf(x).right) {
                    x = parentOf(x);
                    leftRotate(x);
                }
                // 自己是父亲的左儿子，变色后右旋，保持黑色高度
                parentOf(x).color = BLACK;
                parentOf(parentOf(x)).color = RED;
                rightRotate(parentOf(parentOf(x)));
            }
        } else { //父亲是祖父的右儿子
            RedBlackTreeNode uncle = parentOf(parentOf(x)).left;
            // 父亲和叔叔都是红色
            if (uncle.color == RED) {
                // 叔叔和父亲变成黑色
                parentOf(x).color = BLACK;
                uncle.color = BLACK;
                // 祖父变为红色，从祖父开始继续调整
                parentOf(parentOf(x)).color = RED;
                x = parentOf(parentOf(x));
            } else {
                // 自己是父亲的左儿子，以父亲为中心右旋
                if (parentOf(x).left == x) {
                    x = parentOf(x);
                    rightRotate(x);
                }
                // 自己是父亲的右儿子，变色后左旋，保持黑色高度
                parentOf(x).color = BLACK;
                parentOf(parentOf(x)).color = RED;
                leftRotate(parentOf(parentOf(x)));
            }
        }
    }

    // 最后将根节点置为黑色，以满足红黑规则1，又不会破坏规则5
    this.root.color = BLACK;
}

private static RedBlackTreeNode parentOf(RedBlackTreeNode p) {
    return (p == null ? null : p.parent);
}
