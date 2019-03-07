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
    void compute(ListNode *l1, ListNode *l2, int &temp, int &carry){
        temp = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        carry = temp / 10;
        temp %= 10;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, temp;
        
        compute(l1, l2, temp, carry);
        
        ListNode* head = new ListNode(temp), *next;
        next = head;
        
        l1 = l1->next;
        l2 = l2->next;
        
        while(l1 && l2){
            compute(l1, l2, temp, carry);
            next->next = new ListNode(temp);
            next = next->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (!l1){
            l1 = l2;
            l2 = NULL;
        }
        
        while(l1){
            compute(l1, l2, temp, carry);
            next->next = new ListNode(temp);
            next = next->next;
            l1 = l1->next;
        }
        
        if (carry)
            next->next = new ListNode(carry);
        return head;
    }
};
