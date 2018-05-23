// https://leetcode.com/problems/subarray-sum-equals-k/description/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> preSum(nums.size(), 0);
        unordered_map<int, vector<int>> countPos;
        unordered_map<int, vector<int>>::iterator itr;
        int count = 0;
        
        preSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            preSum[i] = preSum[i - 1] + nums[i];
            countPos[preSum[i]].push_back(i);
        }
        
        for(int i = 0; i < nums.size(); i++){
            // case of nums[i:i] == k
            if (nums[i] == k) count++;
            // case of nums[0:i] == k; i > 0 to handle the case of nums[0:0]
            if (i > 0 && preSum[i] == k) count++;
            if ((itr = countPos.find(k + preSum[i])) != countPos.end()){
                // case of nums[i + 1: j] == k where j = [i + 2, i + 3, ..., n]
                vector<int> &tempVec = itr->second;
                count += (tempVec.end() - upper_bound(tempVec.begin(), tempVec.end(), i + 1));
            }
        }
        return count;
    }
};
