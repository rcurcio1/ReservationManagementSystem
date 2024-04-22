#include "user.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// public vector<User*> initializeUsers() {

// }




int main() {
    //vector<User*> users = initializeUsers();
    User u1 = Resident("ross", "pword");
    cout<<u1.getPassword()<<endl;
    cout<<u1.getUsername()<<endl;

    City u2;
    cin>>u2;

    cout<<u2.getUsername()<<endl;
    cout<<u2.getPassword()<<endl;
}
