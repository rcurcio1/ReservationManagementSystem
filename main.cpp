#include "user.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// public vector<User*> initializeUsers() {

// }




int main() {
    //vector<User*> users = initializeUsers();
    User j = Resident("ross", "pword");
    cout<<j.getPassword()<<endl;
    cout<<j.getUsername()<<endl;
}
