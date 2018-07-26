// https://www.lintcode.com/problem/reverse-linked-list/description

/**
 * Definition of singly-linked-list:
 *
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: n
     * @return: The new head of reversed linked list.
     */
    ListNode * reverse(ListNode * head) {
        // write your code here
        
        if (!head) return NULL;
        ListNode *curr = head, *prev = NULL;

        while(curr->next){
            head = curr->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }

        curr->next = prev;
        return curr;
    }
};
