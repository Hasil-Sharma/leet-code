// https://leetcode.com/problems/maximum-width-of-binary-tree/description

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
    struct RecBlock {
        TreeNode* node;
        int encode;
        int depth;
        RecBlock(TreeNode* n, int e, int d) : node(n), encode(e), depth(d) {}
    };
    
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int depth, encode;
        unordered_map<int, int> minMap;
        stack<RecBlock*> stk;
        stk.push(new RecBlock(root, 0, 0));
        
        while(!stk.empty()){
            root = stk.top()->node;
            encode = stk.top()->encode;
            depth = stk.top()->depth;
            stk.pop();
            if(!root) continue;
            else if (!minMap.count(depth))
                minMap[depth] = encode;
            ans = max(ans, encode - minMap[depth] + 1);
            encode <<= 1;
            stk.push(new RecBlock(root->right, encode + 1, depth + 1));
            stk.push(new RecBlock(root->left, encode, depth + 1));
        }
        return ans;
    }

};
