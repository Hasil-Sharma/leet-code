// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

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
        TreeNode* answer = NULL;
        helper(root, p, q, answer);
        return answer;
    }
    
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& answer){
        if (!root || answer) return false; // if root is null or answer has been found
        bool l = helper(root->left, p, q, answer);
        bool r = helper(root->right, p, q, answer);
        if ((l && r) || ((l || r) && (root == p || root == q)) ){
            // if p and q are found in both l and r, root is the anwer
            // if p or q is found in l or r and root equals equals one of them them root is answer
            answer = root;
        }
        return l || r || (root == p || root == q);
    }
};
