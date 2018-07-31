// https://www.lintcode.com/problem/palindrome-linked-list/description

/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: A ListNode.
     * @return: A boolean.
     */
    bool isPalindrome(ListNode * head) {
        // write your code here
        ListNode *slow = head, *fast = head, *temp, *prev = NULL;
        if (!head || !head->next) return true;
        
        while(fast->next && fast->next->next){
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
            fast = fast->next->next;
        }
        
        if (!fast->next){
            slow = slow->next;
        } else {
            temp = slow->next;
            slow->next = prev;
            prev = temp;
        }
        while(prev && slow){
            if (prev->val != slow->val)
                return false;
            prev = prev->next;
            slow = slow->next;
        }
        
        return !prev && !slow;
    }
};
