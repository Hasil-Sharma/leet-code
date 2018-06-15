//https://www.lintcode.com/problem/same-number/description

class Solution {
public:
    /**
     * @param nums: the arrays
     * @param k: the distance of the same number
     * @return: the ans of this question
     */
    string sameNumber(vector<int> &nums, int k) {
        // Write your code here
        unordered_map<int, int> hashMap;
        
        for(int i = 0; i < nums.size(); i++){
            if (hashMap.count(nums[i]) && i - hashMap[nums[i]] < k)
                    return "YES";
                    
            hashMap[nums[i]] = i;
        }
        
        return "NO";
    }
};
