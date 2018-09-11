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
        vvi ans;
        map<int, vi> mp;
        queue<pair<TreeNode*, int>> qq;
        if (root)
        qq.push({root, 0});
        
        while(!qq.empty()){
            root = qq.front().first; 
            int h = qq.front().second;
            qq.pop();
            mp[h].push_back(root->val);
            if (root->left)
                qq.push({root->left, h-1});
            if (root->right)
                qq.push({root->right, h+1});
        }
        
        for(auto kv : mp){
            ans.push_back(kv.second);
        }
        return ans;
    }
};
