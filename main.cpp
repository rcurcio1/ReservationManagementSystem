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
    return;
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

void run(vector<User*> users, vector<Event*> events) {
    User* thisUser = nullptr;
    while(thisUser == nullptr) {
        thisUser = login(users);
    }
    if (thisUser->isManager()) {
        //runManager(users, events);
    }
    else {
        while(true) {
            printMenu();
            int choice;
            cout<<"Enter your selection: ";
            cin>>choice;
            switch(choice) {
                case 1:
                    viewEventSchedule(events);
                    break;
                case 2:
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
    vector<Event*> events = initalizeEvents();
    events[0]->printEvent();
    deque<string> waitlist = events[0]->getWaitlist();
    for(int i = 0; i < waitlist.size(); i++) {
        cout<<waitlist[i]<<endl;
    }
    cout<<waitlist.size()<<endl;
    run(users, events);
}
