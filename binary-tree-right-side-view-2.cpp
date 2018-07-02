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
    vector<int> rightSideView(TreeNode* root) {
        // find the right most tree at every level
        unordered_map<int, bool> levelCovered;
        vector<int> answer;
        stack<pair<TreeNode*, int>> stk;
        
        stk.push(make_pair(root, 0));
        
        while(!stk.empty()){
            TreeNode* node = stk.top().first;
            int depth = stk.top().second;
            stk.pop();
            if (!node) continue;
            else if (!levelCovered.count(depth)){
                levelCovered[depth] = true;
                answer.push_back(node->val);
            }
            
            depth = depth + 1;
            stk.push(make_pair(node->left, depth));
            stk.push(make_pair(node->right, depth));
        }
        return answer;
    }
};
