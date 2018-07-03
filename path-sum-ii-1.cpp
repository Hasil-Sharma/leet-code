// https://leetcode.com/problems/path-sum-ii/description/

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
    vector<vector<int>> answer;
    vector<int> temp;
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        helper(root, sum);
        return answer;
    }
    
    void helper(TreeNode* root, int sum){
        if (!root) return;
        sum -= root->val;
        temp.push_back(root->val);
        if (sum == 0 && !root->left && !root->right) answer.push_back(temp);
        else {
            helper(root->left, sum);
            helper(root->right, sum);
        }
        temp.pop_back();
    }
};
