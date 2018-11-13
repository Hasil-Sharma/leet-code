// https://leetcode.com/problems/add-two-numbers-ii/description/

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
        
        while(l1 || l2 || carry){
            int temp = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = temp / 10;
            temp = temp % 10;
            head->next = new ListNode(temp);
            head = head->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        
        return ans->next;
    }
};
