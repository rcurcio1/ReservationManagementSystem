#include "user.hpp"
#include <vector>
#include <string>

using namespace std;

// public vector<User*> initializeUsers() {

// }




public int main() {
    //vector<User*> users = initializeUsers();
    User j = Resident("ross", "pword");
    cout<<j.getPassword()<<endl;
    cout<<j.getUsername()<<endl;
}