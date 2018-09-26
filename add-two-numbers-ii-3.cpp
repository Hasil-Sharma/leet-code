// https://leetcode.com/problems/add-two-numbers-ii/description/

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
    
    void push(stack<ListNode*>& stk, ListNode* l){
        while(l){
            stk.push(l);
            l = l->next;
        }
    }
    
    int top(stack<ListNode*>& stk){
        if (stk.size()){
            int val = stk.top()->val;
            stk.pop();
            return val;
        }
        return 0;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> stk1, stk2;
        push(stk1, l1);
        push(stk2, l2);
        int carry = 0, v1, v2;
        ListNode *ans = NULL, *temp;
        
        while(!stk1.empty() || !stk2.empty() || carry){
            v1 = top(stk1);
            v2 = top(stk2);
            temp = new ListNode(v1 + v2 + carry);
            carry = temp->val/10;
            temp->val %= 10;
            temp->next = ans;
            ans = temp;
        }
        
        return ans;
    }
};
