//https://leetcode.com/problems/beautiful-arrangement-ii/submissions/1

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int i = 1, j = n;
        vector<int> answer(n);
        int idx = 0;
        while(j >= i){
            if (k > 1){
                answer[idx++] = (k-- % 2 ? i++ : j--);
            } else {
                answer[idx++] = i++;
            }
        }
        
        return answer;
    }
};
