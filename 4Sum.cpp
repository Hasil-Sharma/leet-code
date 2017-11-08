//https://leetcode.com/problems/4sum/description/
#include <bits/stdc++.h>
class Solution {
public:
    bool compareVector(vector<int>& v1, vector<int>& v2, int len){
        bool res = true;
        for(int i = 0; i < len && res; i++){
            res &= (v1[i] == v2[i]);
        }
        return res;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        
         
        // for(int c : nums)
        //     cout << c << " ";
        // cout << endl;
        
        for(int index_skip = 0; index_skip < nums.size(); index_skip++) {
            
            // Reducing problem to a + b + c = target' where target' = target - d
            
            // // Handling the case of duplicate d
            // if(index_skip > 0 && nums[index_skip] == nums[index_skip - 1]) continue;
            
            // cout << "(First Term) Picked Index: " << index_skip <<  " Picked Value: " << nums[index_skip] << endl;
            
            int target_m = target - nums[index_skip];
            // cout << "Target_m: " << target_m << endl;
            for(int i = 0; i < nums.size(); i++) {
                
                // Reducing problem to b + c = target'' where target'' = target' - a 
                
//                 // Handling the case of duplicate a
//                 if(i > 0 && nums[i] == nums[i - 1]) continue;
                
//                 // Not picking the index which has already been picked to choose d
                if ( i == index_skip) continue;
                
                // Low is index of b and hi is index of c
                int low = i + 1, hi = nums.size() - 1;
                int target_mm = target_m - nums[i];
                
                // cout << "(Second Term) Picked Index: " << i <<  " Picked Value: " << nums[i] << endl;
                
                while(low < hi) {
                    
                    // Increasing hi if it is index_skip and reducing hi in case it is index_skip;
                    
                    if(low == index_skip || hi == index_skip) {
                        // low += (index_skip == low) ? 1 : (--hi == hi);
                        if (low == index_skip) low++;
                        else hi--;
                        
                    } else {
                        if (nums[index_skip] + nums[i] + nums[hi] + nums[low] == target) {
                            
                            vector<int> temp(4);
                            temp[0] = nums[i];
                            temp[1] = nums[index_skip];
                            temp[2] = nums[low];
                            temp[3] = nums[hi];

                            // It is possible that nums[low] & nums[hi] get repeated
                            // A case when 6 6 6 6 when initially low and hi point to first and last 6
                            // Later they'll point to 2nd 6 and 3rd 6 which will lead to duplicate answer
                            sort(temp.begin(), temp.end());
                            
                            // for(int c : temp)
                            //     cout << c <<  ",";
                            // cout << endl;
                            ans.insert(temp);
                            
                            hi--; low++;
                            
                        } else if (nums[index_skip] + nums[i] + nums[hi] + nums[low] > target) hi--;
                        else if (nums[index_skip] + nums[i] + nums[hi] + nums[low] < target) low++;
                    }
                    
                    
                }
                
        
            }
        }
        
        vector<vector<int>> ans_vec(ans.begin(), ans.end());
        return ans_vec;
    }
};

