// https://leetcode.com/problems/binary-tree-vertical-order-traversal/description/

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

template <typename T>
void printVec(T const& t){
    for(auto e :  t)
        cout << e << ",";
    cout << endl;
}

class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        deque<vi> ans;
        int m = 0, h;
        queue<pair<TreeNode*, int>> q;
        if (root) q.push({root, 0});
        
        while(!q.empty()){
            root = q.front().first; h = q.front().second;
            q.pop();
            if (h < m) ans.push_front({root->val});
            else if (h - m < ans.size() )ans[h - m].push_back(root->val);
            else ans.push_back({root->val});
            m = min(h, m);
            if (root->left) q.push({root->left, h - 1});
            if (root->right) q.push({root->right, h + 1});
        }
        
        return {ans.begin(), ans.end()};
    }
};
