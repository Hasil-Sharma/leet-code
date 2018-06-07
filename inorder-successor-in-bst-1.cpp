// https://www.lintcode.com/problem/inorder-successor-in-bst/description
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
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        // write your code here
        // cout << root << endl;
        // cout << p << endl;
        if(!root || !p) 
        return NULL;
        if (p == root){
            // successor of root
            // left most node in right subtree
            if (!p->right) 
                return NULL;
            return findLeftMostNode(p->right);
        } 
        
        TreeNode* parent = findParent(root, p);
        if (p->val > parent->val){
            // right child
            if (!p->right) {
                // possible that parent of the node is left child of its parent
                parent = findParent(root, parent);
                if (parent)
                    return (parent->val > p->val) ? parent : NULL;
                return parent;
            }
            return findLeftMostNode(p->right);
        } else if (p->val < parent->val){
            // left child
            if (!p->right)
                return findParent(root, p);
            return findLeftMostNode(p->right);
        }
    }
    
    TreeNode* findLeftMostNode(TreeNode* node){
        while(node->left){
            node = node->left;
        }
        return node;
    }
    
    TreeNode* findParent(TreeNode* root, TreeNode* node){
        
        while (!(root->left == node || root->right == node)){
            if (root->val > node->val)
                root = root->left;
            else root = root->right;
        }
        
        return root;
    }
};
