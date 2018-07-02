// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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

    
    int sumNumbers(TreeNode* root) {
        int answer = 0;
        int temp;
        bool flag = false;
        stack<pair<TreeNode*, int>> stk;
        
        stk.push(make_pair(root, 0));
        
        while(!stk.empty()){
            root = stk.top().first;
            temp = stk.top().second;
            stk.pop();
            if(!root) continue;
            else if (!root->left && !root->right) answer += temp * 10 + root->val;
            else {
                temp = temp * 10 + root->val;
                stk.push({root->left, temp});
                stk.push({root->right, temp});
            }
        }
        return answer;
    }
    
};
