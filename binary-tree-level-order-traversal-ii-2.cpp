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
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> full, empty;
        
        ans.insert(ans.begin(), {root->val});
        full.push(root);
        
        while(!full.empty()){
            while(!full.empty()){
                auto top = full.front();
                full.pop();
                if (!top) continue;
                empty.push(top->left);
                empty.push(top->right);    
            }
            
            vector<int> temp;
            while(!empty.empty()){
                auto top = empty.front();
                empty.pop();
                if (!top) continue;
                temp.push_back(top->val);
                full.push(top);
            }
            
            if (!full.empty()){
                ans.insert(ans.begin(), temp);
            }
        }
        
        return ans;
    }
};
