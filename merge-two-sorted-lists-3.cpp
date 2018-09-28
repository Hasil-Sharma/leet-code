// https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(-1), *head = ans;
        
        while(l1 || l2){
            if (l1 && l2){
                if (l1->val > l2->val){
                    head->next = l2;
                    l2 = l2->next;
                } else {
                    head->next = l1;
                    l1 = l1->next;
                }
            } else {
                l1 = l1 ? l1 : l2;
                l2 = NULL;
                head->next = l1;
                l1 = l1->next;
            }
            
            head = head->next;
        }
        return ans->next;
    }
};
