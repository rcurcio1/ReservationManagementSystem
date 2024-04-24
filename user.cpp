#include "user.hpp"
#include <string>
#include <algorithm>
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

User::~User() { }
Resident::~Resident() { }
NonResident::~NonResident() { }
City::~City() { }



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
int User::getCredit() {
    return credit;
}
void User::changeCredit(int amount) {
    credit += amount;
}
vector<string> User::getTickets() {
    return tickets;
}
string User::getPassword() {
    return password;
}
string User::getUsername() {
    return username;
}

char User::getSymbol() {
    return ' ';
}
char City::getSymbol() {
    return 'C';
}
char Resident::getSymbol() {
    return 'R';
}
char NonResident::getSymbol() {
    return 'N';
}

int User::getHourly() {
    return 0;
}
int City::getHourly() {
    return 5;
}
int Resident::getHourly() {
    return 10;
}
int NonResident::getHourly() {
    return 15;
}

void User::removeTicket(string t) {
    tickets.erase(find(tickets.begin(), tickets.end(), t));
}
void User::addTicket(string t) {
    tickets.push_back(t);
}
bool User::hasTicket(string t) {
    return find(tickets.begin(), tickets.end(), t) != tickets.end();
}
