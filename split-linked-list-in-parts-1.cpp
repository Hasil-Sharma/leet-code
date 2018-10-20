// https://leetcode.com/problems/split-linked-list-in-parts/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* prev;
        vector<ListNode*> ans(k, NULL);
        int len = 0;
        
        for(ListNode* head = root; head; len++, head = head->next);
        
        int p = len / k, r = len % k;
        
        for(int i = 0; i < k; i++, r--){
            ans[i] = root;
            for(int j = 0; j < p + (r > 0); j++){
                prev = root;
                root = root->next;
            }
            prev->next = NULL;
        }
        
        return ans;
    }
};
