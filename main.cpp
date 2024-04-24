#include "user.hpp"
#include "event.hpp"
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

const string MANAGER_USERNAME = "ccmanager13";
const string MANAGER_PASSWORD = "managerpassword";
const int TODAY_MONTH = 4;
const int TODAY_DAY = 23;


void deleteUsers(vector<User*> users) {
    for (User* u : users) {
        delete u;
    }
}

void deleteEvents(vector<Event*> events) {
    for (Event* e: events) {
        delete e;
    }
}

void writeUsers(vector<User*> users) {
    ofstream outfile("users.txt");
    for (int i =0 ; i <users.size(); i++) {
        User* u = users[i];
        outfile<<u->getSymbol()<<" "<<u->getUsername()<<" "<<u->getPassword()<<" "<<u->getCredit();
        vector<string> tickets = u->getTickets();
        for (int j=0; j < tickets.size(); j++) {
            outfile<<" "<<tickets[j];
        }
        outfile<<endl;
    }
    outfile.close();
}

bool duplicateUsers(vector<User*> users) {
    for (int i = 0; i < users.size(); i++) {
        for (int j = i+1; j < users.size(); j++) {
            User* u1 = users[i];
            User* u2 = users[j];
            if (u1->getUsername() == u2->getUsername()) {
                return true;
            }
        }
    }
    return false;
}

string getStringFromLayout(Layout l) {
    if (l == WEDDING) {
        return "wedding";
    }
    if (l == LECTURE) {
        return "lecture";
    }
    if (l == MEETING) {
        return "meeting";
    }
    else {
        return "dance";
    }
}

void writeEvents(vector<Event*> events) {
    ofstream outfile("events.txt");
    for (int i=0; i < events.size(); i++) {
        Event* e = events[i];
        string layoutString = getStringFromLayout(e->getLayout());
        outfile<<e->getEventName()<<" "<<e->getOrganizer()<<" "<<e->getMonth()<<" "<<e->getDay()<<" "
            <<e->getStartTime()<<" "<<e->getEndTime()<<" "<<boolalpha<<e->getOpenToNonResidents()<<" "
            <<e->getTicketCost()<<" "<<e->getTicketsRemaining()<<" "<<e->getAmountOwed()<<" "
            <<boolalpha<<e->getConfirmed()<<" "<<e->getPrivate()<<" "<<layoutString;
        deque<string> waitlist = e->getWaitlist();
        for (int j=0; j < waitlist.size(); j++) {
            outfile<<" "<<waitlist[j];
        }
        outfile<<endl;
    }
    outfile.close();
}


vector<User*> initializeUsers() {
    vector<User*> users;
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        char type;
        iss>>type;
        switch(type) {
            case 'C':
            {
                City* c = new City();
                iss>>*c;
                users.push_back(c);
                break;
            }
            case 'R':
            {
                Resident* r = new Resident();
                iss>>*r;
                users.push_back(r);
                break;
            }
            case 'N':
            {
                NonResident* n = new NonResident();
                iss>>*n;
                users.push_back(n);
                break;
            }
        }
    }
    file.close();
    return users;
}

vector<Event*> initalizeEvents() {
    vector<Event*> events;
    ifstream file("events.txt");
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        Event* e = new Event();
        iss>>*e;
        events.push_back(e);
    }
    file.close();
    return events;
}

User* login(vector<User*> users) {
    string username;
    string password;
    cout<<"Login as a user in the Community Center Management System"<<endl;
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;
    for (int i = 0; i < users.size(); i++) {
        User* u = users[i];
        if (u->getUsername() == username and u->getPassword() == password) {
            return u;
        }
    }
    if (username == MANAGER_USERNAME and password == MANAGER_PASSWORD) {
        return new Manager();
    }
    cout<<"Incorrect user and password, try again!";
    return nullptr;
}

bool withinWeek(Event* e) {
    int month = e->getMonth();
    int day = e->getDay();
    if (month == TODAY_MONTH) {
        return (day - TODAY_DAY <=7) and TODAY_DAY <= day;
    }
    else if (month - TODAY_MONTH == 1) {
        return day + 23 <= TODAY_DAY;
    }
    else {
        return false;
    }
}

void viewEventSchedule(vector<Event*> events) {
    cout<<"Would you like to view events for today, the next week, or all events? (Enter 'day', 'week', or 'all')";
    string selection;
    cin>>selection;
    if (selection == "day") {
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        for (int i = 0; i < events.size(); i++) {
            Event* e = events[i];
            cout<<e->getMonth()<<" "<<e->getDay()<<endl;
            if (e->getMonth() == TODAY_MONTH and e->getDay() == TODAY_DAY) {
                e->printEvent();
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            }
        }
    }
    else if (selection == "week") {
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        for (int i = 0; i < events.size(); i++) {
            Event* e = events[i];
            if (withinWeek(e)) {
                e->printEvent();
                cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            }
        }
    }
    else if (selection == "all") {
        for (int i = 0; i < events.size(); i++) {
            Event* e = events[i];
            e->printEvent();
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        }
    }
}


bool getBoolFromString(string s) {
    if (s == "true" or s == "True") {
        return true;
    }
    else {
        return false;
    }
}

int getMilitaryTime(string timeString) {
    if (timeString == "9am") {
        return 9;
    }
    if (timeString == "10am") {
        return 10;
    }
    if (timeString == "11am") {
        return 11;
    }
    if (timeString == "12pm") {
        return 12;
    }
    if (timeString == "1pm") {
        return 13;
    }
    if (timeString == "2pm") {
        return 14;
    }
    if (timeString == "3pm") {
        return 15;
    }
    if (timeString == "4pm") {
        return 16;
    }
    if (timeString == "5pm") {
        return 17;
    }
    if (timeString == "6pm") {
        return 18;
    }
    if (timeString == "7pm") {
        return 19;
    }
    if (timeString == "8pm") {
        return 20;
    }
    if (timeString == "9pm") {
        return 21;
    }
    return 21;
}

int calculateCost(User* thisUser, string startTime, string endTime) {
    int hourly = thisUser->getHourly();
    int hours = getMilitaryTime(endTime) - getMilitaryTime(startTime);
    return hourly * hours + 10;
}

int getDaysAway(Event* e) {
    int days = ((e->getMonth() - TODAY_MONTH) * 30) + (e->getDay() - TODAY_DAY);
    if (days < 0) {
        return -1;
    }
    return days;
}

vector<Event*> removeEvent(vector<Event*> events, Event* rem) {
    vector<Event*> newEvents;
    for (int i =0; i < events.size(); i++) {
        Event* e = events[i];
        if (e != rem) {
            newEvents.push_back(e);
        }
        else {
            delete e;
        }
    }
    return newEvents;
}

void refundEventCost(Event* e, vector<User*> users) {
    for (User* u : users) {
        if (u->getUsername() == e->getOrganizer()) {
            int refundAmount = calculateCost(u, e->getStartTime(), e->getEndTime());
            refundAmount = (refundAmount - e->getAmountOwed()) - 10;
            u->changeCredit(refundAmount);
        }
    }
}

bool tryReserveEventForCity(vector<Event*> &events, vector<User*> users, Event* newEvent) {
    for (int i = 0; i < events.size(); i++) {
        Event* e = events[i];
        if (newEvent->getDay() == e->getDay() and newEvent->getMonth() == e->getMonth()) {
            int newStart = getMilitaryTime(newEvent->getStartTime());
            int newEnd = getMilitaryTime(newEvent->getEndTime());
            int end = getMilitaryTime(e->getEndTime());
            int start = getMilitaryTime(e->getStartTime());
            if ((newStart < end and newEnd >= end) or (newStart <= start and newEnd > start) or (newStart > start and newEnd < end)) {
                if (e->getConfirmed() or (not e->getConfirmed() and getDaysAway(e) <= 7)) {
                    e->confirmEvent();
                    cout<<"Unable to reserve event, overlaps with a confirmed booking"<<endl;
                    return false;
                }
                else {
                    cout<<"Removing event "<<e->getEventName()<<endl;
                    refundEventCost(e, users);
                    events = removeEvent(events, e);
                    delete e;
                }
            }
        }
    }
    return true;
}

bool tryReserveEventForNonCity(vector<Event*> events, Event* newEvent) {
    for (int i = 0; i < events.size(); i++) {
        Event* e = events[i];
        if (newEvent->getDay() == e->getDay() and newEvent->getMonth() == e->getMonth()) {
            int newStart = getMilitaryTime(newEvent->getStartTime());
            int newEnd = getMilitaryTime(newEvent->getEndTime());
            int end = getMilitaryTime(e->getEndTime());
            int start = getMilitaryTime(e->getStartTime());
            if ((newStart < end and newEnd >= end) or (newStart <= start and newEnd > start) or (newStart > start and newEnd < end)) {
                cout<<"Unable to reserve event, overlaps with "<<e->getEventName()<<endl;
                return false;
            }
        }
    }
    return true;
}

void requestReservation(vector<Event*> &events, vector<User*> users, User* thisUser) {
    cout<<"Hi, welcome to the reservation request menu, before making a reservation, there are a few things to note:"<<endl;
    cout<<" -- The facility is open daily from 9am to 9pm"<<endl;
    cout<<" -- Individuals can reserve a maximum of 24 hours in the facility per week"<<endl;
    cout<<" -- Cities can reserve a maximum of 48 hours in the facility per week"<<endl;
    cout<<" -- Prices: $10 non-refundable service charge + $5/hr for cities, $10/hr for residents, $15/hr for"<<endl;
    cout<<"    non-residents"<<endl;
    cout<<" -- Reservations made by individuals over 7 days in advance may be overrode by City reservations"<<endl;
    cout<<"    if they have not been confirmed"<<endl;
    cout<<" -- To confirm a reservation, it must be paid in full or it must be within 7 days of the event"<<endl;
    cout<<"Enter event name: ";
    string eventName;
    cin>>eventName;
    cout<<"Enter event month (as integer from 1 to 12): ";
    int month;
    cin>>month;
    cout<<"Enter event day (as integer from 1 to 31): ";
    int day;
    cin>>day;
    cout<<"Enter start time (i.e. 11am, 7pm, etc.): ";
    string startTime;
    cin>>startTime;
    cout<<"Enter end time (i.e. 11am, 7pm, etc.): ";
    string endTime;
    cin>>endTime;
    cout<<"Event private? (true or false) ";
    string privateString;
    cin>>privateString;
    bool isPrivate = getBoolFromString(privateString);
    bool openToNonResidents;
    if (not isPrivate) {
        cout<<"Event open to non-residents? (true or false) ";
        string nonResidentsString;
        cin>>nonResidentsString;
        openToNonResidents = getBoolFromString(nonResidentsString);
    }
    else {
        openToNonResidents = true;
    }
    cout<<"Enter ticket cost (int): ";
    int ticketCost;
    cin>>ticketCost;
    cout<<"How many tickets would you like available (int, max 25): ";
    int ticketCount;
    cin>>ticketCount;
    if (ticketCount > 25) {
        ticketCount = 25;
    }
    cout<<"Enter layout for event (wedding, dance, meeting, lecture): ";
    string layoutString;
    cin>>layoutString;
    int cost = calculateCost(thisUser, startTime, endTime);
    cout<<"COST: $"<<cost<<endl;
    if (10 > thisUser->getCredit()) {
        cout<<"Sorry you do not have enough money to cover the service charge, please transfer money to your account and try again!"<<endl;
        return;
    }
    Event* e = new Event(eventName, thisUser->getUsername(), month, day, startTime, endTime, isPrivate, openToNonResidents, ticketCost, ticketCount, cost, layoutString);
    e->printEvent();
    if (thisUser->getHourly() == 5) {
        if(tryReserveEventForCity(events, users, e)) {
            e->confirmEvent();
            events.push_back(e);
            cout<<"Event added to reservations and confirmed"<<endl;
        }
        else {
            delete e;
            return;
        }
    }
    else {
        if(tryReserveEventForNonCity(events, e)) {
            events.push_back(e);
            cout<<"Event added to reservations"<<endl;
            if (getDaysAway(e) <= 7) {
                e->confirmEvent();
                cout<<"Event confirmed"<<endl;
            }
        }
        else {
            delete e;
            return;
        }
    }
    thisUser->changeCredit(-10);
    e->payOff(10);
    cout<<"We just charged you the $10 service fee, you owe another $"<<e->getAmountOwed()<<", how much more"<<endl;
    cout<<"would you like to pay now? Reminder that your booking is not confirmed until it is payed off. ";
    int paying;
    cin>>paying;
    if (paying > thisUser->getCredit()) {
        cout<<"You cannot afford to pay off that much right now. Add credit to your account and pay again from the main menu!";
    }
    else {
        thisUser->changeCredit(-paying);
        e->payOff(paying);
    }
    if (e->getAmountOwed() < 0) {
        cout<<"Event confirmed"<<endl;
        e->confirmEvent();
    }
}


void runManager(vector<User*> users, vector<Event*> events) {
    while(true) {
        //printManagerMenu();
        int choice;
        cout<<"Enter your selection: ";
        cin>>choice;
        switch(choice) {
            case 1:
                return;
            case 2:
                viewEventSchedule(events);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
        }
    }
}

void makePayment(vector<Event*> events, User* thisUser) {
    for (Event* e: events) {
        if (e->getOrganizer() == thisUser->getUsername() and e->getAmountOwed() > 0) {
            cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout<<"You owe $"<<e->getAmountOwed()<<" for the event "<<e->getEventName()<<"."<<endl;
            cout<<"How much of that amount would you like to pay off? ";
            int pay;
            cin>>pay;
            if (pay <= thisUser->getCredit()) {
                thisUser->changeCredit(-pay);
                e->payOff(pay);
                if (e->getAmountOwed() == 0) {
                    e->confirmEvent();
                    cout<<"Event fully payed off and confirmed!"<<endl;
                }
            }
            else {
                cout<<"You do not have enough credit to pay that off. You have $"<<thisUser->getCredit()<<" in credit."<<endl;
            }
        }
    }
}

void transferMoney(User* thisUser) {
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"Enter amount to transfer into your account: ";
    int amount;
    cin>>amount;
    if (amount < 0) {
        cout<<"Cannot transfer negative amount into your account."<<endl;
    }
    else {
        thisUser->changeCredit(amount);
    }
}

void cancelEvent(vector<Event*> &events, vector<User*> users, User* thisUser) {
    for (int i=0; i <events.size(); i++) {
        Event* e = events[i];
        if (e->getOrganizer() == thisUser->getUsername()) {
            cout<<"Would you like to cancel "<<e->getEventName()<<"? (yes or no) ";
            string choice;
            cin>>choice;
            if (choice == "yes") {
                for (User* u : users) {
                    vector<string> tickets = u->getTickets();
                    if (find(tickets.begin(), tickets.end(), e->getEventName()) != tickets.end()) {
                        u->removeTicket(e->getEventName());
                        u->changeCredit(e->getTicketCost());
                    }
                }
                events.erase(find(events.begin(), events.end(), e));
                delete e;
                i--;
            }
        }
    }
}
void buyTickets(vector<Event*> events, User* thisUser) {
    if (thisUser->getHourly() == 5) {
        cout<<"Cannot buy tickets as a City user!"<<endl;
        return;
    }
    for (Event* e: events) {
        if (not e->getPrivate() and not thisUser->hasTicket(e->getEventName()) and not (thisUser->getHourly() == 15 and not e->getOpenToNonResidents())) {
            cout<<"Would you like to buy a ticket to "<<e->getEventName()<<" on "<<
            e->getMonth()<<"/"<<e->getDay()<<" from "<<e->getStartTime()<<" to "<<e->getEndTime()<<" for $"<<e->getTicketCost()<<"? (yes or no) ";
            string choice;
            cin>>choice;
            if (choice == "yes") {
                if (e->getTicketsRemaining() == 0) {
                    cout<<"No tickets remaining, adding you to waitlist. Make sure you have $"<<e->getTicketCost()<<" in credit so we can get you a ticket as soon as a spot opens up!"<<endl;
                    e->addToWaitlist(thisUser->getUsername());
                }
                else if (thisUser->getCredit() >= e->getTicketCost()) {
                    thisUser->addTicket(e->getEventName());
                    thisUser->changeCredit(-e->getTicketCost());
                    e->sellTicket();
                }
                else {
                    cout<<"Sorry, you do not have enough credit to buy this ticket!"<<endl;
                }
            }
        }
    }
}

void printMenu(User* thisUser) {
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"CREDIT: $"<<thisUser->getCredit()<<endl;
    cout<<"1. Quit program"<<endl;
    cout<<"2. View event schedule"<<endl;
    cout<<"3. Request reservation"<<endl;
    cout<<"4. Make payment"<<endl;
    cout<<"5. Cancel reservation"<<endl;
    cout<<"6. Purchase tickets"<<endl;
    cout<<"7. Cancel tickets"<<endl;
    cout<<"8. Transfer money into account"<<endl;
}

void run(vector<User*> &users, vector<Event*> &events) {
    User* thisUser = nullptr;
    while(thisUser == nullptr) {
        thisUser = login(users);
    }
    if (thisUser->isManager()) {
        runManager(users, events);
    }
    else {
        while(true) {
            printMenu(thisUser);
            int choice;
            cout<<"Enter your selection: ";
            cin>>choice;
            switch(choice) {
                case 1:
                    return;
                case 2:
                    viewEventSchedule(events);
                    break;
                case 3:
                    requestReservation(events, users, thisUser);
                    break;
                case 4:
                    makePayment(events, thisUser);
                    break;
                case 5:
                    cancelEvent(events, users, thisUser);
                    break;
                case 6:
                    buyTickets(events, thisUser);
                    break;
                case 7:
                    //sellTickets();
                    break;
                case 8:
                    transferMoney(thisUser);
            }
        }
    }
}




int main() {
    vector<User*> users = initializeUsers();
    if (duplicateUsers(users)) {
        cout<<"Your users.txt file has users with duplicate usernames, please edit that file and try again!"<<endl;
        deleteUsers(users);
        return 0;
    }
    vector<Event*> events = initalizeEvents();
    run(users, events);
    writeUsers(users);
    writeEvents(events);
    deleteUsers(users);
    deleteEvents(events);
}
