// https://leetcode.com/problems/array-nesting/description/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        unordered_set<int> visit;
        for(int i = 0; i < n; i++){
            if (!visit.count(i)){
                int temp = 0, node = i;
                while(!visit.count(node)){
                    temp++;
                    visit.insert(node);
                    node = nums[node];
                }
                ans = max(temp, ans);
            }
        }
        return ans;
    }
};
