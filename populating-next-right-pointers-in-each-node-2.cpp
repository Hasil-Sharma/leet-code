// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

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
        TreeLinkNode *next = root->left;
        
        while(next){
            while(root){
                root->left->next = root->right;
                if(root->next)
                    root->right->next = root->next->left;
                root = root->next;
            }
            root = next;
            next = root->left;
        }
    }
};
