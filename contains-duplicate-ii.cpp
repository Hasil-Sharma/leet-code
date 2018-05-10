// https://leetcode.com/problems/contains-duplicate-ii/description/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k ==0) return false;
        unordered_map<int, int> table;
        int num;
        for(int i = 0; i < nums.size(); i++){
            num = nums[i];
            if (table.find(num) != table.end() && i - table[num] <= k){
                // number was encountered previously
                return true;
            }
            // update in either case because future number might be within the range
            table[num] = i;
        }
        
        return false;
    }
};
