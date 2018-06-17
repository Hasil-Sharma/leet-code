// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, minN = INT_MAX;
        
        for(int &n : nums){
            sum += n;
            minN = min(minN, n);
        }
        
        return sum - nums.size()*minN;
    }
};
