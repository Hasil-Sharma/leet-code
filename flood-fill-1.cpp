// https://leetcode.com/problems/flood-fill/description/

class Solution {
public:
    
    vector<pair<int,int>> steps = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (oldColor == newColor) 
            return image;
        int m = image.size(), n = image[0].size();
        helper(image, sr, sc, oldColor, newColor);
        return image;
    }
    
    void helper(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor){
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor) 
            return;
        image[sr][sc] = newColor;
        
        for(auto step: steps)
            helper(image, sr + step.first, sc + step.second, oldColor, newColor);
    }
};
