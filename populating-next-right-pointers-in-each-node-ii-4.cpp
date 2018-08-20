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
        TreeLinkNode *head = NULL;
        if (!root) return;
        while(root) {
            if (root->left || root->right) {
                if (root->left){
                    if (!head) head = root->left;
                    if (root->right) 
                        root->left->next = root->right;
                    else attach(root->left, root);
                }

                if (root->right){
                    if (!head) head = root->right;
                    attach(root->right, root);
                }
            }
            root = root->next;
        }
        
        connect(head);
    }
    
    void attach(TreeLinkNode* node, TreeLinkNode* root){
        while(root->next && !node->next){
            root = root->next;
            if (root->left || root->right)
                node->next = root->left ? root->left : root->right;
        }
    }
};
