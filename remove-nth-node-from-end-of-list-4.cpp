// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
        ListNode *start = head, *end = head, *prev;
        // moving end by n
        while(n--) end = end->next;
        
        while(end && end->next){
            start = start->next;
            end = end->next;
        }
        
        if (!end){
            head = start->next;
        } else {
            end = start->next->next;
            start->next = end;
        }
        
        return head;
    }
};
