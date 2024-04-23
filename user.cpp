#include "user.hpp"
#include <string>
#include <vector>
#include <sstream>
using namespace std;

User::User(string m_username, string m_password, int m_credit, vector<string> m_tickets) {
    username = m_username;
    password = m_password;
    credit = m_credit;
    tickets = m_tickets;
} 
Resident::Resident(string username, string password, int credit, vector<string> tickets) : User(username, password, credit, tickets) { }
City::City(string username, string password, int credit, vector<string> tickets) : User(username, password, credit, tickets) { }
NonResident::NonResident(string username, string password, int credit, vector<string> tickets) : User(username, password, credit, tickets) { }

User::User() { }
Resident::Resident() { }
NonResident::NonResident() { }
City::City() { }
Manager::Manager() { }

User::~User() { }
Resident::~Resident() { }
NonResident::~NonResident() { }
City::~City() { }
Manager::~Manager() { }



istringstream& operator>>(istringstream& input, Resident& obj) {
    input>>obj.username;
    input>>obj.password;
    input>>obj.credit;
    string m;
    while(input>>m) {
        obj.tickets.push_back(m);
    }
    return input;
}
istringstream& operator>>(istringstream& input, NonResident& obj) {
    input>>obj.username;
    input>>obj.password;
    input>>obj.credit;
    string m;
    while(input>>m) {
        obj.tickets.push_back(m);
    }
    return input;
}
istringstream& operator>>(istringstream& input, City& obj) {
    input>>obj.username;
    input>>obj.password;
    input>>obj.credit;
    string m;
    while(input>>m) {
        obj.tickets.push_back(m);
    }
    return input;
}

string User::getPassword() {
    return password;
}
string User::getUsername() {
    return username;
}
bool User::isManager() { 
    return false;
}
bool Manager::isManager() {
    return true;
}
bool City::isManager() {
    return false;
}
bool Resident::isManager() {
    return false;
}
bool NonResident::isManager() {
    return false;
}

char User::getSymbol() {
    return ' ';
}
char City::getSymbol() {
    return 'C';
}
char Manager::getSymbol() {
    return 'M';
}
char Resident::getSymbol() {
    return 'R';
}
char NonResident::getSymbol() {
    return 'N';
}

