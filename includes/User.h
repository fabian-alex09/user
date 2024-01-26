#ifndef USER_H
#define USER_H

#include <string.h>
using namespace std;

class User{
    private:
        string username;
        string password;
    public:
        User(string name, string pass);
        void showData();
        string getUser();
        string getPassword();
};

#endif
