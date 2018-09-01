// https://leetcode.com/problems/flatten-nested-list-iterator/description/

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }

    int next() {
        int v = q.front();
        q.pop();
        return v;
    }

    bool hasNext() {
        return !q.empty();
    }

private:
    queue<int> q;
    
    void flatten(vector<NestedInteger> &nestedList){
        for(auto nn : nestedList){
            if (nn.isInteger()) q.push(nn.getInteger());
            else flatten(nn.getList());
        }
    }
};
