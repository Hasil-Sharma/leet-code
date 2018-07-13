// https://leetcode.com/problems/reconstruct-itinerary/description/

class Solution {
public:
    #define mp(A, B) make_pair(A, B)
    typedef pair<int, int> pii;
    typedef vector<int> vi;
    typedef vector<vector<int>> vvi;
    typedef vector<pair<int, int>> vpii;
    typedef vector<bool> vb;
    typedef vector<vector<bool>> vvb;
    typedef vector<string> vs;
    typedef vector<vector<string>> vvs;
    typedef stack<int> stki;
    typedef queue<int> qi;
    typedef deque<int> dqi;
    typedef pair<string, string> pss;
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        set<string> airports;
        vs answer;
        vi ansproxy;
        
        int count = tickets.size();
        
        for(pss& ticket : tickets){
            airports.insert(ticket.first);
            airports.insert(ticket.second);
        }
        
        int n = airports.size();
        int idx = 0;
        unordered_map<string, int> airportToInt;
        vs intToAirport(n);
        
        for(auto airport : airports){
            airportToInt[airport] = idx;
            intToAirport[idx++] = airport;
        }
        vvi ticketCount(n, vi(n, 0));
        vector<set<int>> adjList(n, set<int>());
        
        for(pss& ticket : tickets){
            adjList[airportToInt[ticket.first]].insert(airportToInt[ticket.second]);
            ticketCount[airportToInt[ticket.first]][airportToInt[ticket.second]]++;
        }
        
        int src = airportToInt["JFK"];
        
        dfs(ansproxy, adjList, ticketCount, src, count);
        
        for(int i : ansproxy){
            answer.push_back(intToAirport[i]);
        }
        return answer;
    }
    
    
    void dfs(vi& ans, vector<set<int>>& adjList, vvi& ticketCount, int src, int count){
        
        ans.push_back(src);
        for(int child: adjList[src]){
            if (ticketCount[src][child]){
                ticketCount[src][child]--;
                dfs(ans, adjList, ticketCount, child, count);
                if (ans.size() == count + 1)
                    break;
                ticketCount[src][child]++;
            }
        }
        
        if (ans.size() != count + 1)
            ans.pop_back();
    }
};
