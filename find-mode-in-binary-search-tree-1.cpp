// https://leetcode.com/problems/find-mode-in-binary-search-tree/description/

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
    unordered_map<int, int> hashTable;
    int maxCount = 0;
    
    vector<int> findMode(TreeNode* root) {
        vector<int> answer;
        helper(root);
        
        for(auto itr = hashTable.begin(); itr != hashTable.end(); itr++){
            if (itr->second == maxCount)
                answer.push_back(itr->first);
        }
        
        return answer;
    }
    
    void helper(TreeNode* root){
        if (!root) return;
        hashTable[root->val] = hashTable[root->val] + 1;
        maxCount = max(maxCount, hashTable[root->val]);
        helper(root->left);
        helper(root->right);
    }
};
