// https://leetcode.com/problems/binary-search-tree-iterator/description/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack <TreeNode*> stk;
    BSTIterator(TreeNode *root) {
        stk = stack<TreeNode*>();
        iterate(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* root = stk.top();
        stk.pop();
        iterate(root->right);
        return root->val;
    }
    
    void iterate(TreeNode* root){
        while(root){
            stk.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
