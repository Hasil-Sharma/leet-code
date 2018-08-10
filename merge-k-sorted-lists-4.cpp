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
        return merge(lists.begin(), lists.end());
    }
    
    ListNode* merge(vector<ListNode*>::iterator s, vector<ListNode*>::iterator e){
        if (s == e) return NULL;
        else if (next(s) == e) return *s;
        int m = distance(s, e) / 2;
        ListNode* left = merge(s, s + m);
        ListNode* right = merge(s + m, e);
        return mergeUtil(left, right);
    }
    
    ListNode* mergeUtil(ListNode* left, ListNode* right){
        ListNode *ans = new ListNode(0), *head = ans;
        
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
