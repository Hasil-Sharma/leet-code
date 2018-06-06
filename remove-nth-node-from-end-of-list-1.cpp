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
        
        // 1->2, n = 1, 1->NULL
        // 1->2, n = 2, 2->NULL
        // 1->2->3->4->5, n = 2, 1->2->3->5
        
        ListNode *start = head, *end = head, *temp;
        while(--n){
            end = end->next;
        }
        
        // difference between start and end is now n
        while(end->next != NULL){
            temp = start;
            start = start->next;
            end = end->next;
        }
        
        // start points to nth element from end now;
        if (start == head){
            // we'll have to change the head
            head = start->next;
        } else if (start == end){
            // remove the last element
            temp->next = NULL;
        } else {
            // remove the element at start
            temp->next = start->next;
        }
        return head;
    }
};
