//

// https://leetcode.com/problems/partition-list/description/
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *right = NULL, *left = NULL, *lans = NULL, *rans = NULL, *ans;
        int temp;
        while(head){
            temp = head->val;
            if (temp < x){
                if (left){
                    left->next = new ListNode(temp);
                    left = left->next;
                } else {
                    left = new ListNode(temp);
                    lans = left;
                }
            } else {
                if (right){
                    right->next = new ListNode(temp);
                    right = right->next;
                } else {
                    right = new ListNode(temp);
                    rans = right;
                }
            }
            head = head->next;
        }
        
        if (lans){
            left->next = rans;
            ans = lans;
        } else {
            ans = rans;
        }
        return ans;
    }
};
