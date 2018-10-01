// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // making sure p is greater than q
        if (p->val < q->val) swap(p, q);
        
        while(root){
            if (root->val > p->val) root = root->left;
            else if (root->val < q->val ) root = root->right;
            else break;
        }
        
        return root;
    }
};
