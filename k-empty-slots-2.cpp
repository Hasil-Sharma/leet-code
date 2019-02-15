// https://leetcode.com/problems/k-empty-slots/description/

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        vector<int> days = vector<int>(n);
        
        for(int i = 0; i < n; i++)
            days[flowers[i] - 1] = i + 1;
        
        int left = 0, right = left + k + 1, ans = INT_MAX;
        
        while(right < n){
            bool flag = true;
            for(int i = left + 1; i < right && flag; i++){
                if (days[i] < days[left] || days[i] < days[right]){
                    flag = false;
                    left = i;
                    right = left + k + 1;
                }
            }
            
            if (flag){
                ans = min(ans, max(days[left], days[right]));
                left = right;
                right = left + k + 1;
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};
