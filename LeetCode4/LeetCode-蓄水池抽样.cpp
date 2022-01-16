class Solution {
public:
    ListNode* head;
    Solution(ListNode* _head) {
        head = _head;
    }
    int getRandom() {
        int ans = 0, idx = 0;
        auto t = head;
        while (t != NULL) {
            idx++;
            if (rand() % idx == 0) ans = t->val;
            t = t->next;
        }
        return ans;
    }