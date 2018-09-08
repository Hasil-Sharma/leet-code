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
        ListNode *ans = NULL;
        if (head)
        helper(head, ans);
        return ans;
    }
    
    ListNode* helper(ListNode* head, ListNode*& ans){
        if (head->next){
            ListNode* temp = helper(head->next, ans);
            temp->next = head;
            head->next = NULL;
        } else {
            ans = head;
        }
        
        return head;
    }
};
