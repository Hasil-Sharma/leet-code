// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

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
        if (!root) return;
        TreeLinkNode* next = root,*temp;
        root->next = NULL;
        
        while(next){
            
            root = next;
            next = next->left;
            
            while(root && next){
                root->left->next = root->right;
                root->right->next = root->next ? root->next->left : NULL;
                root = root->next;
            }
        }
    }
};
