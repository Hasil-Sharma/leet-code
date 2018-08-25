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
        ListNode* temp;
        
        while(head){
            stk.push(head);
            head = head->next;
        }
        
        while(!stk.empty()){
            if (!head) {
                head = stk.top();
                temp = head;
            }
            else {
                temp->next = stk.top();
                temp = temp->next;
            }
            temp->next = NULL;
            stk.pop();
        }
        return head;
    }
};
