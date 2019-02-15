// https://leetcode.com/problems/k-empty-slots/

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> bloomed;
        int n = flowers.size(); // number of days
        k += 1;
        for(int i = 0; i < n; i++){
            int pos = flowers[i];
            bloomed.insert(pos);
            if (bloomed.count(pos - k)){
                auto itr = bloomed.upper_bound(pos - k);
                if (itr == bloomed.end() || *itr >= pos)
                    return i + 1;
            } else if (bloomed.count(pos + k)) {
                auto itr = bloomed.upper_bound(pos);
                if (itr == bloomed.end() || *itr >= pos + k)
                    return i + 1;
            }
        }
        
        return -1;
    }
};
