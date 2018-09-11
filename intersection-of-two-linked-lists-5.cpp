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
        int lenA = getLen(headA), lenB = getLen(headB);
        if (lenA > lenB){
            swap(headA, headB);
            swap(lenA, lenB);
        }
        
        int diff = lenB - lenA;
        while(diff--)
            headB = headB->next;
        
        while(headB != headA){
            headB = headB->next;
            headA = headA->next;
        }
        
        return headA;
    }
    
    int getLen(ListNode* A){
        int len = 0;
        while(A){
            len++;
            A = A->next;
        }
        return len;
    }
};
