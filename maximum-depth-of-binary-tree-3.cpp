// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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
    int maxDepth(TreeNode* root) {
        int ans = 0;
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 0});
        
        while(!stk.empty()){
            auto top = stk.top();
            stk.pop();
            
            if (top.first == NULL){
                ans = max(ans, top.second);
                continue;
            }
            
            stk.push({top.first->left, top.second + 1});
            stk.push({top.first->right, top.second + 1});
        }
        return ans;
    }
};
