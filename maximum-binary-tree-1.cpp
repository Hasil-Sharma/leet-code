// https://leetcode.com/problems/maximum-binary-tree/description/

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int start = 0, int end = -2) {
        end = (end == -2) ? nums.size() - 1 : end;
        if (start > end) return NULL;
        int currMax = INT_MIN, posMax = 0;
        
        for(int i = start; i <= end; i++){
            if (nums[i] > currMax){
                currMax = nums[i];
                posMax = i;
            }
        }
        
        TreeNode* t = new TreeNode(nums[posMax]);
        t->left = constructMaximumBinaryTree(nums, start, posMax - 1);
        t->right = constructMaximumBinaryTree(nums, posMax + 1, end);
        return t;
    }
};
