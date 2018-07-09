// https://leetcode.com/problems/increasing-subsequences/description/

class Solution {
public:
    typedef vector<vector<int>> vvi;
    typedef vector<int> vi;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vvi answer;
        vi temp;
        unordered_set<int> seen;
        if (nums.size() == 0) 
            return answer;
        
        for(int i = 0; i < nums.size() - 1; i++){
            if (seen.count(nums[i])) continue;
            seen.insert(nums[i]);
            temp.push_back(nums[i]);
            helper(nums, temp, answer, i + 1);
            temp.pop_back();
        }
        return answer;
    }
    
    void helper(vi &nums, vi & temp, vvi & answer, int start){
        unordered_set<int> seen;
        for(int i = start; i < nums.size(); i++){
            if(temp.back() <= nums[i] && !seen.count(nums[i])){
                seen.insert(nums[i]);
                temp.push_back(nums[i]);
                answer.push_back(temp);
                helper(nums, temp, answer, i + 1);
                temp.pop_back();
            }
        }
    }
};
