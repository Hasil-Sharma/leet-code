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
       int k = lists.size();
        return merge(lists, 0, k - 1);
    }

private:
    ListNode* merge(vector<ListNode*>& lists, int l, int r){
        if (l > r) return NULL;
        else if (r == l) return lists[l];
        int m = l + (r - l)/2;
        ListNode* left = merge(lists, l, m);
        ListNode* right = merge(lists, m+1, r);
        return mergeList(left, right);
    }
    
    ListNode* mergeList(ListNode* left, ListNode* right){
        ListNode* ans = new ListNode(-1), *head = ans;
        
        while(left || right){
            if (left && right){
                if (left->val > right->val){
                    head->next = right;
                    right = right->next;
                } else {
                    head->next = left;
                    left = left->next;
                }
            } else {
                left = left ? left : right;
                right = NULL;
                head->next = left;
                left = left->next;
            }
            head = head->next;
        }
        return ans->next;
    }
};
