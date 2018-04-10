// https://leetcode.com/problems/max-chunks-to-make-sorted-ii/description/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // for each i 
        // - check max element from 0 to i
        // - check min element from i + 1 to n - 1
        // if max <= min then a new chunk can be created
        int n = arr.size(), ans = 1;
        vector<int> leftMax(n), rightMin(n);
        
        leftMax[0] = arr[0];
        for(int i = 1; i < n; i++)
            leftMax[i] = max(leftMax[i - 1], arr[i]);
        rightMin[n - 1] = arr[n - 1];
        for(int i = n - 2; i > -1; i--)
            rightMin[i] = min(rightMin[i + 1], arr[i]);
        
        for(int i = 0 ; i < n - 1; i++)
            ans += leftMax[i] <= rightMin[i+1] ? 1 : 0;
            
        return ans;
    }
};
