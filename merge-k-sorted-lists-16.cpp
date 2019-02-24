// https://leetcode.com/problems/merge-k-sorted-lists/

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
    typedef ListNode LN;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        
        int k = 1 + log2(lists.size());
        for(int i = 0; i < k; i++){
            int offset = (1 << i);
            for(int j = 0; j + offset < lists.size(); j += 2*offset){
                lists[j] = merge(lists[j], lists[j + offset]);
            }
        }
        
        return lists[0];
    }
    
    LN* merge(LN* l1, LN* l2){
        LN* head = new LN(-1), *temp = head;
        
        while(l1 && l2){
            (l1->val > l2->val) ? ((head->next = l2) && (l2 = l2->next)) : ((head->next = l1) && (l1 = l1->next));
            head = head->next;
        }
        
        head->next = l1 ? l1 : l2;
        
        return temp->next;
        
    }
};
