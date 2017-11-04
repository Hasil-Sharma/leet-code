//httpsleetcode.com/problems/3sum/description/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int sum, lo, hi;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || (i != 0 && nums[i-1] != nums[i])){
                // To get only unique
                lo = i + 1;
                hi = nums.size() - 1;
                sum = 0 - nums[i];
                while(lo < hi){
                    if(nums[lo] + nums[hi] == sum){
                        // Found a pair
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[lo++]);
                        temp.push_back(nums[hi--]);
                        
                        // To handle cases like -2,0,0,2,2 repeated tuple
                        if(ans.size() == 0 || ans.back()[0] != temp[0] || ans.back()[1] != temp[1] || ans.back()[2] != temp[2])
                            ans.push_back(temp);
                    } else if (nums[lo] + nums[hi] < sum) 
                        lo++; //increase the lower number
                    else if (nums[lo] + nums[hi] > sum)
                        hi--; //decrease the upper number to reduce sum
                        
                }
            }
        }
        return ans;
    }
};

