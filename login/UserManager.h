#ifndef USERM_H
#define USERM_H


#include <iostream>
#include <vector>
#include <string>
#include "User.h"

using namespace std;

class UserManager{
    private:
        vector<User> users;
    public:
        bool login(string name, string pass);
        void registerUser();
        void showUsers();
};

#endif