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
        stack<pair<TreeNode*, int>> stk;
        stk.push(make_pair(root, 0));
        while(!stk.empty()){
            auto top = stk.top();
            stk.pop();
            if (!top.first)
                continue;
            if (answer.size() == top.second)
                answer.push_back(vector<int>());
            answer[top.second].push_back(top.first->val);
            stk.push(make_pair(top.first->right, top.second + 1));
            stk.push(make_pair(top.first->left, top.second + 1));
        }
        return answer;
    }
    
};
