// https://leetcode.com/problems/find-the-celebrity/description/

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int cand = 0;
        for(int i = 1; i < n; i++)
            if (!knows(i, cand))
                cand = i;
        for(int j = 0; j < n; j++)
            if (j == cand) continue;
            else if (!knows(j, cand) || knows(cand, j))
                return -1;
        return cand;
    }
};
