#include <string>
#include <vector>
#include <sstream>
#ifndef USER_H
#define USER_H

using namespace std;

class User {
protected:
    string username;
    string password;
    vector<string*> tickets;
public:
    User();
    User(string username, string password);
    virtual ~User();
    string getUsername();
    string getPassword();   
    virtual bool isManager(); 
};

class Resident : public User {
public:
    Resident();
    Resident(string username, string password);  
    ~Resident() override;
    friend istringstream& operator>>(istringstream& input, Resident& obj);
    bool isManager() override; 
};

class NonResident : public User {
public:
    NonResident();
    NonResident(string username, string password);
    ~NonResident() override;
    friend istringstream& operator>>(istringstream& input, NonResident& obj);
    bool isManager() override;
};

class City : public User {
public:
    City();
    City(string username, string password);
    ~City() override;
    friend istringstream& operator>>(istringstream& input, City& obj);
    bool isManager() override;
};

class Manager : public User {
private:
    int budget;
public:
    Manager();
    Manager(string username, string password);
    ~Manager() override;
    bool isManager() override;
};

#endif
