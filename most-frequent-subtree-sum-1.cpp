// https://leetcode.com/problems/most-frequent-subtree-sum/description/

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
    unordered_map<int, int> hashMap;
    int maxSum = INT_MIN;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        vector<int> ans;
        for(auto itr = hashMap.begin(); itr != hashMap.end(); itr++){
            if (itr->second == maxSum) ans.push_back(itr->first);
        }
        return ans;
    }
    
    int helper(TreeNode* root){
        if (!root) return 0;
        
        int l, r, sum = root->val;
        
        l = helper(root->left);
        r = helper(root->right);
        
        if(root->left && root->right) {
            sum += l + r;
        } else if (root->left) {
            sum += l;
        } else if (root->right){
            sum += r;
        }
        
        hashMap[sum] = hashMap[sum] + 1;
        maxSum = max(maxSum, hashMap[sum]);
        return sum;
    }
};
