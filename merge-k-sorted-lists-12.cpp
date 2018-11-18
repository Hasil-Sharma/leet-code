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
        return merge(lists, 0, lists.size() - 1);
    }
    
    ListNode* merge(vector<ListNode*>& lists, int s, int e){
        if (s > e) return NULL;
        if (s == e) return lists[s];
        int m = s + (e - s) / 2;
        ListNode* left = merge(lists, s, m), *right = merge(lists, m + 1, e);
        return mergeHelper(left, right);
    }
    
    ListNode* mergeHelper(ListNode* left, ListNode* right){
        ListNode *head = new ListNode(-1), *ans = head;
        
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
