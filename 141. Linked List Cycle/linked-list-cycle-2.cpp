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
        ListNode* slow = head;
        ListNode* fast = head ? head->next : NULL;
        
        while(slow && fast && slow != fast){
            slow = slow->next;
            fast = fast && fast->next ? fast->next->next : NULL;
        }
        
        return slow && fast && slow == fast;
    }
};
