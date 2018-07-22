// https://leetcode.com/problems/predict-the-winner/description/

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
typedef queue<pair<int, int>> qpii;
typedef unordered_map<int, int> mpii;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size(), f = 0, s = 0;
        return first(nums, 0, n - 1, f, s);
    }
    
    bool first(vi& nums, int start, int end, int f, int s){
        if (start > end) return f >= s;
        return !second(nums, start + 1, end, f + nums[start], s) || !second(nums, start, end - 1, f + nums[end], s);
    }
    
    bool second(vi& nums, int start, int end, int f, int s){
        if (start > end) return f < s;
        return !first(nums, start + 1, end, f, s + nums[start]) || !first(nums, start, end - 1, f, s + nums[end]);
    }
    
};
