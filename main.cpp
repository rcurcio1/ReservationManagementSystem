#include "user.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


public vector<User*> initializeUsers() {
    vector<User*> users;
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        char type;
        iss>>type;
        switch(type) {
            case 'C':
                City u;
                iss>>u;
                user.push_back(u);
            case 'R':
                Resident u;
                iss>>u;
                user.push_back(u);
            case 'N':
                NonResident u;
                iss>>u;
                user.push_back(u);
        }
    }
    return users;
}

int main() {
    vector<User*> users = initializeUsers();
    User u1 = Resident("ross", "pword");
    cout<<u1.getPassword()<<endl;
    cout<<u1.getUsername()<<endl;

    City u2;
    cin>>u2;

    cout<<u2.getUsername()<<endl;
    cout<<u2.getPassword()<<endl;
}
