// https://leetcode.com/problems/intersection-of-two-arrays/description/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> hashMap;
        unordered_map<int, bool> :: iterator itr;
        set<int> ans;
        for(auto &a : nums1)
            hashMap[a] = true;
        
        for(auto &a : nums2){
            if ((itr = hashMap.find(a)) != hashMap.end())
                ans.insert(a);
        }
        
        return vector<int>(ans.begin(), ans.end());
    }
};
