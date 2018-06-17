// https://leetcode.com/problems/largest-triangle-area/description/

class Solution {
public:
    double dist(int i, int j, vector<vector<int>>& points){
        return sqrt(
            (points[i][0] - points[j][0])*(points[i][0] - points[j][0]) 
            + 
            (points[i][1] - points[j][1])*(points[i][1] - points[j][1])
        );
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double a, b, c, s, ans = 0.0;
        
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                for(int k = j + 1; k < points.size(); k++){
                    // heron's formula: sqrt(s*(s-a)*(s-b)*(s-c))
                    a = dist(i, j , points); b = dist(i, k, points); c = dist(j, k, points);
                    // printf("%f %f %f\n", a, b , c);
                    s = (a + b + c)/2.0;
                    ans = max(ans, sqrt(s*(s-a)*(s-b)*(s-c)));
                }
            }
        }
        return ans;
    }
};
