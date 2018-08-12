// https://leetcode.com/problems/palindrome-linked-list/description/

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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = NULL, *temp;
        while(fast && fast->next){
            fast = fast->next->next;
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        // if fast is NULL -> even length and if fast is not null means odd length
        if (fast) slow = slow->next;
        while(slow && prev){
            if (slow->val != prev->val) return false;
            slow = slow->next;
            prev = prev->next;
        }
        
        return !slow && !prev;
    }
};
