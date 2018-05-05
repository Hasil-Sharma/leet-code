// https://leetcode.com/problems/pascals-triangle-ii/description/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> answer;
        
        answer.push_back(1);
        
        for(int k = 1; k <= rowIndex; k++) {
            long temp = (answer.back() * (rowIndex - k + (long)1)) / k;
            answer.push_back((int)temp);
        }
        return answer;
    }
};
