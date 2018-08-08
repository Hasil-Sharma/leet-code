// https://www.lintcode.com/problem/inorder-successor-in-bst/description

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p, TreeNode* pp = NULL) {
        // write your code here
        if (!root) return root;
        else if (root->val > p->val) return inorderSuccessor(root->left, p, root);
        else if (root->val < p->val) return inorderSuccessor(root->right, p, pp);
        
        if (!root->right) return (pp && pp->val > root->val) ? pp : NULL;
        
        root = root->right;
        while(root->left)
            root = root->left;
        return root;
    }
};
