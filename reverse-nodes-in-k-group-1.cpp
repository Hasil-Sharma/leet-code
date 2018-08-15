// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;
        int c = 1;
        ListNode* p1 = new ListNode(0), *p2 = head, *ans = p1, *temp;
        p1->next = head;
        
        while(p2 && p2->next){
            p2 = p2->next;
            c++;
            if (c == k){
                temp = p1->next;
                p1->next = reverse(p1->next, p2);
                p1 = temp;
                p2 = p1->next;
                c = 1;
            }
        }
        return ans->next;
    }
    
    ListNode* reverse(ListNode* p1, ListNode* p2){
        ListNode* prev = p2->next, *temp;
        
        while(p1 != p2){
            temp = p1->next;
            p1->next = prev;
            prev = p1;
            p1 = temp;
        }
        p2->next = prev;
        return p2;
    }
};
