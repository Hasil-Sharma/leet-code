// https://leetcode.com/problems/my-calendar-i/description/

class MyCalendar {
public:
    map<int, int> events;
    map<int, int> :: iterator prev, next;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool flag = (events.size() == 0) ? true : false;
        next = events.lower_bound(start); 
        prev = events.end();
        
        if (next != events.begin()){
            prev = next;
            --prev;
        }
        
        if (prev == events.end()){
            flag = (next->first >= end) ? true : flag;
        } else if (next == events.end()){
            flag = (prev->second <= start) ? true : flag;
        } else if (prev->second <= start && next->first >= end){
            flag = true;
        }
        if (flag) events[start] = end;
        return flag;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
