// https://leetcode.com/problems/longest-absolute-file-path/description/

class Solution {
public:
    int lengthLongestPath(string input) {
            // write your code here
            int ans = 0, start = 0, dot = 0, idx = 0, tcount = 0;
            vector<int> depthLen(input.length(), 0);

            while(idx < input.length()){
                while(input[idx] != '\n' && idx < input.length()){
                    tcount += (input[idx] == '\t') ? 1 : 0;
                    dot += (input[idx] == '.')  ? 1 : 0;
                    idx++;
                }
                
                depthLen[tcount] = (tcount > 0 ? depthLen[tcount - 1] : 0) + idx - start - tcount;
                start = ++idx;
                if (dot > 0){
                    ans = max(ans, depthLen[tcount] + tcount);
                }
                tcount = 0;
                dot = 0;
            }

            return ans;
        }
};
