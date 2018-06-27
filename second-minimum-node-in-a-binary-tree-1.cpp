// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/

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
    int findSecondMinimumValue(TreeNode* root) {
        int ans = -1;
        if (!root->left) return ans;
        int curr = root->val;
        int left, right;
        if (root->left->val == curr && root->right->val == curr){
            
            left = findSecondMinimumValue(root->left);
            ans = (ans != -1 && left != -1) ? min(ans, left) : max(ans, left);
            
            right = findSecondMinimumValue(root->right);
            ans = (ans != -1 && right != -1) ? min(ans, right) : max(ans, right);
        } else if (root->left->val == curr){
            // root->right is not == curr
            left = findSecondMinimumValue(root->left);
            ans = (ans != -1 && left != -1) ? min(ans, left) : max(ans, left);
            
            ans = (ans != -1) ? min(ans, root->right->val) : max(ans, root->right->val);
            right = findSecondMinimumValue(root->right);
            ans = (right != -1 && ans != -1) ? min(right, ans) : max(ans, right);
        } else if (root->right->val == curr){
            
            right = findSecondMinimumValue(root->right);
            ans = (right != -1 && ans != -1) ? min(right, ans) : max(ans, right);
            
            ans = (ans != -1) ? min(ans, root->left->val) : max(ans, root->left->val);
            left = findSecondMinimumValue(root->left);
            ans = (left != -1 && ans != -1) ? min(left, ans) : max(left, ans);

        } else if (root->right->val > root->left->val){
            ans = (ans != -1) ? min(ans, root->left->val) : max(ans, root->left->val);
            left = findSecondMinimumValue(root->left);
            ans = (left != -1 && ans != -1) ? min(left, ans) : max(left, ans);
        } else {
            ans = (ans != -1) ? min(ans, root->right->val) : max(ans, root->right->val);
            right = findSecondMinimumValue(root->right);
            ans = (right != -1 && ans != -1) ? min(right, ans) : max(ans, right);
        }
        return ans;
    }
};
