//https://leetcode.com/problems/valid-triangle-number/description/

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int answer = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = n - 1; i >= 0; i--){
            int l = 0, r = i - 1;
            while(l < r){
                if(nums[l] + nums[r] > nums[i]){
                    answer += r - l;
                    r--;
                } else l++;
            }
        }
        
        return answer;
    }
};
