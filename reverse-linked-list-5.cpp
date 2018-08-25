// https://leetcode.com/problems/reverse-linked-list/description/
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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *next = NULL;
        
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
};
