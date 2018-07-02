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
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if (!front.first)
                continue;
            if (answer.size() == front.second)
                answer.push_back(vector<int>());
            answer[front.second].push_back(front.first->val);
            q.push(make_pair(front.first->left, front.second + 1));
            q.push(make_pair(front.first->right, front.second + 1));
        }
        return answer;
    }
    
};
