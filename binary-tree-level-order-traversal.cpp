// https://leetcode.com/problems/binary-tree-level-order-traversal/description/
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
    void insertToAnswer(vector<vector<int>>& answer, pair<TreeNode*, int> p){
        if(answer.size() - 1 == p.second){
            answer.back().push_back(p.first->val);
        } else {
            answer.push_back(vector<int>(1, p.first->val));
        }
    }
    
    void insertTreeNodeToQueue(queue<pair<TreeNode*, int>>& q, pair<TreeNode*, int> p){
        if(p.first){
            q.push(p);
        }
    }
    void insertToQueue(queue<pair<TreeNode*, int>>& q){
        insertTreeNodeToQueue(q, {q.front().first->left, q.front().second + 1});
        insertTreeNodeToQueue(q, {q.front().first->right, q.front().second + 1});
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> answer;
        queue<pair<TreeNode*, int>> q;
        insertTreeNodeToQueue(q, {root, 0});
        while(!q.empty()){
            insertToAnswer(answer, q.front());
            insertToQueue(q);
            q.pop();
        }
        return answer;
    }
};

