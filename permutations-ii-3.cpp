// https://leetcode.com/problems/permutations-ii/description/

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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ss(nums);
        vvi ans;
        
        do {
            ans.push_back(nums);
        } while (nextPermute(nums));
        
        return ans;
    }
    
    
    bool nextPermute(vi& nums){
        int n = nums.size(), i = n - 1;
        
        while(i > 0 && nums[i - 1] >= nums[i])
            i--;
        
        if (i == 0)
            return false;
        
        int j = n - 1;
        while(nums[i - 1] >= nums[j])
            j--;
        
        swap(nums[j], nums[i-1]);
        
        j = n - 1;
        
        while(i < j)
            swap(nums[i++], nums[j--]);
        return true;
    }
};
