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
    cout<<j.getPassword()<<endl;
    cout<<j.getUsername()<<endl;

    User u2 = NonResident();
    cin>>u2;

    cout<<u2.getUsername<<endl;
    cout<<u2.getPassword<<endl;
}
