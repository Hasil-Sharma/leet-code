// https://leetcode.com/problems/longest-harmonious-subsequence/description/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> hash;
        unordered_map<int, int> :: iterator itr;
        int ans = 0, i;
        
        for(int &i : nums) hash[i]++;
        
        for(auto &t : hash){
            for(i = -1; i <= 1; i += 2)
              if ((itr = hash.find(t.first + i)) != hash.end())
                  ans = max(ans, t.second + itr->second);
        }
        
        return ans;
    }
};
