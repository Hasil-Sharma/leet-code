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
        if (!headA || !headB) return NULL;
        ListNode* last = addCycle(headA);
        ListNode* cycleMeet = detectCycle(headB);
        if (!cycleMeet){
            last->next = NULL;
            return NULL;
        }
        
        ListNode* intersection = findIntersect(headB, cycleMeet);
        last->next = NULL;
        return intersection;
    }

private:
    ListNode* addCycle(ListNode* A){
        ListNode* head = A;
        
        while(A->next)
            A = A->next;
        A->next = head;
        return A;
    }
    
    ListNode* detectCycle(ListNode* A){
        ListNode* slow = A, *fast = A->next;
        while(slow && fast && fast->next && slow != fast){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow == fast ? slow->next : NULL;
    }
    
    ListNode* findIntersect(ListNode* A, ListNode* fast){
        while(A != fast){
            A = A->next;
            fast = fast->next;
        }
        return fast;
    }
};
