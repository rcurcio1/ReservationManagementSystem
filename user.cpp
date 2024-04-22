#include "user.hpp"
#include <string>
#include <vector>

using namespace std;

User::User(string m_username, string m_password) {
    username = m_username;
    password = m_password;
} 
Resident::Resident(string username, string password) : User(username, password) { }
City::City(string username, string password) : User(username, password) { }
NonResident::NonResident(string username, string password) : User(username, password) { }

User::User() { }
Resident::Resident() { }
NonResident::NonResident() { }
City::City() { }


istream& operator>>(istream& input, Resident& obj) {
    input >> obj.username;
    input >> obj.password;
    return input;
}
istream& operator>>(istream& input, NonResident& obj) {
    input >> obj.username;
    input >> obj.password;
    return input;
}
istream& operator>>(istream& input, City& obj) {
    input >> obj.username;
    input >> obj.password;
    return input;
}

string User::getPassword() {
    return password;
}

string User::getUsername() {
    return username;
}
