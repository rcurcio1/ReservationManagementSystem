#include "event.hpp"
#include <vector>
#include <sstream>

Event::Event() { }
Event::Event(string m_eventName, string m_organizer, int m_month, int m_day, string m_startTime, string m_endTime, bool m_openToNonResidents, int m_ticketCost, deque<string> m_waitlist) : 
    eventName(m_eventName),
    organizer(m_organizer),
    month(m_month),
    day(m_day),
    startTime(m_startTime),
    endTime(m_endTime),
    openToNonResidents(m_openToNonResidents),
    ticketCost(m_ticketCost),
    waitlist(m_waitlist) { }


istringstream& operator>>(istringstream& input, Event& obj) {
    input>>obj.eventName;
    input>>obj.organizer;
    input>>obj.month;
    input>>obj.day;
    input>>obj.startTime;
    input>>obj.endTime;
    input>>obj.openToNonResidents;
    input>>obj.ticketCost;
    string m;
    while(input>>m) {
        obj.waitlist.push_back(m);
    }
    return input;
}

deque<string> Event::getWaitlist() {
    return waitlist;
}
