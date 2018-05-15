// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int answer = 0, valid_subarrays = 0, potential_subarray = 0;
        
        for(int &a : A){
            if (a >= L && a <= R){
                valid_subarrays += potential_subarray + 1;
                answer += valid_subarrays;
                potential_subarray = 0;
            } else if (a <= R) {
                answer += valid_subarrays;
                potential_subarray += 1;
            } else {
                valid_subarrays = 0;
                potential_subarray = 0;
            }
        }
        
        return answer;
    }
};
