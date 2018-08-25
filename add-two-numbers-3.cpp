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
        ListNode *head = NULL, *ans = head; // adding a head;
        
        while(l2 || l1){
            int val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            
            if (!head){
                head = new ListNode(val % 10);
                ans = head;
            } else {
                head->next = new ListNode(val % 10);
                head = head->next;
            }
            
            carry = val / 10;
            l2 = l2 ? l2->next : l2;
            l1 = l1 ? l1->next : l1;
        }
        
        if (carry)
            head->next = new ListNode(carry);
        
        return ans;
    }
};
