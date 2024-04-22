#include <string>
#include <sstream>
#ifndef USER_H
#define USER_H

using namespace std;

class User {
protected:
    string username;
    string password;
    vector<Ticket*> tickets;
public:
    User();
    User(string username, string password);
    string getUsername();
    string getPassword();   
    virtual bool isManager(); 
};

class Resident : public User {
public:
    Resident();
    Resident(string username, string password);  
    friend istringstream& operator>>(istringstream& input, Resident& obj);
    bool isManager() override; 
};

class NonResident : public User {
public:
    NonResident();
    NonResident(string username, string password);
    friend istringstream& operator>>(istringstream& input, NonResident& obj);
    bool isManager() override;
};

class City : public User {
public:
    City();
    City(string username, string password);
    friend istringstream& operator>>(istringstream& input, City& obj);
    bool isManager() override;
};

class Manager : public User {
private:
    int budget;
public:
    Manager();
    Manager(string username, string password);
    bool isManager() override;
}

#endif
