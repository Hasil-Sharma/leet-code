// https://leetcode.com/problems/count-complete-tree-nodes/submissions/1

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
    enum Side {LEFT, RIGHT};
    int getHeight(TreeNode* root, Side side){
        int h = 0;
        if (side == LEFT){
            while(root->left){
                h++;
                root = root->left;
            }
        } else {
            while(root->right){
                h++;
                root = root->right;
            }
        }
        
        return h;
    }
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int L = getHeight(root, LEFT), R = getHeight(root, RIGHT);
        if (L == R){
            // this is a complete binary tree
            return (1 << (L + 1)) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
