#include <string>
#include <sstream>
#include <deque>
#ifndef EVENT_H
#define EVENT_H
using namespace std;


class Event {
private:
    string eventName;
    string organizer;
    int month;
    int day;
    string startTime;
    string endTime;
    bool openToNonResidents;
    int ticketCost;
    deque<string> waitlist;
public:
    Event();
    Event(string eventName, string organizer);
    friend istringstream& operator>>(istringstream& input, Event& obj);
}

#endif
