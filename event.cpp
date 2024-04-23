#include "event.hpp"
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;


Layout getLayoutFromString(string layoutString) {
    if (layoutString == "wedding" or layoutString == "Wedding") {
        return WEDDING;
    }
    if (layoutString == "meeting" or layoutString == "Meeting") {
        return MEETING;
    }
    if (layoutString == "lecture" or layoutString == "Lecture") {
        return LECTURE;
    }
    else {
        return DANCE;
    }
}

Event::Event() { }
Event::Event(string m_eventName, string m_organizer, int m_month, int m_day, string m_startTime, 
    string m_endTime, bool m_openToNonResidents, int m_ticketCost, int m_ticketsRemaining, 
    int m_amountOwed, int m_confirmed, bool m_private, Layout m_layout, deque<string> m_waitlist) : 
    eventName(m_eventName),
    organizer(m_organizer),
    month(m_month),
    day(m_day),
    startTime(m_startTime),
    endTime(m_endTime),
    openToNonResidents(m_openToNonResidents),
    ticketCost(m_ticketCost),
    ticketsRemaining(m_ticketsRemaining),
    amountOwed(m_amountOwed),
    confirmed(m_confirmed),
    isPrivate(m_private),
    layout(m_layout),
    waitlist(m_waitlist) { }
Event(string m_eventName, string m_organizer, int m_month, int m_day, string m_startTime, string m_endTime, bool m_private, 
    bool m_openToNonResidents,  int m_ticketCost, int m_ticketsRemaining, int m_amountOwed, string layoutString) :
    eventName(m_eventName),
    organizer(m_organizer),
    month(m_month),
    day(m_day),
    startTime(m_startTime),
    endTime(m_endTime),
    openToNonResidents(m_openToNonResidents),
    ticketCost(m_ticketCost),
    ticketsRemaining(m_ticketsRemaining),
    amountOwed(m_amountOwed),
    isPrivate(m_private) { 
        layout = getLayoutFromString(layoutString);
        confirmed = false;
}

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
    input>>obj.ticketsRemaining;
    input>>obj.amountOwed;
    string confirmedString;
    input>>confirmedString;
    if (confirmedString == "true") {
        obj.confirmed = true;
    }
    else {
        obj.confirmed = false;
    }
    string privateString;
    input>>privateString;
    if (privateString == "true") {
        obj.isPrivate = true;
    }
    else {
        obj.isPrivate = false;
    }
    string layoutString;
    input>>layoutString;
    obj.layout = getLayoutFromString(layoutString);
    string m;
    while(input>>m) {
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
    cout<<"Is Private: "<<boolalpha<<isPrivate<<endl;
    cout<<"Ticket cost: "<<ticketCost<<endl;
    cout<<"Tickets remaining: "<<ticketsRemaining<<endl;
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
int Event::getTicketsRemaining() {
    return ticketsRemaining;
}
int Event::getAmountOwed() {
    return amountOwed;
}
bool Event::getConfirmed() {
    return confirmed;
}
bool Event::getPrivate() {
    return isPrivate;
}
Layout Event::getLayout() {
    return layout;
}
deque<string> Event::getWaitlist() {
    return waitlist;
}
