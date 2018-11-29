// https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1), *head = ans;
        int carry = 0;
        
        while(l1 || l2 || carry){
            ans->next = new ListNode((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry);
            carry = ans->next->val / 10;
            ans->next->val = ans->next->val % 10;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            ans = ans->next;
        }
        
        return head->next;
    }
};
