class Solution {
public:
    TreeNode* res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        search(root, p, q);
        return res;
    }
    void search(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root->val - p->val) * (root->val - q->val) <= 0) res = root;
        else if (p->val > root->val && q->val > root->val) search(root->right, p, q);
        else search(root->left, p, q);
    }
};
