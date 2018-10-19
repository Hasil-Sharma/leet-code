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
        int s = 0, e = lists.size() - 1;
        return partition(lists, s, e);
    }
    
    ListNode* partition(vector<ListNode*>& lists, int s, int e){
        if (s > e) return NULL;
        else if (s == e) return lists[s];
        int m = s + (e - s)/2;
        ListNode* left = partition(lists, s, m);
        ListNode* right = partition(lists, m + 1, e);
        return merge(left, right);
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
