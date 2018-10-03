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
        unordered_map<RandomListNode*, RandomListNode*> ump;
        RandomListNode* ans = new RandomListNode(-1), *curr = ans, *temp = head;
        
        while(temp){
            curr->next = new RandomListNode(temp->label);
            ump[temp] = curr->next;
            curr = curr->next;
            temp = temp->next;
        }
        
        curr = ans->next;
        temp = head;
        
        while(temp){
            curr->random = temp->random ? ump[temp->random] : NULL;
            temp = temp->next;
            curr = curr->next;
        }
        
        return ans->next;
    }
};
