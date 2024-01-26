#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
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
        stoi(name);
    }

    return false;
}

void UserManager::registerUser(string name, string pass){
    User newUser(name, pass);
    users.push_back(newUser);
}

void UserManager::showUsers(){
    cout << "-------------User List-------------" << endl << endl;
    for(int i=0; i<users.size(); i++){
        cout << users[i].getUser() << endl;
    }
}

void UserManager::deleteUser(string s){
    for(int i=0; i<users.size(); i++){
        if(users[i].getUser()==s){
            users.erase(users.begin() + i);
        }
    }

}

bool UserManager::searchUser(string s){
    //s = userInputCheck(s);
    bool searched = false;
    for(int i=0; i<users.size(); i++){
        cout << "Searched " << users[i].getUser() << endl;
        if(users[i].getUser()==s){
            searched = true;
            break;
        }
    }
    return searched;
}

bool UserManager::userInputCheck(string s){
/* Ensures username only consists of the following: 
    - username does not start with a number
    - alphanumeric characters
    - '-' and '_'
*/ 
    bool valid = false;
    string check = s.at(0) + "";
    int numCheck;

    for (int i=0; i<s.size(); i++){
        cout << s[i];
        if(s[i] != '-' || s[i] != '_' || !isalnum(s[i]) || !isspace(s[i])){
            valid = true;
            break;
        }
    }


    /*
    if((stoi(check)>=0) && (stoi(check)<=9)){
        return valid;
    }else{
        for (int i=0; i<s.size(); i++){
            cout << s[i];
            if(s[i] != '-' || s[i] != '_' || !isalnum(s[i]) || !isspace(s[i])){
                valid = true;
                break;
            }
        }
    }
    */
    return valid;

}

bool UserManager::passInputCheck(string s){
    return true;
}

string UserManager::userInputMod(string s){
    //lowercase username
    for(int i=0; i<s.size(); i++){
        if(isalpha(s[i])){
            tolower(s[i]);
        }
    }

    cout << "New username checked is " << s << endl;

    return s;
}
