// https://leetcode.com/problems/add-two-numbers-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* helper(ListNode* l1, ListNode* l2, int& carry){
        if (!l1) return NULL;
        ListNode* node = helper(l1->next, l2->next, carry);
        ListNode* curr = new ListNode(l1->val + l2->val + carry);
        carry = curr->val / 10;
        curr->val %= 10;
        curr->next = node;
        return curr;
    }
    
    int getLen(ListNode* l1){
        int len = 0;
        while(l1) {
            len++;
            l1 = l1->next;
        }
        return len;
    }
    
    ListNode* addPadding(ListNode* l1, int val){
        ListNode* head = val ? new ListNode(0) : NULL, *pad = head;
        while(head && --val){
            pad->next = new ListNode(0);
            pad = pad->next;
        }
        if (head) {
            pad->next = l1;
            l1 = head;
        }
        return l1;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int len1 = getLen(l1), len2 = getLen(l2);
        if (len2 > len1) {
            swap(l1, l2);
            swap(len1,  len2);
        }
        l2 = addPadding(l2, len1 - len2);
        ListNode* ans = helper(l1 , l2, carry);
        if (carry) {
            ListNode* temp = new ListNode(carry);
            temp->next = ans;
            ans = temp;
        }
        return ans;
    }
    
};
