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
        if(!root || (!root->left && !root->right)) return;
        TreeLinkNode * node;
        node = root;
        if(node->left){
            if (node->right){
                node->left->next = node->right;
            } else {
                root = node->next;
                while(root){
                    if (root->left){
                        node->left->next = root->left;
                        break;
                    } else if (root->right){
                        node->left->next = root->right;
                        break;
                    }
                    root = root->next;
                }
            }
        }
        
        if (node->right){
            root = node->next;
            while(root){
                if (root->left){
                    node->right->next = root->left;
                    break;
                } else if (root->right){
                    node->right->next = root->right;
                    break;
                }
                root = root->next;
            }
        }
        
        connect(node->right);
        connect(node->left);
    }
};
