// https://leetcode.com/problems/find-bottom-left-tree-value/description/

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
    int maxDepth = -1;
    int ans;
    int findBottomLeftValue(TreeNode* root, int depth = 0, bool left = true) {
        if (!root) return 0;
        if (left && depth > maxDepth){
            ans = root->val;
            maxDepth = depth;
        }
        findBottomLeftValue(root->left, depth + 1, root->left);
        findBottomLeftValue(root->right, depth + 1, !root->left);
        
        return ans;
    }
};
