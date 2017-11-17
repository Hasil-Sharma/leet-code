// https://leetcode.com/problems/swap-nodes-in-pairs/description/
#include <bits/stdc++.h>
using namespace std;

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
        ListNode *answer, *first, *second;
        // in case head is NULL or 1 node linked list
        if (head == NULL || head->next == NULL) return head;
        
        // Swapping first two terms
        answer = head->next;
        head->next = head->next->next;
        answer->next = head;
        
        first = answer->next;
        
        // For swapping i and i + 1 need pointers to i - 1 and i
        while(true){
            second = first->next;
            
            // Case of even or add elements
            if (second == NULL || second->next == NULL)
                break;
            
            first->next = second->next;
            second->next = first->next->next;
            first->next->next = second;
            
            first = second;
        }
        return answer;
        
    }
};
