// https://leetcode.com/problems/validate-binary-search-tree/description/
#include <bits/stdc++.h>
using namespace std;

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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        bool flag = true, push_left = true;
        vector<int> traversal;
        int item;
        if(root) stk.push(root);
        
        while(!stk.empty()){
            // keep on pushing to stack till last left element is encountered
            if (push_left){
                root = stk.top();
                while(root->left){
                    stk.push(root->left);
                    root = root->left;
                }
                traversal.push_back(root->val);
                stk.pop();
                if (root->right) {
                    stk.push(root->right);
                    push_left = true;
                } else {
                    push_left = false;
                }
            } else {
                root = stk.top(); stk.pop();
                traversal.push_back(root->val);
                if(root->right) {
                    stk.push(root->right);
                    push_left = true;
                } else {
                    push_left = false;
                }
            }
        }
        
//         for(int i: traversal)
//             cout << i << endl;
        
        if (traversal.size()) item = traversal[0];
        for(int i = 1; i < traversal.size(); i++){
            if (item >= traversal[i]) return false;
            item = traversal[i];
        }
        return true;
    }
};
