// https://leetcode.com/problems/heaters/description/

class Solution {
public:
    
    int getInterval(vector<int>& heaters, int house){
        int low = 0, high = heaters.size() - 1;
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            if (heaters[mid] > house) high = mid - 1;
            else if (heaters[mid] < house) low = mid + 1;
            else if (heaters[mid] == house){
                low = mid;
                break;
            }
        }
        
        return low;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int ans, final_ans = 0;
        
        for(int &house : houses){
            auto interval = getInterval(heaters, house);
            if (interval == 0){
                ans = heaters[0] - house;
            } else if (interval == heaters.size()){
                ans = house - heaters[interval - 1];
            } else {
                ans = min(heaters[interval] - house, house - heaters[interval - 1]);
            }
            final_ans = max(ans, final_ans);
        }
        
        return final_ans;
    }
};
