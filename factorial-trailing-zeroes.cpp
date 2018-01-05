https://leetcode.com/problems/factorial-trailing-zeroes/description/

class Solution {
public:
    int trailingZeroes(int n) {
        long long int answer = 0, div = 5;
        while(div <= n){
            answer += n / div;
            div *= 5;
        }
        return answer;
    }
};
