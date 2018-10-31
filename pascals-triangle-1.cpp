// https://leetcode.com/problems/pascals-triangle/description/

typedef vector<vector<int>> vvi;
typedef vector<int> vi;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vvi ans;
        if (numRows)
        ans.push_back({1});
        int val;
        for(int i = 1; i < numRows; i++){
            vi temp;
            temp.push_back(1);
            for(int k = 1; k < i; k++){
                temp.push_back(ans[i-1][k-1] + ans[i-1][k]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};
