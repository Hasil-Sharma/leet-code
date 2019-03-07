// https://leetcode.com/problems/permutations/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void permGen(vector<int> & nums, vector<vector<int>>& ans, vector<int> & temp){
        if (nums.size () == 0){
            ans.push_back(temp);
        } else {
            for(int i = 0; i < nums.size(); i++){
                temp.push_back(nums[i]);
                nums.erase(nums.begin() + i);
                this->permGen(nums, ans, temp);
                nums.insert(nums.begin() + i, temp.back());
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        this->permGen(nums, ans, temp);
        return ans;
    }
};

