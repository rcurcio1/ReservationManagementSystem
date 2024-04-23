#include "user.hpp"
#include "event.hpp"
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

const string MANAGER_USERNAME = "ccmanager13";
const string MANAGER_PASSWORD = "managerpassword";


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

void writeEvents(vector<Event*> events) {
    ofstream outfile("events.txt");
    for (int i=0; i < events.size(); i++) {
        Event* e = events[i];
        outfile<<e->getEventName()<<" "<<e->getOrganizer()<<" "<<e->getMonth()<<" "<<e->getDay()<<" "
            <<e->getStartTime()<<" "<<e->getEndTime()<<" "<<boolalpha<<e->getOpenToNonResidents()<<" "
            <<e->getTicketCost()<<" "<<e->getTicketsRemaining()<<" "<<e->getAmountOwed()<<" "<<boolalpha<<e->getConfirmed();
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

void viewEventSchedule(vector<Event*> events) {
    for (int i = 0; i < events.size(); i++) {
        Event* e = events[i];
        e->printEvent();
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    }
}

void printMenu() {
    cout<<"1. Quit program"<<endl;
    cout<<"2. View event schedule"<<endl;
    cout<<"3. Request reservation"<<endl;
    cout<<"4. Make payment"<<endl;
    cout<<"5. Cancel reservation"<<endl;
    cout<<"6. Purchase tickets"<<endl;
    cout<<"7. Cancel tickets"<<endl;
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
            printMenu();
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
}




int main() {
    vector<User*> users = initializeUsers();
    if (duplicateUsers(users)) {
        cout<<"Your users.txt file has users with duplicate usernames, please edit that file and try again!"<<endl;
        deleteUsers(users);
        return 0;
    }
    vector<Event*> events = initalizeEvents();
    events[0]->printEvent();
    deque<string> waitlist = events[0]->getWaitlist();
    for(int i = 0; i < waitlist.size(); i++) {
        cout<<waitlist[i]<<endl;
    }
    cout<<waitlist.size()<<endl;
    cout<<users[2]->getTickets()[0]<<endl;
    run(users, events);
    writeUsers(users);
    writeEvents(events);
    deleteUsers(users);
    deleteEvents(events);
}
