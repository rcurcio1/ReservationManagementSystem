#include <string>
#ifndef USER_H
#define USER_H

using namespace std;

class User {
protected:
    string username;
    string password;
public:
    User();
    User(string username, string password);
    string getUsername();
    string getPassword();    
};

class Resident : public User {
public:
    Resident();
    Resident(string username, string password);  
    friend std::istream& operator>>(std::istream& input, Resident& obj);
};

class NonResident : public User {
public:
    NonResident();
    NonResident(string username, string password);
    friend std::istream& operator>>(std::istream& input, NonResident& obj);
};

class City : public User {
public:
    City();
    City(string username, string password);
    friend std::istream& operator>>(std::istream& input, City& obj);
};

#endif
