// https://leetcode.com/problems/count-complete-tree-nodes/description/

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
    int height(TreeNode* root){
        int ans = -1;
        while(root){
            ans++;
            root = root->left;
        }
        return ans;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int ans = 0, h;
        
        while(root){
            h = height(root);
            if (height(root->right) == h - 1){
                ans += (1 << h);
                root = root->right;
            } else {
                ans += (1 << (h - 1));
                root = root->left;
            }
        }
        
        return ans;
    }
};
