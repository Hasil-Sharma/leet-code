// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    unordered_map<int, int> inidx;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++)
            inidx[inorder[i]] = i;
        
        int h = postorder.size() - 1;
        return helper(postorder, h, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode* helper(vector<int>& postorder, int & pi, vector<int>& inorder, int is, int ie){
        if (is > ie || pi < 0) return NULL;
        int val = postorder[pi--];
        TreeNode* root = new TreeNode(val);
        root->right = helper(postorder, pi, inorder, inidx[val] + 1, ie);
        root->left = helper(postorder, pi, inorder, is, inidx[val] - 1);
        return root;
    }
};
