// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define ff(i, m, n) for(i = m; i < n; i++)
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vvi ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size(), i;
            vi temp;
            ff(i,0,size){
                root = q.front();
                q.pop();
                temp.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
