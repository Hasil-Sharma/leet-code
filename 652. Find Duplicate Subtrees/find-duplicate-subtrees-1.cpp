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

private:
    unordered_map<string, int> possible_trees;

    string traversal(TreeNode* node, vector<TreeNode*> &ans){
        if (!node) return "#";

        string str = traversal(node->left, ans) + ","  + traversal(node->right, ans) + "," + to_string(node->val);

        if (possible_trees[str] == 1) ans.push_back(node);

        possible_trees[str]++;
        return str;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;

        traversal(root, ans);

        return ans;
    }
};
