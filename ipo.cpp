// https://leetcode.com/problems/ipo/description/

class Solution {
    typedef pair<int, int> pii;
    typedef vector<pii> vpii;
    typedef function<bool(pii, pii)> fp_pii_pii;
    
    bool static ccmp(pii p1, pii p2){
        return p1.first > p2.first;
    }
    
    bool static pcmp(pii p1, pii p2){
        return p1.second < p2.second;
    }
    
public:
    
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        
        priority_queue<pii, vpii, fp_pii_pii> min_c_pq(ccmp);
        priority_queue<pii, vpii, fp_pii_pii> max_p_pq(pcmp);
        
        for(int i = 0; i < Profits.size(); i++)
            min_c_pq.push({Capital[i], Profits[i]});
                
        for(int i = 0; i < k; i++){
            
            while(min_c_pq.size() && min_c_pq.top().first <= W){
                max_p_pq.push(min_c_pq.top());
                min_c_pq.pop();
                
            }
            
            if(max_p_pq.size()){
                W += max_p_pq.top().second;
                max_p_pq.pop();
            }
        }
        
        
        return W;
    }
};
