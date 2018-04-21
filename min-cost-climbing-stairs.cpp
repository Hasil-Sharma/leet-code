// https://leetcode.com/problems/min-cost-climbing-stairs/description/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int first = cost[0], second = cost[1], temp, size = cost.size();
        
        for(int i = 2; i < size; i++){
            first = cost[i] + min(first, second);
            temp = first;
            first = second;
            second = temp;
        }
        
        return min(first, second);
    }
};
