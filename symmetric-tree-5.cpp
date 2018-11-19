// https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> qq;
        vector<TreeNode*> temp;
        if (root) qq.push(root);
        
        while(!qq.empty()){
            int size = qq.size();
            while(size--){
                root = qq.front();
                qq.pop();
                
                temp.push_back(root->left);
                temp.push_back(root->right);
                
                if (root->left) qq.push(root->left);
                if (root->right) qq.push(root->right);
            }
            
            int i = 0, j = temp.size() - 1;
            
            while(i < j){
                if(!temp[i] && !temp[j]){
                    i++;
                    j--;
                } else if (temp[i] && temp[j] && temp[i]->val == temp[j]->val) {
                    i++;
                    j--;
                } else return false;
            }
            
            temp.clear();
        }
        
        return true;
    }
    
};
