// https://leetcode.com/problems/longest-consecutive-sequence/description/

typedef unordered_map<int, int> umpii;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int left, right, ans = 0;
        umpii len;
        
        for(int c : nums){
            if (len.count(c))
                continue;
            left = len.count(c-1) ? len[c-1] : 0;
            right = len.count(c+1) ? len[c+1] : 0;
            len[c] = left + right + 1;
            ans = max(ans, len[c]);
            len[c-left] = len[c];
            len[c+right] = len[c];
        }
        return ans;
    }
};
