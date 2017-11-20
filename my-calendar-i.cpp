//https://leetcode.com/problems/my-calendar-i/description/
#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
private:
    vector<pair <int,int>> events;
public:
    MyCalendar() {
        
    }
    
    int checkCanAdd(int start, int end){
        int l = 0, h = events.size() - 1, ans = -2, mid;
        if (events[l].first >= end){
            // add element before the first element;
            ans = -1;
        } else if (events[h].second <= start){
            // add element after the last element
            ans = h;
        } else {
            while(l <= h){
                mid = (l + h)/2;
                if (events[mid].second <= start && events[mid + 1].first >= end){
                    // start can be added after the mid;
                    ans = mid;
                    break;
                } else if (events[mid].first < start){
                    l = mid + 1;
                } else h = mid - 1;
            }
        }
    return ans;
    }
    
    bool book(int start, int end) {
        bool flag = false;
        if (events.size() == 0){
            events.push_back(make_pair(start, end));
            flag = true;
        } else {
            // i the index after which element is to be added  
            int i = this->checkCanAdd(start, end);
            if (i > -2){
                events.insert(events.begin() + i + 1, make_pair(start, end));
                flag = true;
            }
        }
        return flag;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */

