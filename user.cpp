#include "user.hpp"
#include <string>
#include <vector>
#include <sstream>
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


istringstream& operator>>(istringstream& input, Resident& obj) {
    input>>obj.username;
    input>>obj.password;
    return input;
}
istringstream& operator>>(istringstream& input, NonResident& obj) {
    input>>obj.username;
    input>>obj.password;
    return input;
}
istringstream& operator>>(istringstream& input, City& obj) {
    input>>obj.username;
    input>>obj.password;
    return input;
}

string User::getPassword() {
    return password;
}

string User::getUsername() {
    return username;
}

bool Manager::isManager() override{
    return true;
}
bool City::isManager() override{
    return true;
}
bool Resident::isManager() override{
    return true;
}
bool NonResident::isManager() override{
    return true;
}

