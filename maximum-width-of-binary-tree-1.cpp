// https://leetcode.com/problems/maximum-width-of-binary-tree/submissions/1

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
    int ans;
    unordered_map<int, int> minMap;
    
    int widthOfBinaryTree(TreeNode* root) {
        ans = 0;
        helper(root, 0, 0);
        return ans;
    }
    
    void helper(TreeNode* root, int encode, int depth){
        if (!root) return;
        
        if(!minMap.count(depth)) minMap[depth] = encode;
        
        ans = max(ans, encode - minMap[depth] + 1);
        depth += 1;
        encode <<= 1;
        helper(root->left, encode, depth);
        helper(root->right, encode + 1, depth);
    }
};
