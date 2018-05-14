// https://leetcode.com/problems/subdomain-visit-count/description/

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> hashTable;
        vector<string> answer;
        int sIdx, count, dIdx;
        
        for(string &cpdomain: cpdomains){
            sIdx = cpdomain.find(" ");
            count = stoi(cpdomain.substr(0, sIdx));
            string domains = cpdomain.substr(sIdx + 1);
            hashTable[domains] += count;
            while((dIdx = domains.find(".")) != string::npos){
                domains = domains.substr(dIdx + 1);
                hashTable[domains] += count;
            }
        }
        
        for(auto &t : hashTable){
            answer.push_back(to_string(t.second) + " " + t.first);
        }
        
        return answer;
    }
};
