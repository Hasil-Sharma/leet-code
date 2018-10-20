// https://leetcode.com/problems/odd-even-linked-list/description/

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(-1), *even = new ListNode(-1);
        ListNode *h1 = odd, *h2 = even;
        int i = 0;
        
        while(head){
            i++;
            if (i % 2 == 1){
                h1->next = head;
                h1 = h1->next;
            } else {
                h2->next = head;
                h2 = h2->next;
            }
            head = head->next;
        }
        
        h2->next = NULL;
        h1->next = even->next;
        return odd->next;
    }
};
