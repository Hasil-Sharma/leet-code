// https://leetcode.com/problems/linked-list-cycle-ii/description/

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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *slow = head, *fast = head;
        
        do {
            slow = slow->next;
            fast = (fast->next ? fast->next->next : NULL);
        } while(fast && slow != fast);
        
        // in case fast is null
        if (!fast) 
            return fast;
        
        slow = head;
        // now slow and fast are same distance from the loop starting
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};
