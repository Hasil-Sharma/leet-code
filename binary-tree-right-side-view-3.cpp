// https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    vector<int> answer;
    vector<int> rightSideView(TreeNode* root) {
        // find the right most tree at every level
        helper(root, 0);
        return answer;
    }
    
    void helper(TreeNode* root, int depth){
        if (!root) return;
        else if (depth == answer.size())
            answer.push_back(root->val);
        else {
            answer[depth] = root->val;
        }
        
        depth = depth + 1;
        helper(root->left, depth);
        helper(root->right, depth);
    }
};
