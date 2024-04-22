#include "event.hpp"
#include <vector>
#include <sstream>

Event::Event() { }
Event::Event(string m_eventName, User m_organizer, int m_month, int m_day, string m_startTime, string m_endTime, bool m_openToNonResidents, int m_ticketCost, deque<string> m_waitlist) : 
    eventName(m_eventName),
    organizer(m_organizer),
    month(m_month),
    day(m_day),
    startTime(m_startTime),
    endTime(m_endTime),
    openToNonResidents(m_openToNonResidents),
    ticketCost(m_ticketCost),
    waitlist(m_waitlist) { }


friend istringstream& operator>>(istringstream& input, Event& obj) {
    input>>eventName;
    input>>organizer;
    input>>month;
    input>>day;
    input>>startTime;
    input>>endTime;
    input>>openToNonResidents;
    input>>ticketCost;
    string waitlistLine;
    getline(input, waitlistLine);
    vector<string> = waitlistVector = splitString(waitlistLine);
    for (int i =0; i waitlistVector.size(); i++) {
        waitlist.push_back(waitlistVector[i]);
    }
    return input;
}
