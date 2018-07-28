// https://www.lintcode.com/problem/merge-k-sorted-lists/description

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */

struct cmp {
    bool operator()(const ListNode* l1, const ListNode* l2) const {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(auto e : lists){
            if(e)
            pq.push(e);
        }
        
        ListNode *ans = new ListNode(0), *temp = ans;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            temp->next = top;
            temp = temp->next;
            if (top->next)
                pq.push(top->next);
        }
        return ans->next;
    }
};


