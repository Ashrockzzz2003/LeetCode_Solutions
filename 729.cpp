class Booking {
public:
    int start;
    int end;

    Booking(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class MyCalendar {
private:
    vector<Booking> bookings;

    bool isOverlap(Booking b1, Booking b2) {
        return max(b1.start, b2.start) < min(b1.end, b2.end);
    }

public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        Booking new_booking = Booking(start, end);
        for (Booking b : bookings) {
            if (isOverlap(b, new_booking)) return false;
        }

        bookings.emplace_back(new_booking);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */