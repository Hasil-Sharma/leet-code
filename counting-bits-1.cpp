// https://leetcode.com/problems/counting-bits/description/

typedef vector<int> vi;
class Solution {
public:
    vector<int> countBits(int num) {
        
        vi answer(num+1, 0);
        
        for(int i = 1; i <= num; i++)
            answer[i] = answer[i >> 1] + (i & 1);
        
        return answer;
    }
};
