// https://leetcode.com/problems/my-calendar-iii/description/
class MyCalendarThree {
public:
    map<int, int> events;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        events[start]++;
        events[end]--;
        
        int ongoing = 0, k = 0;
        
        for(auto p : events){
            k = max(k, ongoing += p.second);
        }
        
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */
