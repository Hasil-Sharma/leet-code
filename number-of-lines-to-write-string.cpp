// https://leetcode.com/problems/number-of-lines-to-write-string/description/

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> answer(2);
        answer[0] = (S.length() > 1) ? 1 : 0;
        int curr_width = 0;
        for(char c : S){
            curr_width += widths[c - 'a'];
            if (curr_width > 100){
                // adding the current character causes width to become more than 100
                
                answer[0] += 1; 
                // increasing the number of current lines
                
                curr_width = widths[c - 'a']; 
                // adding the current character to next line
            }
        }
        answer[1]  = curr_width;
        
        return answer;
    }
};
