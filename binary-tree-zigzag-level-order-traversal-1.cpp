// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
        int level;
        QElem(TreeNode* n, int l) : node(n), level(l) {}
    };
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int depth;
        vector<vector<int>> answer;
        queue<QElem*> q;
        
        q.push(new QElem(root, 0));
        while(!q.empty()){
            
            root = q.front()->node;
            depth = q.front()->level;
            q.pop();
            if(!root) continue;
            
            if (depth == answer.size())
                answer.push_back(vector<int>());
            
            if (depth & 1){
                answer[depth].insert(answer[depth].begin(), root->val);
            } else {
                answer[depth].push_back(root->val);
            }
            depth++;
            q.push(new QElem(root->left, depth));
            q.push(new QElem(root->right, depth));
        }
        
        return answer;
    }
};
