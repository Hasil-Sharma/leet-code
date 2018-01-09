// https://leetcode.com/problems/the-skyline-problem/description/

class Solution {
public:
    void print(vector<pair<int, int>>& v){
        for(auto p : v){
            printf("(%d, %d) ", p.first, p.second);
        }
        cout << endl;
    }
    
    void addToAnswer(vector<pair<int, int>>& answer, pair<int, int>& p, int h1, int h2){
        p.second = max(h1, h2);
        if (answer.size() != 0 && answer.back().first == p.first)
            answer.back().second = max(answer.back().second, p.second);
        else if (answer.size() == 0 || answer.back().second != p.second)
            answer.push_back(p);
    }
    vector<pair<int, int>> merge(vector<pair<int, int>>& v1, vector<pair<int, int>>& v2){
        int h1 = 0, h2 = 0, i1 = 0, i2 = 0;
        vector<pair<int, int>> answer;
        // v1 and v2 will always have a size of atleast 2
        // cout << "Merging" << endl;
        // print(v1);
        // print(v2);
        while(i1 < v1.size() || i2 < v2.size()){
            pair<int, int> p;
            while(i1 < v1.size() && i2 < v2.size()){
                if (v1[i1].first < v2[i2].first){
                    h1 = v1[i1].second;
                    p.first = v1[i1++].first;
                } else {
                    h2 = v2[i2].second;
                    p.first = v2[i2++].first;
                }
                addToAnswer(answer, p, h1, h2);
            }
            
            while(i1 < v1.size()){
                p.first = v1[i1].first;
                h1 = v1[i1++].second;
                addToAnswer(answer, p, h1, h2);;
            }
            
            while(i2 < v2.size()){
                p.first = v2[i2].first;
                h2 = v2[i2++].second;
                addToAnswer(answer, p, h1, h2);
            }
        }
        answer.back().second = 0;
        // cout << "Merged" << endl;
        // print(answer);
        return answer;
    }
    vector<pair<int, int>> helper(vector<vector<int>>& buildings, int start, int end){
        vector<pair<int, int>> answer;
        int mid;
        if (start == end - 1){
            // split single building into skyline
            answer.push_back({buildings[start][0], buildings[start][2]});
            answer.push_back({buildings[start][1], 0});
        } else if (end != 0) {
            mid = start + (end - start)/2;
            vector<pair<int, int>> lanswer = helper(buildings, start, mid);
            vector<pair<int, int>> ranswer = helper(buildings, mid, end);
            answer = merge(lanswer, ranswer);
        }
        return answer;
    }
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        return helper(buildings, 0, buildings.size());
    }
};
