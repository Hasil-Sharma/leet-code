// https://leetcode.com/problems/flatten-nested-list-iterator/description/

class NestedIterator {
private:
    stack<pair<vector<NestedInteger>, int>> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stk.push({nestedList, 0});
    }

    int next() {
        auto top = stk.top();
        int val = top.first[top.second].getInteger();
        
        stk.top().second++;
        return val;
    }

    bool hasNext() {
        if (stk.empty()) return false;
        
        
        auto top = stk.top();
        
        while(!stk.empty()){
            if (top.first.size() == top.second){
                stk.pop();
                if (stk.empty()) return false;
                top = stk.top();
            } else if (!top.first[top.second].isInteger()){
                stk.top().second++;
                stk.push({top.first[top.second].getList(), 0});
                top = stk.top();
            } else {
                break;
            }
        }
        
        return top.first.size() > top.second;
    }
};
