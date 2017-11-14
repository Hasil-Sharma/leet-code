// https://leetcode.com/problems/merge-two-sorted-lists/description/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *answer = NULL, **temp;
        
        temp = &(answer);
        while(l1 && l2){
            if (l1->val < l2->val){
                *temp = l1;
                l1 = l1->next;
            } else {
                *temp = l2;
                l2 = l2->next;
            }
            
            temp = &(*temp)->next;
            
        }
        
        while(l1 || l2){
            if (l1){
                *temp = l1;
                l1 = l1->next;
            } else {
                *temp = l2;
                l2 = l2->next;
            }
            temp = &(*temp)->next;
        }
        
        return answer;
    }
};
