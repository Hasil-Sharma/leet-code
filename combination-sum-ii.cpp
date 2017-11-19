// https://leetcode.com/problems/combination-sum-ii/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combSum2Gen(vector<vector<int>>& answer, vector<int>& candidates, vector<int>& temp, int target, int len){
        if (target == 0) {
            answer.push_back(temp);
        } else {
            for(int i = len; i < candidates.size(); i++){
                // To avoid duplicates
                if (i > len && candidates[i - 1] == candidates[i]) continue;
                else if (target - candidates[i] < 0) break;
                temp.push_back(candidates[i]);
                this->combSum2Gen(answer, candidates, temp, target - candidates[i], i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        this->combSum2Gen(answer, candidates, temp, target, 0);
        return answer;
    }
};

