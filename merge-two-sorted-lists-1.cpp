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
        ListNode* head = new ListNode(INT_MIN), *ans = head, *l;
        while(l1 && l2){
            if (l1->val < l2->val){
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        
        l = l1 ? l1 : l2;
        
        while(l){
            head->next = l;
            l = l->next;
            head = head->next;
        }
        return ans->next;
    }
};
