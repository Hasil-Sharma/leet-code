// https://leetcode.com/problems/find-the-celebrity/description/

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int cel = 0;
        
        for(int i = 1; i < n; i++){
            if (knows(i, cel) && !knows(cel, i))
                cel = cel;
            else
                cel = i;
        }
        
        for(int i = 0; i < n; i++){
            if (cel == i) continue;
            else if (knows(i, cel) && !knows(cel, i))
                cel = cel;
            else return -1;
        }
        
        return cel;
    }
};
