// https://leetcode.com/problems/merge-k-sorted-lists/description/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int amount = lists.size(), interval = 1;
        while(interval < amount){
            for(int i = 0; i < amount - interval; i += interval*2)
                lists[i] = merge(lists[i], lists[i + interval]);
            interval = interval * 2;
        }
        
        return amount ? lists[0] : NULL;
    }
    
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* ans = new ListNode(-1), *head = ans;
        
        while(left && right){
            if (left->val > right->val){
                head->next = right;
                right = right->next;
            } else {
                head->next = left;
                left = left->next;
            }
            head = head->next;
        }
        
        head->next = left ? left : right;
        return ans->next;
    }
};
