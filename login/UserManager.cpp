#include <iostream>
#include <vector>
#include <string>
#include "UserManager.h"
#include "User.h"

using namespace std;

bool UserManager::login(string name, string pass){

    for(int i=0; i<users.size(); i++){
        if(users[i].getUser()==name && users[i].getPassword()==pass){
            return true;
            break;
        }else{
            return false;
            break;
        }
    }

    return false;
}

void UserManager::registerUser(){
    string name, pass;
    cout << "Enter Username: ";
    cin >> name;
    //check if username is not already taken
    cout << "Enter Password: ";
    cin >> pass;

    User newUser(name, pass);
    users.push_back(newUser);
}

void UserManager::showUsers(){
    cout << "-------------User List-------------" << endl << endl;
    for(int i=0; i<users.size(); i++){
        cout << users[i].getUser() << endl;
    }
}