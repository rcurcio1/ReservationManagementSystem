#include "user.hpp"
#include <string>
#include <vector>

using namespace std;

User::User(string m_username, string m_password) {
    username = m_username;
    password = m_password;
} 
Resident::Resident(string username, string password) : User(username, password) { }


string User::getPassword() {
    return password;
}

string User::getUsername() {
    return username;
}
