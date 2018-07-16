// https://leetcode.com/problems/house-robber/description/

#define mp(A, B) make_pair(A, B)
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
typedef unordered_map<int, int> mpii;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        else if (n == 1) return nums[0];
        
        int a = nums[0], b = nums[1], c;
        
        for(int i = 2; i < n; i++){
            c = b;
            b = nums[i] + max(a , b - nums[i-1]);
            a = c;
        }
        
        return max(a,b);
    }
};
