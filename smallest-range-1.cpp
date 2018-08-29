// https://leetcode.com/problems/smallest-range/description/

class Solution {
public:
    
    struct E {
        int idx, val, row;
        E(int r, int i, int v) : row(r), idx(i), val(v) {}
    };
    
    struct cmp {
        bool operator()(E*& e1, E*& e2){
            return e1->val > e2->val;
        }
    };
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<E*, vector<E*>, cmp> pq;
        int m = INT_MIN, start = -1, end = -1, range = INT_MAX, k = nums.size();
        
        for(int i = 0; i < k; i++){
            pq.push(new E(i, 0, nums[i][0]));
            m = max(m, nums[i][0]);
        }
        
        while(pq.size() == k){
            auto top = pq.top();
            pq.pop();
            
            if (m - top->val < range){
                range = m - top->val;
                start = top->val;
                end = m;
            }
            
            if (top->idx + 1 < nums[top->row].size()){
                top->idx++;
                top->val = nums[top->row][top->idx];
                pq.push(top);
                m = max(m, top->val);
            }
        }
        
        return {start, end};
    }
};
