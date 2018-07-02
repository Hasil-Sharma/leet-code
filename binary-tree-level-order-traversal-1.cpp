// https://leetcode.com/problems/binary-tree-level-order-traversal/description

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        helper(root, answer, 0);
        return answer;
    }
    
    void helper(TreeNode* root, vector<vector<int>>& answer, int depth){
        if (!root) return;
        if (depth == answer.size()){
            answer.push_back(vector<int>());
        }
        
        answer[depth].push_back(root->val);
        helper(root->left, answer, depth + 1);
        helper(root->right, answer, depth + 1);
    }
};
