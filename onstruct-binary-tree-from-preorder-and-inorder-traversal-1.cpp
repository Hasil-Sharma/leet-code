// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    unordered_map<int, int> inorderIdx;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            inorderIdx[inorder[i]] = i;
        }
        int h = 0;
        return helper(preorder, h, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* helper(vector<int>& preorder, int& ps, vector<int>& inorder, int is, int ie){
        if (is > ie || ps == preorder.size()) return NULL;
        int val = preorder[ps++];
        TreeNode *root = new TreeNode(val);
        root->left = helper(preorder, ps, inorder, is, inorderIdx[val] - 1);
        root->right = helper(preorder, ps, inorder, inorderIdx[val] + 1, ie);
        return root;
    }
};
