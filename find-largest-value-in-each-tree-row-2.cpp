// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

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
    
    struct QElem {
        TreeNode* node;
        int val;
        QElem(TreeNode* n, int v) : node(n), val(v) {}
    };
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<QElem*> q;
        q.push(new QElem(root, 0));
        
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            if (!front->node)
                continue;
            
            if (front->val == ans.size()) 
                ans.push_back(front->node->val);
            
            ans[front->val] = max(ans[front->val], front->node->val);
            q.push(new QElem(front->node->left, front->val + 1));
            q.push(new QElem(front->node->right, front->val + 1));
        }
        return ans;
    }
};
