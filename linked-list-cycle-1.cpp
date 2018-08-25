// https://leetcode.com/problems/linked-list-cycle/description/

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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head ? head->next : head;
        
        while(fast && fast->next && slow != fast){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow && slow == fast;
    }
};
