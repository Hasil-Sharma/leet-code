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
    void enumNode(TreeNode** nodeAddr, int val){
        *nodeAddr = (TreeNode*)malloc(sizeof(TreeNode));
        (*nodeAddr)->val = val;
        (*nodeAddr)->left = (*nodeAddr)->right = NULL;
    }
    void helper(TreeNode** nodeAddr, vector<int>& nums, int start, int len){
        // start -> start index
        // len -> # of elements to consider
        if (len == 1){
          enumNode(nodeAddr, nums[start]);
        } else if (len == 2) {
            enumNode(nodeAddr, nums[start]); // nums[start] < nums[start + 1]
            enumNode(&((*nodeAddr)->right), nums[start + 1]);
        } else if (len > 2) {
            int mid = (start + len / 2);
            enumNode(nodeAddr, nums[mid]);
            helper(&((*nodeAddr)->left), nums, start, mid - start);
            helper(&((*nodeAddr)->right), nums, mid + 1, len - (mid - start + 1));
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* answer = NULL;
        helper(&answer, nums, 0, n);
        return answer;
    }
};
