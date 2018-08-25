// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tail = NULL;
        if (!headA || !headB) return NULL;
        
        tail = headA;
        
        while(tail->next){
            tail = tail->next;
        }
        
        tail->next = headA;
        
        ListNode* slow = headB, *fast = headB;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        
        if (!fast || !fast->next){
            tail->next = NULL;
            return NULL;
        }
        
        slow = headB;
        
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        tail->next = NULL;
        
        return slow;
    }
};
