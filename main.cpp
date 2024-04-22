#include "user.hpp"
#include "event.hpp"
#include <vector>
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
    vector<User*> users;
    ifstream file("events.txt");
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        Event* e = new Event();
        iss>>*e;
        events.push_back(e);
    }
    file.close();
    return users;
}

User* login(vector<User*> users) {
    string username;
    string password;
    cout<<"Login as a user in the Community Center Management System"<<endl;
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>pasword;
    for (int i = 0; i < users.size(); i++) {
        User* u = users[i];
        if (u->getUsername() == username and u->getPassword() == password) {
            return u;
        }
    }
    if (username == "ccmanager" and password == "ccpassword13") {
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
                    viewEventSchedule(events);
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
            }
        }
    }
}


int main() {
    vector<User*> users = initializeUsers();
    vector<Event*> events = initalizeEvents();
    run(users);
}
