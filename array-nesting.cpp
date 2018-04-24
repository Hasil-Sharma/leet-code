// https://leetcode.com/problems/array-nesting/description/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int answer = 0, temp = 0, buffer;
        
        for(int i = 0; i < nums.size(); i++){
            temp = 0;
            
            while(nums[i] != -1){
                buffer = nums[i];
                nums[i] = -1;
                i = buffer;
                temp++;
            }
            
            answer = (temp > answer) ? temp : answer;
        }
        
        return answer;
    }
};
