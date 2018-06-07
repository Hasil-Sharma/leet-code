// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/

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
    // [start, end)
    TreeNode* sortedArrayToBST(vector<int>& nums, int start = 0, int end = -1 ) {
        int mid;
        
        if (end == -1) end = nums.size();
        if (start >= end) return NULL;
        
        mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        if (mid != start){
            root->left = sortedArrayToBST(nums, start, mid);
            root->right = sortedArrayToBST(nums, mid + 1, end);
        }
        
        return root;
    }
};
