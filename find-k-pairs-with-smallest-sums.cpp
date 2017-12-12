// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    class PAIR {
        int sum, num1, num2;
        public:
            // sum -> sum of the values, num1 -> index in vector nums1, num2 -> index in vector nums2
            PAIR(int sum, int num1, int num2){
                this->sum = sum;
                this->num1 = num1;
                this->num2 = num2;
            }

            int getNum1() const {return this->num1;}
            int getNum2() const {return this->num2;}
            int getSum() const {return this->sum;}
    };
    
    class myComparator {
        public:
            int operator() (const PAIR& p1, const PAIR& p2){
                
                return (p1.getSum() > p2.getSum());
            }
    };
    
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> answer;
        priority_queue<PAIR, vector<PAIR>, myComparator> pq;
        set<pair<int, int>> visited;
        
        if(nums1.size() == 0 || nums2.size() == 0) return answer;
        
        int num1 = 0, num2 = 0;
        pq.push(PAIR(nums1[num1] + nums2[num2], num1, num2));
        visited.insert({0, 0});
        while(k-- && !pq.empty()){
            PAIR pr = pq.top(); pq.pop();
            num1 = pr.getNum1(); num2 = pr.getNum2();
            answer.push_back({nums1[num1], nums2[num2]});
            
            // pushing the PAIR directly below the current PAIR
            if (num2 < nums2.size() - 1 && visited.find({num1, num2 + 1}) == visited.end()){
                pq.push(PAIR(nums2[num2 + 1] + nums1[num1], num1, num2 + 1));
                visited.insert({num1, num2 + 1});
            }
            
            // pushing the PAIR directly next to the current PAIR
            if (num1 < nums1.size() - 1 && visited.find({num1 + 1, num2}) == visited.end()){
                pq.push(PAIR(nums2[num2] + nums1[num1 + 1], num1  + 1, num2));
                visited.insert({num1 + 1, num2});
            }
                
        }
        
        return answer;
    }
};
