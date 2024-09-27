// Interval Based

class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // find the event that occurs just after or at the same time of start, end
        auto it = st.lower_bound({start, end});

        // check for overlap with next event
        if(it != st.end() && it->first < end)
            return false;

        // check for overlap with prev event
        if(it != st.begin()) {
            auto p = prev(it);
            if(start < p->second)
                return false;
        }
        
        st.insert({start, end});
        return true;

    }
};


// Approach II
/*
Interval Based
~ For interval1 (start1, end1) and interval2 (start2, end2) to be overlapping
    -> max(start1, start2) < min(end1, end2)
*/
/*
class MyCalendar {
public:
    vector<pair<int, int>> bookings;
    MyCalendar() {
        
    }

    bool checkOverlapping(int start1, int end1, int start2, int end2) {
        if(max(start1, start2) < min(end1, end2))
            return true;
        return false;
    }
    
    bool book(int start, int end) {
        // check if double booking happening or not
        for(pair<int, int> region : bookings) {
            if(checkOverlapping(region.first, region.second, start, end))
                return false;
        }

        bookings.push_back({start, end});
        return true;

    }
};
*/

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */