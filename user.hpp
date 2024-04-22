#include <string>
#ifndef USER_H
#define USER_H

using namespace std;

class User {
private:
    string username;
    string password;
public:
    User(string username, string password);
    string getUsername();
    string getPassword();    
};

class Resident : public User {
public:
    Resident(string username, string password);  
};

class NonResident : public User {
public:
    NonResident(string username, string password);
};

class City : public User {
public:
    City(string username, string password);
};

#endif
