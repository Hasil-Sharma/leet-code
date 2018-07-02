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
    
    vector<int> rightSideView(TreeNode* root) {
        // find the right most tree at every level
        vector<int> answer;
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 0});
        
        while(!stk.empty()){
            TreeNode* node = stk.top().first;
            int depth = stk.top().second;
            stk.pop();
            
            if (!node) continue;
            else if (depth == answer.size()) answer.push_back(node->val);
            else answer[depth] = node->val;
            
            depth = depth + 1;
            stk.push({node->right, depth});
            stk.push({node->left, depth});
        }
        return answer;
    }
};
