// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
    vector<int> postorderTraversal(TreeNode* root) {
        deque<int> answer;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            root = stk.top();
            stk.pop();
            if(!root) continue;
            answer.push_front(root->val);
            stk.push(root->left);
            stk.push(root->right);
            
        }
        return {answer.begin(), answer.end()};
    }
    
};
