// https://leetcode.com/problems/delete-and-earn/description/

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
typedef unordered_map<int, int> umpii;
typedef set<int> si;
vpii steps = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
public:
    // Test case that will fail with a Greedy Algorithm - 1, 1, 1, 2 -> Choosing 2 will render a suboptimal solution
    // subproblem - choose a n, remove all n - 1 & n + 1 and call the same method again
    
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int curr = 0, prev1 = 0, prev2 = 0,  i = 0, count = 0, key, prevNum = 0;
        
        while(i < n){
            key  = nums[i];
            count = 1;
            while(nums[++i] == key) count++;
            
            // does not work ?
            // count = 0;
            // while(nums[i++] == key) count++;
            
            if (prevNum == key - 1) curr = max(count * key + prev2, prev1);
            else curr = key * count + prev1;
            
            prevNum = key;
            prev2 = prev1;
            prev1 = curr;
            
        }
        
        return curr;
    }
    
};
