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
    unordered_map<RandomListNode*, RandomListNode*> ump;
    
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        if (ump.count(head)) return ump[head];
        
        RandomListNode* node = new RandomListNode(head->label);
        ump[head] = node;
        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);
        return node;
    }
};
