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
        if (!root || !root->left) return; // entire level is empty since it is complete binary tree
        root->left->next = root->right; // for left child
        if (root->next)
            root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }
};
