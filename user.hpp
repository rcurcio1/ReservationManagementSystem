#ifndef USER_H
#define USER_H

using namespace std;

enum UserType;

class User {
private:
    string username;
    string password;
public:
    void User(string username, string password);
    string getUsername();
    string getPassword();    
}

class Resident : public User {
public:
    void Resident(string username, string password);  
}

class NonResident : public User {
public:
    void NonResident(string username, string password);
}

class City : public User {
public:
    void City(string username, string password);
}

#endif
