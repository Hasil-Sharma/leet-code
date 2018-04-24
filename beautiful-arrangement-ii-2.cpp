// https://leetcode.com/problems/beautiful-arrangement-ii/description/

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<bool> numAdjust = vector<bool>(n + 1, false);
        vector<int> answer;
        int num_iter = k;
        bool flag = true;
        answer.push_back(1);
        numAdjust[1] = true;
        
        for(int i = 2; i <= num_iter; i++){
            int currNum = answer.back() + (flag ? k : -k);
            flag = (!flag);
            k--;
            numAdjust[currNum] = true;
            answer.push_back(currNum);
        }
        
        for(int i = 1; i <= n; i++){
            if (!numAdjust[i])
                answer.push_back(i);
        }
        
        return answer;
    }
};
