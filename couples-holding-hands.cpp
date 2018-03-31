https://leetcode.com/problems/couples-holding-hands/description/

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        vector<int> pos(row.size()); 
        int fp, sp, np, count = 0;
        // first person, second person, next person, count of swaps
        
        for(int i = 0; i < row.size(); i++)
            pos[row[i]] = i;
        
        for(int i = 0; i < row.size(); i += 2){
            
            fp = row[i];
            sp = (fp % 2) ? fp - 1 : fp + 1;
            // if fp is odd than sp should be one less else it should be one more
            
            if(sp != row[i + 1]){
                // if sp is not as it should be;
                count++;
                np = row[i + 1];
                
                // swapping the np with sp
                row[pos[np]] = sp; // pos[np] == i + 1
                row[pos[sp]] = np;
                
                // updating the position vector
                pos[np] = pos[sp];
                pos[sp] = i + 1;
            }
        }
        
        return count;
    }
};
