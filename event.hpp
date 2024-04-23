#include <string>
#include <sstream>
#include <deque>
#ifndef EVENT_H
#define EVENT_H
using namespace std;

enum Layout{MEETING, LECTURE, WEDDING, DANCE};


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
    int ticketsRemaining;
    int amountOwed;
    bool confirmed;
    bool isPrivate;
    Layout layout;
    deque<string> waitlist;
public:
    Event();
    Event(string m_eventName, string m_organizer, int m_month, int m_day, string m_startTime, string m_endTime, bool m_openToNonResidents, 
        int m_ticketCost, int m_ticketsRemaining, int m_amountOwed, int m_confirmed, bool m_private, Layout m_layout, deque<string> m_waitlist);
    void printEvent();
    friend istringstream& operator>>(istringstream& input, Event& obj);
    string getEventName();
    string getOrganizer();
    int getMonth();
    int getDay();
    string getStartTime();
    string getEndTime();
    bool getOpenToNonResidents();
    int getTicketCost();
    int getTicketsRemaining();
    int getAmountOwed();
    bool getConfirmed();
    bool getPrivate();
    Layout getLayout();
    deque<string> getWaitlist();
    void confirmEvent();
    void payOff(int amount);
};

#endif
