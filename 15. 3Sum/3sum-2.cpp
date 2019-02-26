//https://www.lintcode.com/problem/3sum/description

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
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
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> umpii;
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
    pii find(vi& nums, int key, int start){
        int end = nums.size() - 1;
        while(end > start){
            int sum = nums[start] + nums[end];
            if (key == sum) return {start, end};
            if (key > sum) end--;
            else start++;
        }
        return {-1, -1};
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vvi ans;
        int n = nums.size();
        if (n <= 2) return ans;
        
        sort(nums.begin(), nums.end());
        
        int i, j, k;
        
        ff(i, 0, n){
            if (i > 0 && nums[i] == nums[i-1]) 
                continue;
            int temp = -nums[i];
            int j = i + 1, k = n - 1;
            while(k > j){
                if (nums[k] + nums[j] + nums[i] == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(nums[j] == nums[j - 1]) j++;
                    k--;
                    while(nums[k] == nums[k + 1]) k--;
                } else if (nums[j] + nums[k] > temp) k--;
                else j++;
            }
        }
        
        return ans;
    }
};
