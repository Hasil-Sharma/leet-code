// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    class MatrixElement {
        int val, row, col;
        public:
        
            MatrixElement(int val, int row, int col){
                this->val = val;
                this->row = row;
                this->col = col;
            }
        
            int getVal() const { return this->val; }
            int getRow() const { return this->row; }
            int getCol() const { return this->col; }
    };
    
    class myComparator{
        public:
            int operator() (const MatrixElement& m1, const MatrixElement& m2){
                return m1.getVal() > m2.getVal();
            }
    };
    
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue <MatrixElement, vector<MatrixElement>, myComparator> pq;
        int n =  matrix.size(), ans;
        
        for(int i = 0; i < n; i++) pq.push(MatrixElement(matrix[0][i], 0, i));
        
        while(k--){
            MatrixElement elem = pq.top(); pq.pop();
            ans = elem.getVal();
            if (elem.getRow() < n - 1) pq.push(
                MatrixElement(matrix[elem.getRow() + 1][elem.getCol()],
                              elem.getRow() + 1, 
                              elem.getCol())
            );
        }
        
        return ans;
    }
};

