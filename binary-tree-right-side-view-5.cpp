// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    typedef vector<int> vi;
    vector<int> rightSideView(TreeNode* root) {
        vi answer;
        helper(root, answer, 0);
        return answer;
    }
    
    void helper(TreeNode* root, vi& answer, int h){
        if(!root) return;
        else if (answer.size() == h) answer.push_back(root->val);
        helper(root->right, answer, ++h);
        helper(root->left, answer, h);
    }
};
