// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/

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
    struct Elem {
        TreeNode* node;
        int h;
        Elem(TreeNode* n, int v) : node(n), h(v) {}
    };
    
    int minDepth(TreeNode* root) {
        stack<Elem*> q;
        if(!root) return 0;
        int ans = INT_MAX, temp;
        
        q.push(new Elem(root, 1));
        
        while(!q.empty()){
            auto top = q.top();
            q.pop();
            root = top->node;
            temp = top->h;
            if (!root->left && !root->right){
                ans = min(ans, temp);
            }
            
            if(root->left) q.push(new Elem(root->left, temp + 1));
            if(root->right) q.push(new Elem(root->right, temp + 1));
        }
        
        return ans;
    }
    
};
