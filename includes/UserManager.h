#ifndef USERM_H
#define USERM_H

#include <iostream>
#include <vector>
#include <string>
#include "User.h"

using namespace std;

class UserManager{
    private:
        vector<User> users; //data structure for username and passwords
        string hashPass(string s); //returns message digest for password
    public:
        bool login(string name, string pass);
        void registerUser(string name, string pass);
        void showUsers(); //lists all users
        void deleteUser(string s);
        bool searchUser(string s);
        bool userInputCheck(string s); //checks if username string is valid
        bool passInputCheck(string s);//checks if password is valid
        string userInputMod(string s); //lowers alphabet char && removes whitespace

};

#endif