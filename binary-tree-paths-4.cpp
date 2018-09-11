// https://leetcode.com/problems/binary-tree-paths/description/

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
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
#define ss(v) sort(v.begin(), v.end())
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<string>> vvs;
typedef stack<int> stki;
typedef queue<int> qi;
typedef deque<int> dqi;
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> umpii;
typedef unordered_map<int, vi> umpiv;
typedef set<int> si;
typedef unordered_set<int> usi;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        queue<pair<TreeNode*, string>> qq;
        string ss;
        vs ans;
        if (root) qq.push(make_pair(root, to_string(root->val)));
        
        while(!qq.empty()){
            root = qq.front().first; ss = qq.front().second;
            qq.pop();
            if (!root->left && !root->right){
                ans.push_back(ss);
            } else {
                if (root->right) {
                    string ss1 = ss + "->"  + to_string(root->right->val);
                    qq.push(make_pair(root->right, ss1));
                }
                
                if (root->left) {
                    string ss1 = ss + "->" + to_string(root->left->val);
                    qq.push(make_pair(root->left, ss1));
                }
            }
        }
        
        return ans;
    }
};
