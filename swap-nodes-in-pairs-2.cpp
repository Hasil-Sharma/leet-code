// https://leetcode.com/problems/swap-nodes-in-pairs/description/

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = new ListNode(-1), *temp = ans, *t;
        
        while(head && head->next){
            t = head->next->next;
            ans->next = head->next;
            ans->next->next = head;
            ans = head;
            head = t;
        }
        
        ans->next = head;
        return temp->next;
    }
};
