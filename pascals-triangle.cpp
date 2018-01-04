//https://leetcode.com/problems/pascals-triangle/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void genNext(vector<int>& current, vector<int>& prev, int prevSize){
        current.push_back(prev[0]);
        
        for(int i = 0; i < prevSize - 1; i++){
            current.push_back(prev[i] + prev[i+1]);
        }
        current.push_back(prev[prevSize - 1]);
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows, vector<int>());
        if (numRows == 0) return ans;
        ans[0].push_back(1);
        for(int i = 1; i < numRows; i++){
            this->genNext(ans[i], ans[i-1], i);
        }
        return ans;
    }
};

