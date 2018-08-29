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
    
    struct cmp {
        bool operator()(ListNode*& l1, ListNode*& l2){
            return l2->val < l1->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(-1), *head = ans;
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for(auto list : lists)
            if (list)
            pq.push(list);
        
        while(pq.size()){
            auto top = pq.top();
            pq.pop();
            
            head->next = top;
            head = head->next;
            
            if (top->next)
                pq.push(top->next);
        }
        
        return ans->next;
    }
};
