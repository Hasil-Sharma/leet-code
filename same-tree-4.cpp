// https://leetcode.com/problems/same-tree/description/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> qq;
        qq.push({p, q});
        while(!qq.empty()){
            auto front = qq.front();
            qq.pop();
            p = front.first; q = front.second;
            if (!p && !q) continue;
            else if (p && q && p->val == q->val){
                qq.push({p->left, q->left});
                qq.push({p->right, q->right});
            } else return false;
        }
        
        return true;
    }
};
