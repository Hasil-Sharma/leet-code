// https://leetcode.com/problems/contiguous-array/description/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int p = 0, ans = 0, i = 0;
        unordered_map<int, int> countMap;
        countMap[0] = -1;
        
        for(int n : nums){
            p += n ? 1 : -1;
            if (countMap.count(p))
                ans = max(ans, i - countMap[p]);
            else countMap[p] = i;
            i++;
        }
        return ans;
    }
};
