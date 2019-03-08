//

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
    vector<vector<int>> permute(vector<int>& nums) {
        vvi ans;
        if (nums.size()) permute(ans, nums, 0);
        return ans;
    }
    
    void permute(vvi& ans, vi& nums, int idx){
        queue<pair<vi, int>> qq;
        qq.push({nums, idx});
        
        while(!qq.empty()){
            int size = qq.size();
            
            while(size--){
                auto front = qq.front();
                
                qq.pop();
                vi temp = get<0>(front);
                int idx = get<1>(front);
                if (idx == nums.size()) ans.push_back(temp);
                    
                for(int i = idx; i < temp.size(); i++){
                    swap(temp[i], temp[idx]);
                    qq.push({temp, idx + 1});
                    swap(temp[i], temp[idx]);
                }
            }
        }
    }
};
