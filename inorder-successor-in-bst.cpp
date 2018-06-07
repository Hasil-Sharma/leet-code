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
        if (!root || !p)
            return NULL;
            
        TreeNode * temp;
        unordered_map<TreeNode*, TreeNode*> parentHash;
        parentHash[root] = NULL;
        stack<TreeNode*> stk;
        stk.push(root);
        
        while(!stk.empty()){
            temp = stk.top();
            stk.pop();
            if (temp->left){
                parentHash[temp->left] = temp;
                stk.push(temp->left);
            }
            
            if (temp->right){
                parentHash[temp->right] = temp;
                stk.push(temp->right);
            }
        }
        
        if (!parentHash[p]){
            // successor of root
            // left most node in right subtree
            if (!p->right) 
                return NULL;
            return findLeftMostNode(p->right);
        } else if (p->val > parentHash[p]->val){
            // right child
            if (!p->right) {
                // possible that parent of the node is left child of its parent
                temp = parentHash[parentHash[p]];
                if (temp)
                    return (temp->val > p->val) ? temp : NULL;
                return temp;
            }
            return findLeftMostNode(p->right);
        } else if (p->val < parentHash[p]->val){
            // left child
            if (!p->right)
                return parentHash[p];
            return findLeftMostNode(p->right);
        }
    }
    
    TreeNode* findLeftMostNode(TreeNode* node){
        while(node->left){
            node = node->left;
        }
        return node;
    }
};
