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
    Event(string m_eventName, string m_organizer, int m_month, int m_day, string m_startTime, string m_endTime, bool m_openToNonResidents, int m_ticketCost, deque<string> m_waitlist);
    deque<string> getWaitlist();
    void printEvent();
    friend istringstream& operator>>(istringstream& input, Event& obj);
};

#endif
