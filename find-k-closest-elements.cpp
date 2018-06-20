// https://leetcode.com/problems/find-k-closest-elements/description/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // find the bucket in which x will fall of the form : (]
        int low = 0, high = arr.size() - 1, _high;
        deque<int> ans;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if (arr[mid] == x){
                _high = mid;
                break;
            } else if (arr[mid] > x){
                _high = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        low = _high - 1;
        high = _high;
        
        while(k--){
            if (low >= 0 && high < arr.size()){
                if (x - arr[low] <= arr[high] - x) ans.push_front(arr[low--]);
                else ans.push_back(arr[high++]);
            } else if (low >= 0){
                ans.push_front(arr[low--]);
            } else {
                ans.push_back(arr[high++]);
            }
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};
