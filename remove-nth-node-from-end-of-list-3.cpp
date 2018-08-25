// // https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode *slow = head, *fast = head;
        
        while(n--)
            fast = fast->next;
        
        if (!fast) head = head->next;
        else {
            while(fast && fast->next){
                fast = fast->next;
                slow = slow->next;
            }

            slow->next = slow->next->next;
        }
        return head;
    }
    
};
