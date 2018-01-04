// https://leetcode.com/problems/intersection-of-two-linked-lists/description/
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
    int getLen(ListNode* head){
        int len = 0;
        for(;head; head = head->next) len++;
        return len;
    }
    
    void traverse(ListNode ** headp, int diff){
        ListNode* head = (*headp);
        for(int i = 0; i < diff; i++) head = head->next;
        *headp = head;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLen(headA), lenB = getLen(headB), diff = abs(lenA - lenB);
        traverse((lenA > lenB) ? &headA : &headB, diff);
        // now both headA and headB are heads of equal length linkedList
        while(headA && headB){
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};

