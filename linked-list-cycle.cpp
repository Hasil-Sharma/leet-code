// https://leetcode.com/problems/linked-list-cycle/description/
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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        bool flag = false;
        while(slow && fast && fast->next && !flag){
            slow = slow->next;
            fast = fast->next->next;
            flag = (slow == fast) ? true : false;
        }
        return flag;
    }
};

