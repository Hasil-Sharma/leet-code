// https://leetcode.com/problems/merge-k-sorted-lists/description/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        ListNode *head = new ListNode(-1), *ans = head;
        for(auto list: lists)
            if (list) pq.push(list);
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            
            head->next = top;
            head = head->next;
            
            if (top->next)
                pq.push(top->next);
        }
        
        return ans->next;
    }
private:
    struct cmp {
        bool operator()(ListNode* l1, ListNode * l2){
            return l1->val > l2->val;
        }
    };
};
