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
    int credit;
    vector<string> tickets;
public:
    User();
    User(string username, string password, int credit, vector<string> tickets);
    virtual ~User();
    string getUsername();
    string getPassword();
    int getCredit();
    void changeCredit(int amount); 
    vector<string> getTickets();
    void removeTicket(string t);
    void addTicket(string t);
    virtual bool isManager();
    virtual char getSymbol(); 
    virtual int getHourly();
};

class Resident : public User {
public:
    Resident();
    Resident(string username, string password, int credit, vector<string> tickets);  
    ~Resident() override;
    friend istringstream& operator>>(istringstream& input, Resident& obj);
    bool isManager() override; 
    char getSymbol() override; 
    int getHourly() override;
};

class NonResident : public User {
public:
    NonResident();
    NonResident(string username, string password, int credit, vector<string> tickets);
    ~NonResident() override;
    friend istringstream& operator>>(istringstream& input, NonResident& obj);
    bool isManager() override;
    char getSymbol() override; 
    int getHourly() override;
};

class City : public User {
public:
    City();
    City(string username, string password, int credit, vector<string> tickets);
    ~City() override;
    friend istringstream& operator>>(istringstream& input, City& obj);
    bool isManager() override;
    char getSymbol() override; 
    int getHourly() override;
};

class Manager : public User {
private:
    int budget;
public:
    Manager();
    Manager(string username, string password);
    ~Manager() override;
    bool isManager() override;
    char getSymbol() override; 
    int getHourly() override;
};

#endif
