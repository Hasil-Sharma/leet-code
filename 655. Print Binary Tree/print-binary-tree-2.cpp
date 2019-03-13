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
    int getHeight(TreeNode* root){
        if (!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    
    int getMid(int a, int b){
        return a + (b - a) / 2;
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int m = getHeight(root), n = (1<<m) - 1, i = 0;
        vvs ans = vvs(m, vs(n, ""));
        queue<tuple<TreeNode*, int, int>> qq;
        
        qq.push(make_tuple(root, 0, n - 1));
        
        while(!qq.empty()){
            int size = qq.size();
            while(size--){
                auto elem = qq.front();
                auto node = get<0>(elem);
                qq.pop();
                int m = getMid(get<1>(elem), get<2>(elem));
                ans[i][m] = to_string(node->val);
                if (node->left)
                    qq.push(make_tuple(node->left, get<1>(elem), m - 1));
                if (node->right)
                    qq.push(make_tuple(node->right, m + 1, get<2>(elem)));
            }
            
            ++i;
        }
        
        return ans;
    }
};
