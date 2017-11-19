//https://leetcode.com/problems/combination-sum-iii/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void combSumGet(vector<int> &values, vector<int>& temp, vector<vector<int>>& answer, int m_size, int target, int index){
        if (temp.size() == m_size && target == 0){
            answer.push_back(temp);
        } else {
            for(int i = index; i < values.size(); i++){
                if (target - values[i] < 0) break;
                temp.push_back(values[i]);
                this->combSumGet(values, temp, answer, m_size, target - values[i], i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> answer;
        vector<int> temp, values;
        if (k > n) return answer;
        for(int i = 1; i < 10; i++) values.push_back(i);
        this->combSumGet(values, temp, answer, k, n, 0);
        return answer;
    }
};

