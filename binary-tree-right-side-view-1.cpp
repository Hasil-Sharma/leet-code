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
    
    unordered_map<int, bool> levelCovered;
    vector<int> answer;
    
    vector<int> rightSideView(TreeNode* root) {
        // find the right most tree at every level
        helper(root, 0);
        return answer;
    }
    
    void helper(TreeNode* root, int depth){
        if (!root) return;
        else if (!levelCovered.count(depth)){
            levelCovered[depth] = true;
            answer.push_back(root->val);
        }
        
        helper(root->right, depth + 1);
        helper(root->left, depth + 1);
    }
};
