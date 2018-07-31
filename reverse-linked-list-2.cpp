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
        stack<ListNode*> stk;
        ListNode* ans;
        if (!head) return head;
        while(head->next){
            stk.push(head);
            head = head->next;
        }
        
        ans = head;
        while(!stk.empty()){
            head->next = stk.top();
            stk.pop();
            head = head->next;
        }
        
        head->next = NULL;
        return ans;
    }
};
