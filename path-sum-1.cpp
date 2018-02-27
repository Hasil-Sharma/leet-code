// https://leetcode.com/problems/path-sum/description/

class Solution {
public:
    
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        int curr_sum = sum - root->val;
        if (curr_sum == 0 && !(root->left || root->right)) return true; // if the current node is all that there is
        
        bool left =  hasPathSum(root->left, curr_sum);
        bool right = hasPathSum(root->right, curr_sum);
        
        return left || right;
    }
};
