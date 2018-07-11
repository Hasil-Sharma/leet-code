// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define mp(A, B) make_pair(A, B)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef stack<int> stki;
typedef queue<int> qi;
typedef deque<int> dqi;

void operator+= (int &val, vi& path){
    int ans = 0;
    for(int i : path){
        ans = ans * 10 + i;
    }
    val += ans;
}

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        vi path;
        helper(root, path, ans);
        return ans;
    }
    
    void helper(TreeNode* root, vi& path, int& ans){
        if(!root) return;
        
        path.push_back(root->val);
        
        if(!root->left && !root->right){
            ans += path;
        } else {
            helper(root->left, path, ans);
            helper(root->right, path, ans);
        }
        
        path.pop_back();
    }
};
