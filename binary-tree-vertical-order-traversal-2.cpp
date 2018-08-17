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
typedef map<int, vi> mpiv;
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
        deque<vi> buffer;
        int min = 1;
        queue<pair<int, TreeNode*>> q;
        if (root) q.push({0, root});
        while(!q.empty()){
            int idx = q.front().first; root = q.front().second;
            q.pop();
            if (min > idx) {
                buffer.push_front({root->val});
                min = idx;
            } else if (idx - min < buffer.size()) buffer[idx - min].push_back(root->val);
            else buffer.push_back({root->val});
            
            if (root->left)
                q.push({idx - 1, root->left});
            if (root->right)
                q.push({idx + 1, root->right});
        }
        for(auto kv : buffer)
            ans.push_back(kv);
        return ans;
    }
    
};
