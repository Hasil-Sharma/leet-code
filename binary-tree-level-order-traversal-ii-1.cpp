// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
class Solution {
public:
    void helper(TreeNode* root, vector<vector<int>>& ans, int h){
        if(!root) return;
        else if (ans.size() == h - 1) ans.push_back(vector<int>());
        
        ans[h - 1].push_back(root->val);
        helper(root->left, ans, h + 1);
        helper(root->right, ans, h + 1);
        
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> answer;
        helper(root, answer, 1);
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};
