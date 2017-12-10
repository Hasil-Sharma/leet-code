//https://leetcode.com/problems/closest-leaf-in-a-binary-tree/description
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
    TreeNode* searchHelper(TreeNode* node, int k, stack<TreeNode*>& stk){
        if (!node) return NULL;
        else if (node->val == k){
            return node;
        } else {
            stk.push(node);
            TreeNode* lnode = this->searchHelper(node->left, k, stk);
            TreeNode* rnode = (!lnode) ? this->searchHelper(node->right, k, stk) : NULL;
            
            // node not found in either of the substree
            if(!lnode && !rnode){
                stk.pop();
                return NULL;
            } else return (lnode) ? lnode : rnode;
        }
    }
    
    pair<int,int> searchLeaf(TreeNode * node, int h){
        if (!node) return {0, INT_MAX};
        else if (node->left == NULL && node->right == NULL) return {node->val, h};
        
        pair<int, int> left, right;
        
        left = searchLeaf(node->left, h + 1);
        right = searchLeaf(node->right, h + 1);
        
        return (left.second > right.second) ? right : left;
        
    }
    int findClosestLeaf(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        int h = 0;
        TreeNode* node = this->searchHelper(root, k, stk);
        pair<int,int> ans = this->searchLeaf(node, h++);
        
        while(!stk.empty()){
            TreeNode* parent = stk.top(); stk.pop();
            pair<int, int> temp = {0, INT_MAX};
            
            // to avoid reading the node part again
            if (parent->left && parent->left->val == node->val) {
                temp = this->searchLeaf(parent->right, h++);
            } else if (parent->right && parent->right->val == node->val){
                temp = this->searchLeaf(parent->left, h++);
            }
            ans = (temp.second < ans.second) ? temp : ans;
            node = parent;
        }
        return ans.first;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        int ret = Solution().findClosestLeaf(root, k);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
