//https://leetcode.com/problems/next-permutation/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getFirstNum(vector<int>& nums){
        int j = -1;
        for(int i = nums.size() - 1; i > 0 && j == - 1; i--){
            if (nums[i - 1] < nums[i]) j = i - 1;
        }
        return j;
    }
    
    int getSecondNum(vector<int>& nums, int i){
        int j, value, k;
        // j = i + 1 is atleast one such index
        for(k = i + 1, j = i + 1; k < nums.size(); k++)
            j =  (nums[i] < nums[k] &&  nums[j] >= nums[k]) ? k : j; // nums[j] => nums[k] is important to get the right most index
        return j;
    }
    
    void nextPermutation(vector<int>& nums) {
        int i,j;
        
        // i is the index of rightmost number in nums with nums[i] < nums[i+1]
        i = this->getFirstNum(nums);
        if (i == -1) {
            // if nums is already lexicographically greatest;
            reverse(nums.begin(), nums.end());
            return;
        }
        // j is the index of smallest number larger than nums[i] such the j > i
        j = this->getSecondNum(nums, i);
        // swap values on nums[i] and nums[j]; 
        swap(nums[i], nums[j]);
        
        // reverse after ith index as the numbers remain decreasing order even after the swap
        reverse(nums.begin() + i + 1, nums.end());
    }
};
