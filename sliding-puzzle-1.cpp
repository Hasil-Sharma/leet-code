// https://leetcode.com/problems/sliding-puzzle/description/
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int ans = -1;
        map<string, bool> state;
        queue<pair<string, int>> q;
        
        q.push({encode(board), 0});
        
        while(!q.empty()){
            auto p = q.front();
            string str = p.first;
            
            q.pop();
            
            // if this state has been already tested
            if (state.find(str) != state.end())
                continue;
            // if this state is the final required state
            else if (checkFinal(str)) {
                ans = p.second;
                break;
            }
            
            state[str] = true;
            
            int zeroPos = str.find('0');
            int start, inc;
            
            if (zeroPos == 1 || zeroPos == 4){
                start = -1;
                inc = 2;
            } else if (zeroPos == 0 || zeroPos == 3) {
                start = 1;
                inc = 2;
            } else {
                start = -1;
                inc = 4;
            }
            
            for(int i = start; i <= 3; i += inc){
                    string str1 = str;
                    swap(str1[zeroPos],str1[(zeroPos + i) % 6]);
                    q.push({str1, p.second + 1});
            }
            
        }
        return ans;
    }
    
    string encode(vector<vector<int>>& board){
        stringstream code;
        
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 3; j++)
                code << board[i][j];
        
        return code.str();
    }
    
    bool checkFinal(string str){
        return str == "123450";
    }
};
