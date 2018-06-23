// https://leetcode.com/problems/average-of-levels-in-binary-tree/description/

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<pair<TreeNode*, int>> q;
        if (!root) 
            return ans;
        
        q.push({root, 0});
        while(!q.empty()){
            auto front = q.front();
            
            if (!front.first){
                q.pop();
                continue;
            }
            
            long temp = 0;
            int count = 0;
            
            while(!q.empty() && q.front().second == front.second){
                front = q.front();
                q.pop();
                if (!front.first)
                    continue;
                
                temp += front.first->val;
                count++;
                q.push({front.first->right, front.second + 1});
                q.push({front.first->left, front.second + 1});

            }
            
            ans.push_back(temp * (double) 1.0 / count);
        }
        return ans;
    }
};
