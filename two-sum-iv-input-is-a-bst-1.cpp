// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

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
    unordered_set<int> numSeen;
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        else if (numSeen.count(k - root->val)) return true;
        numSeen.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};
