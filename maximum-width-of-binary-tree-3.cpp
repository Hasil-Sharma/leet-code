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
        int depth, encode, currDepth = -1, startEncode;
        queue<RecBlock*> q;
        q.push(new RecBlock(root, 0, 0));
        
        while(!q.empty()){
            
            root = q.front()->node;
            encode = q.front()->encode;
            depth = q.front()->depth;
            q.pop();
            if(!root) continue;
            
            if (depth != currDepth){
                currDepth = depth;
                startEncode = encode;
            }
            
            ans = max(ans, encode - startEncode + 1);
            encode <<= 1;
            depth += 1;
            q.push(new RecBlock(root->left, encode, depth));
            q.push(new RecBlock(root->right, encode + 1, depth));
        }
        return ans;
    }

};
