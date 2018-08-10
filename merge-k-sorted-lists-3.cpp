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
        bool operator()(ListNode* l1, ListNode* l2){
            return l1->val > l2->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        ListNode * ans = new ListNode(0), *head = ans;
        
        for(auto list : lists)
            if (list) pq.push(list);
        
        while(!pq.empty()){
            auto root = pq.top();
            pq.pop();
            if (root->next) pq.push(root->next);
            head->next = root;
            head = head->next;
        }
    
        return ans->next;
    }
};
