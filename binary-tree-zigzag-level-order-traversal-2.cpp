// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bool flag = false;
        
        queue<TreeNode*> q;
        
        if(root) q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            deque<int> temp;
            while(size--){
                root = q.front();
                q.pop();
                if (!flag) temp.push_back(root->val);
                else temp.push_front(root->val);
                if (root->left)
                    q.push(root->left);
                if (root->right)
                    q.push(root->right);
            }
            ans.push_back({temp.begin(), temp.end()});
            flag = (!flag);
        }
        return ans;
    }
};
