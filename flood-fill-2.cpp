// https://leetcode.com/problems/flood-fill/description/

class Solution {
public:
    
    vector<pair<int,int>> steps = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor) 
            return image;
        int m = image.size(), n = image[0].size();
        stack<int> stk;
        stk.push(sr * n + sc);
        
        while(!stk.empty()){
            auto top = stk.top();
            stk.pop();
            sc = top % n;
            sr = (top - sc) / n;
            image[sr][sc] = newColor;
            for (auto step : steps){
                int _sr = sr + step.first;
                int _sc = sc + step.second;
                if (_sr < 0 || _sr >= m || _sc < 0 || _sc >= n || image[_sr][_sc] != oldColor)
                    continue;
                stk.push({_sr * n + _sc});
            }
        }
        
        return image;
    }
    
};
