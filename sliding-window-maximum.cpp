// https://leetcode.com/problems/sliding-window-maximum/description/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> d;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            
            while(!d.empty() && d.back().first <= nums[i])
                d.pop_back();
            
            d.push_back({nums[i], i});
            
            // test here
            while(!d.empty() && d.front().second <= i - k)
                d.pop_front();
            
            if(d.back().second >= k - 1) ans.push_back(d.front().first);
            
        }
        
        return ans;
    }
};
