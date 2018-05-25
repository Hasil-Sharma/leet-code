// https://leetcode.com/problems/continuous-subarray-sum/description/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> remHash = {{0, -1}};
        unordered_map <int, int> :: iterator itr;
        int runningRem = 0;
        for(int i = 0; i < nums.size(); i++){
            runningRem += nums[i];
            if (k != 0) runningRem %= k;
            if ((itr = remHash.find(runningRem)) != remHash.end()) {
                if(i - itr->second > 1)
                    return true;
            }
            else remHash[runningRem] = i;
        }
        return false;
    }
};
