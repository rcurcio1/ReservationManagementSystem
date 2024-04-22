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

std::istream& operator>>(std::istream& input, Resident& obj) {
    input >> obj.username;
    input >> obj.password;
    return input;
}
std::istream& operator>>(std::istream& input, NonResident& obj) {
    input >> obj.username;
    input >> obj.password;
    return input;
}
std::istream& operator>>(std::istream& input, City& obj) {
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
