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
        int n = lists.size();
        
        return merge(lists, 0, n - 1);
    }
    
    
    ListNode* merge(vector<ListNode*>& lists, int s, int e){
        if (s > e) return NULL;
        else if (s == e) return lists[s];
        else {
            int m = s + (e - s) / 2;
            ListNode* left = merge(lists, s, m);
            ListNode* right = merge(lists, m + 1, e);
            return helper(left, right);
        }
    }
    
    
    ListNode* helper(ListNode* left, ListNode* right){
        ListNode* ans = new ListNode(-1), *head = ans;
        
        while(left && right){
            if (left->val < right->val){
                head->next = left;
                left = left->next;
            } else {
                head->next = right;
                right = right->next;
            }
            
            head = head->next;
        }
        
        head->next = left ? left : right;
        
        return ans->next;
    }
};
