// https://www.lintcode.com/problem/closest-binary-search-tree-value/description

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
    int closestValue(TreeNode * root, double target) {
        // write your code here
        double nDiff;
        int ans = root->val, temp;
        nDiff = root->val - target;
        
        if (nDiff > 0 && root->left){
            temp = closestValue(root->left, target);
            ans = (abs(target - temp) < abs(nDiff)) ? temp : ans;
        } else if (nDiff < 0 && root->right){
            temp = closestValue(root->right, target);
            ans = (abs(target - temp) < abs(nDiff)) ? temp : ans;
        }
        
        return ans;
        
    }
};
