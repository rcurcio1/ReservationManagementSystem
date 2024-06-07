#include <string>
#include <vector>
#include <sstream>
#ifndef USER_H
#define USER_H

using namespace std;

// Parent class representing a general user of the system
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
    // Retrieve username
    string getUsername();
    // Retrieve password
    string getPassword();
    // Retrieve credit
    int getCredit();
    // Add the given amount to credit
    void changeCredit(int amount); 
    // Retrieve tickets
    vector<string> getTickets();
    // Remove the given string from the tickets
    void removeTicket(string t);
    // Add the given string to tickets
    void addTicket(string t);
    // Return whether the user has the given ticket
    bool hasTicket(string t);
    // Return the symbol used to represent the user type in the save file
    virtual char getSymbol(); 
    // Return how much the user type has to pay per hour for an event
    virtual int getHourly();
    // Return whether this user type can book weddings
    virtual bool canBookWeddings();
};

// Child class representing a resident of the community
class Resident : public User {
public:
    Resident();
    Resident(string username, string password, int credit, vector<string> tickets);  
    ~Resident() override;
    // Read from istringstream into Resident
    friend istringstream& operator>>(istringstream& input, Resident& obj);
    char getSymbol() override; 
    int getHourly() override;
    bool canBookWeddings() override;
};

// Child class representing someone who is not a resident of the community
class NonResident : public User {
public:
    NonResident();
    NonResident(string username, string password, int credit, vector<string> tickets);
    ~NonResident() override;
    // Read from istringstream into NonResident
    friend istringstream& operator>>(istringstream& input, NonResident& obj);
    char getSymbol() override; 
    int getHourly() override;
    bool canBookWeddings() override;
};

// Child class representing an account made on behalf of the city
class City : public User {
public:
    City();
    City(string username, string password, int credit, vector<string> tickets);
    ~City() override;
    // Read from istringstream into City
    friend istringstream& operator>>(istringstream& input, City& obj);
    char getSymbol() override; 
    int getHourly() override;
    bool canBookWeddings() override;
};

#endif
