// https://leetcode.com/problems/merge-k-sorted-lists/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Compare {
public:
  bool operator()(ListNode*& l1, ListNode*& l2){
      return l1->val > l2->val;
  }  
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0), *ans = head;
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        int k = lists.size();
        
        for(auto l : lists){
            if (l) pq.push(l);
        }
        
        while(!pq.empty()){
            head->next = pq.top();
            pq.pop();
            if (head->next->next){
                pq.push(head->next->next);
            }
            head = head->next;
        }
        
        return ans->next;
    }
};
