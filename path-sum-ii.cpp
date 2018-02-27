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
    void helper(TreeNode* root, int sum, vector<int>& temp, vector<vector<int>>& answer){
        if (root == NULL) return;
        
        temp.push_back(root->val);
        int curr_sum = sum - root->val;
        
        if (curr_sum == 0 && !(root->left || root->right)) answer.push_back(temp);
        else {
            helper(root->left, curr_sum, temp, answer);
            helper(root->right, curr_sum, temp, answer);
        }
        
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> answer;
        vector<int> temp;
        helper(root, sum, temp, answer);
        return answer;
    }
};
