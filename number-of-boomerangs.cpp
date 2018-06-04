// https://leetcode.com/problems/number-of-boomerangs/description/

class Solution {
public:
    int dist(pair<int, int>& p1, pair<int, int>& p2){
        return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
    }
    
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int ans = 0;
        unordered_map<int, int> hashMap;
        for(int i = 0; i < points.size(); i++){
            for(int j = 0; j < points.size(); j++){
                if (i == j)  continue;
                hashMap[dist(points[i], points[j])]++;
            }
            for(auto &itr : hashMap)
                ans += itr.second * (itr.second - 1);
            // possible values for a given i
            hashMap.clear();
        }
        
        return ans;
    }
};
