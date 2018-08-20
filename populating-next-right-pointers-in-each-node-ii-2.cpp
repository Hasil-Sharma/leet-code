// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
        TreeLinkNode* next;
        if (root) q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            next = NULL;
            for(int i = 0; i < size; i++){
                root = q.front();
                q.pop();
                root->next = next;
                next = root;
                if (root->right) q.push(root->right);
                if (root->left) q.push(root->left);
            }
        }
    }
};
