#include <string>
#include <sstream>
#include <deque>
#ifndef EVENT_H
#define EVENT_H
using namespace std;

// Enum representing possible layouts of events
enum Layout{MEETING, LECTURE, WEDDING, DANCE};

// Class representing an event that is being booked in the facility manager system
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
        int m_ticketCost, int m_ticketsRemaining, int m_amountOwed, bool m_confirmed, bool m_private, Layout m_layout, deque<string> m_waitlist);
    Event(string m_eventName, string m_organizer, int m_month, int m_day, string m_startTime, string m_endTime, bool m_private, 
        bool m_openToNonResidents,  int m_ticketCost, int m_ticketsRemaining, int m_amountOwed, string layout);
    // Neatly display the event
    void printEvent();
    // Read the contents of an istringstream into an event
    friend istringstream& operator>>(istringstream& input, Event& obj);
    /*
    GETTERS
    */
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
    // Remove the person at the front of the waitlist and return them
    string removeFromWaitlist();
    // Add the given person to the back of the waitlist
    void addToWaitlist(string t);
    // Confirm the event
    void confirmEvent();
    // Pay of the given amount that is owed
    void payOff(int amount);
    // Remove one ticket from availability
    void sellTicket();
    // Add one ticket to availability
    void returnTicket();
};

#endif
