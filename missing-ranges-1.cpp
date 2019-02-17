// https://leetcode.com/problems/missing-ranges/description/

class Solution {
public:
    
    string getOutput(int a, int b){
        if (a == b)
            return to_string(a);
        return to_string(a) + "->" + to_string(b); 
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        long long prev = lower, next, n = nums.size();
        
        for(long long num : nums){
            if (prev < num){
                ans.push_back(getOutput(prev, num - 1));
            }
            
            prev = num + 1;
        }
        
        if (upper >= prev){
            ans.push_back(getOutput(prev, upper));
        }
        
        return ans;
    }
};
