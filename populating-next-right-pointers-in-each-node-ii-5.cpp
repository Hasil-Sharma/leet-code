// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    
    void connect(TreeLinkNode *root) {
        TreeLinkNode *curr, *next, *temp;
        
        if(!root) return;
    
        curr = root;
        
        while(curr){
            next = NULL;
            while(curr && !next){
                next = curr->left ? curr->left : curr->right;
                if (!next) curr = curr->next;
            }
            temp = next;
            
            while(curr && temp){
                if (curr->left && curr->left != temp)
                    temp->next = curr->left;
                else if (curr->right && curr->right != temp){
                    temp->next = curr->right;
                    curr = curr->next;
                }
                if (temp->next) temp = temp->next;
                else curr = curr->next;
            }
            
            curr = next;
        }
    }
};
