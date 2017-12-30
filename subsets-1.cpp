// https://leetcode.com/problems/subsets/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<int>& temp, int i, vector<int>& nums, vector<vector<int>>& answer){
        answer.push_back(temp);
        for(int j = i ; j < nums.size(); j++){
            temp.push_back(nums[j]);
            this->helper(temp, j + 1, nums, answer);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> temp;
        this->helper(temp, 0, nums, answer);
        return answer;
    }
};

