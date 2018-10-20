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
        if (!head) return head;
        ListNode *slow = head, *fast = head;
        
        slow = slow->next;
        fast = fast->next ? fast->next->next : NULL;
        
        while(fast && slow != fast){
            slow = slow->next;
            fast = fast->next ? fast->next->next : NULL;
        }
        
        if(slow && fast && slow == fast){
            slow = head;
            while(slow != fast){
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
        
        return NULL;
    }
};
