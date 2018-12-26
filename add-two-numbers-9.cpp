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
        int carry = 0, val;
        while (l1 || l2 || carry){
            val = carry;
            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }
            
            if (l2){
                val += l2->val;
                l2 = l2->next;
            }
            carry = val/10;
            val = val % 10;
            head->next = new ListNode(val);
            head = head->next;
        }
        
        return ans->next;
    }
};
