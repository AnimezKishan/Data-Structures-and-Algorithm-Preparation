/*
Interval Based
Points to keep in mind to approach Interval based problem
~ For interval1 (start1, end1) and interval2 (start2, end2) to be overlapping
    -> max(start1, start2) < min(end1, end2)

~ To find the start and end point of region between them which is causing overlapping 
    -> start_point = max(start1, start2)
    -> end_point = min(end1, end2)
*/

class MyCalendarTwo {
public:
    vector<pair<int, int>> doubleOverlapping;
    vector<pair<int, int>> bookings;
    MyCalendarTwo() {
        
    }

    bool checkOverlapping(int start1, int end1, int start2, int end2) {
        if(max(start1, start2) < min(end1, end2))
            return true;
        return false;
    }

    pair<int, int> findOverlappingRegion(int start1, int end1, int start2, int end2) {
        return {max(start1, start2), min(end1, end2)};
    }
    
    bool book(int start, int end) {
        // check if triple booking happening or not
        for(pair<int, int> &region : doubleOverlapping) {
            if(checkOverlapping(region.first, region.second, start, end))
                return false;
        }

        // check if double booking happening or not
        for(pair<int, int> &region : bookings) {
            if(checkOverlapping(region.first, region.second, start, end)){
                pair<int, int> overlapping_region = findOverlappingRegion(region.first, region.second, start, end);
                doubleOverlapping.push_back(overlapping_region);
            }
        }

        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */