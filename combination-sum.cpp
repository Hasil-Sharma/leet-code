// https://leetcode.com/problems/combination-sum/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void getCombSum(vector<int>& candidates, vector<vector<int>>& answer, int target, vector<int>& currVec, int len){
    
        if (target == 0){
            vector<int> temp(currVec.begin(), currVec.begin() + len) ;
            answer.push_back(temp);
            
        } else {
            
             for(int i = 0; i < candidates.size(); i++){
                 int c = candidates[i];
                 // all the further values of c are not going to work
                if (target - c < 0) 
                    break;
                 
                 // add a number to vector only if it is same or of value greater
                if (len == 0 || currVec[len - 1] <= c){
                    currVec[len] = c;
                    this->getCombSum(candidates, answer, target - c, currVec, len + 1);
                }
                    
            }
            
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> answer;
        vector<int> currVec(target);
        sort(candidates.begin(), candidates.end());
        this->getCombSum(candidates, answer, target, currVec, 0);
        return answer;
    }
};

