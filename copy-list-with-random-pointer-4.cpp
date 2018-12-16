// https://leetcode.com/problems/copy-list-with-random-pointer/description/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> mp;
        RandomListNode *ans = new RandomListNode(-1), *temp = ans;
        
        while(head){
            ans->next = mp.count(head) ? mp[head] : (mp[head] = new RandomListNode(head->label));
            ans->next->random = head->random ? (mp.count(head->random) ? mp[head->random] : (mp[head->random] = new RandomListNode(head->random->label))) : NULL;
            ans = ans->next;
            head = head->next;
        }
        
        return temp->next;
    }
};
