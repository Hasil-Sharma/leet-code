// https://leetcode.com/problems/3sum/description/

#define mp(A, B) make_pair(A, B)
#define ff(i, m, n) for(i = m; i < n; i++)
#define ffr(i, m, n) for(i = m; i >= n; i--)
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vvi ans;
        int i, n = nums.size();
        sort(nums.begin(), nums.end());
        ff(i, 0, n){
            int p1 = i + 1, p2 = n - 1;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            while(p1 < p2){
                if (p1 > i + 1 && nums[p1 - 1] == nums[p1]) p1++;
                else if (p2 < n - 1 && nums[p2 + 1] == nums[p2]) p2--;
                else {
                    int sum = nums[p1] + nums[p2];
                    if (sum == -nums[i])
                        ans.push_back({nums[i], nums[p1], nums[p2]});
                    if (sum >= -nums[i]) p2--;
                    if (sum <= -nums[i]) p1++;
                }
            }
        }
        return ans;
    }
};
