// https://leetcode.com/problems/merge-two-sorted-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define next(p) p = p ? p->next : NULL;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0), *ans = head;
        
        while(l1 && l2){
            head->next = (l1->val < l2->val ? l1 : l2);
            next(head);
            if (l1->val < l2->val) {
                next(l1);
            } else next(l2);
        }
        
        head->next = l1 ? l1 : l2;
        
        return ans->next;
    }
};
