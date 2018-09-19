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
        int carry = 0;
        ListNode* head = new ListNode(-1), *ans = head;
        
        while(l1 || l2){
            head->next = new ListNode((l1 ? l1->val : 0) + (l2 ? l2->val: 0) + carry);
            carry = head->next->val / 10;
            head->next->val %= 10;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
            head = head->next;
        }
        if (carry) head->next = new ListNode(carry);
        return ans->next;
    }
};
