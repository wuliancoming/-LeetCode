class Solution {
public:
    int res;
    int cur = 0;
    int kthSmallest(TreeNode* root, int k) {
        midfor(root, k);
        return res;
    }
    void midfor(TreeNode* root, int k) {
        if (!root) return;
        if (cur != k) midfor(root->left, k);
        cur++;
        if (cur == k) {
            res = root->val;
        }
        if (cur != k) midfor(root->right, k);
    }
};
