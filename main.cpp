#include "user.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;


vector<User*> initializeUsers() {
    vector<User*> users;
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        char type;
        iss>>type;
        switch(type) {
            case 'C':
            {
                City* c = new City();
                iss>>*c;
                users.push_back(c);
                break;
            }
            case 'R':
            {
                Resident* r = new Resident();
                iss>>*r;
                users.push_back(r);
                break;
            }
            case 'N':
            {
                NonResident* n = new NonResident();
                iss>>*n;
                users.push_back(n);
                break;
            }
        }
    }
    file.close();
    return users;
}

int main() {
    vector<User*> users = initializeUsers();
    for (int i=0; i < users.size(); i++) {
        User* u = users[i];
        cout<<u->getUsername()<<":"<<u->getPassword()<<endl;
    }
    User u1 = Resident("ross", "pword");
    cout<<u1.getPassword()<<endl;
    cout<<u1.getUsername()<<endl;

    //City u2;
    //cin>>u2;

    //cout<<u2.getUsername()<<endl;
    //cout<<u2.getPassword()<<endl;
}
