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
        RandomListNode *ans = new RandomListNode(-1), *curr = ans;
        
        while(head){
            if (ump.count(head)){
                curr->next = ump[head];
            } else {
                curr->next = new RandomListNode(head->label);
                ump[head] = curr->next;
            }
            
            if(head->random){
                if (ump.count(head->random)){
                    curr->next->random = ump[head->random];
                } else {
                    curr->next->random = head->random ? new RandomListNode(head->random->label) : NULL;
                    ump[head->random] = curr->next->random;
                }
            }
            
            curr = curr->next;
            head = head->next;
        }
       
        return ans->next;
    }
};
