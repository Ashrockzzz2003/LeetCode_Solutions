class Booking {
public:
    int start;
    int end;

    Booking(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class MyCalendarTwo {
private:
    vector<Booking> overlaps;
    vector<Booking> bookings;

    bool isOverlap(Booking b1, Booking b2) {
        return max(b1.start, b2.start) < min(b1.end, b2.end);
    }

    Booking overlap(Booking b1, Booking b2) {
        return Booking(max(b1.start, b2.start), min(b1.end, b2.end));
    }

public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        Booking new_booking = Booking(start, end);
        for (Booking b : overlaps) {
            if (isOverlap(b, new_booking)) return false;
        }

        for (Booking b : bookings) {
            if (isOverlap(b, new_booking)) overlaps.push_back(overlap(b, new_booking));
        }

        bookings.push_back(new_booking);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */