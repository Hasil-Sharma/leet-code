// https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hashMap;
        unordered_map<string, int> :: iterator itr;
        vector<string> ans;
        int i = 0, temp = INT_MAX, temp1;
        
        for(string &str : list1)
            hashMap[str] = i++;
        
        i = 0;
        for(string &str : list2){
            if ((itr = hashMap.find(str)) != hashMap.end()){
                if ((temp1 = itr->second + i) < temp){
                    ans.clear();
                    temp = temp1;
                    ans.push_back(str);
                } else if (temp1 == temp) 
                    ans.push_back(str);
            }
            i++;
        }
        
        return ans;
    }
};
