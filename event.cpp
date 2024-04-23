#include "event.hpp"
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;
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
    string openToNResString;
    input>>openToNResString;
    if (openToNResString == "true") {
        obj.openToNonResidents = true;
    }
    else {
        obj.openToNonResidents = false;
    }
    input>>obj.ticketCost;
    string m;
    cout<<"here"<<endl;
    while(input>>m) {
        //input>>m;
        cout<<"Appending to waitlist"<<endl;
        obj.waitlist.push_back(m);
    }
    return input;
}

void Event::printEvent() {
    cout<<"Name: "<<eventName<<endl;
    cout<<"Organizer: "<<organizer<<endl;
    cout<<"Date: "<<month<<"/"<<day<<endl;
    cout<<"Time: "<<startTime<<"-"<<endTime<<endl;
    cout<<"Open to Non-Residents: "<<boolalpha<<openToNonResidents<<endl;
    cout<<"Ticket cost: "<<ticketCost<<endl;
}

string Event::getEventName() {
    return eventName;
}
string Event::getOrganizer() {
    return organizer;
}
int Event::getMonth() {
    return month;
}
int Event::getDay() {
    return day;
}
string Event::getStartTime() {
    return startTime;
}
string Event::getEndTime() {
    return endTime;
}
bool Event::getOpenToNonResidents() {
    return openToNonResidents;
}
int Event::getTicketCost() {
    return ticketCost;
}
deque<string> Event::getWaitlist() {
    return waitlist;
}
