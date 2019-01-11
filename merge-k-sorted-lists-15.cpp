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
        return divide(lists, 0, n - 1);
    }
    
    ListNode* divide(vector<ListNode*>& lists, int l, int r){
        // cout << l << " " << r << endl;
        if (l > r) return NULL;
        else if (l == r) return lists[l];
        int m = l + (r - l)/2;
        ListNode* left = divide(lists, l, m);
        ListNode* right = divide(lists, m + 1, r);
        return conquer(left, right);
    }
    
    
    ListNode* conquer(ListNode* left, ListNode* right){
        ListNode *ans = new ListNode(-1), *head = ans;
        
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
