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
        return lists.size() ? partition(lists, 0, lists.size() - 1) : NULL;
    }
    
    ListNode* partition(vector<ListNode*>& lists, int s, int e){
        if (s==e) return lists[s];
        else if (s < e){
            int m = s + (e - s) / 2;
            ListNode* l1 = partition(lists, s, m);
            ListNode* l2 = partition(lists, m + 1, e);
            return merge(l1, l2);
        }
        return NULL;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* head = new ListNode(-1), *ans = head;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        ListNode *l = l1 ? l1 : l2;
        while(l){
            head->next = l;
            l = l->next;
            head = head->next;
        }
        return ans->next;
    }
};
