// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        deque<vector<int>> ans;
        queue<TreeNode*> q;
        
        if(root) q.push(root);
        while(!q.empty()){
            
            int size = q.size();
            ans.push_front(vector<int>());
            
            for(int i = 0; i < size; i++){
                
                root = q.front();
                q.pop();
                if(!root) continue;
                ans[0].push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
                
            }
        }
        
        return {ans.begin(), ans.end()};
    }
    
};
