// https://leetcode.com/problems/3sum/

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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vvi ans;
        ss(nums);
        
        int i = 0, k, j, n = nums.size();
        
        for(i = 0; i < n; i++){
            if (i > 0 && nums[i] == nums[i-1]) continue;
            j = i + 1;
            k = n - 1;
            
            while(j < k){
                int t = nums[i] + nums[j] + nums[k];
                if ((j > i + 1 && nums[j] == nums[j-1]) || t < 0) j++;
                else if ((k < n - 1 && nums[k] == nums[k+1]) || t > 0) k--;
                else if (t == 0) 
                    ans.push_back({nums[i], nums[j++], nums[k--]});
            }
        }
        
        return ans;
    }
};
