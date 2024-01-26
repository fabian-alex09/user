#include <string>
#include <iostream>
#include "User.h"

using namespace std;


User::User(string name, string pass){
    username = name;
    password = pass;
}

void User::showData(){
    cout << "Username is " << username << endl;
    cout << "Password is " << password << endl;
}

string User::getUser(){
    return username;
}

string User::getPassword(){
    return password;
}

