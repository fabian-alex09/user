#include <iostream>
#include <string>
#include <vector>
#include "login/UserManager.h"

using namespace std;


void choiceFunc(int choice, UserManager &m);

int main(){
    UserManager manager;
    int choice;

    do{
        cout << endl << "-----------------------------------------------------" << endl << endl;
        cout << "Please select one of the following choices: " << endl;
        cout << "\t 1 - Register User" << endl;
        cout << "\t 2 - Login" << endl;
        cout << "\t 3 - Show Users" << endl;
        cout << "\t 4 - Exit" << endl << endl;

        cout << "Input:  ";

        cin >> choice; 

        choiceFunc(choice, manager);       
    }while(choice!=4);
    

    return 0;
}

void choiceFunc(int choice, UserManager &m){
    string name, pass;

    switch (choice){
        case 1:
            m.registerUser();
            break;
        case 2:
            cout << "Enter Username: ";
            cin >> name;
            cout << "Enter Password: " ;
            cin >> pass;

            cout << endl;
            if(m.login(name,pass)==true){
                cout << "Welcome, " << name << "!"<< endl;
            }else{
                cout << "Either username or password is incorrect." << endl;
            }
            m.login(name, pass);
            break;
        case 3:
            m.showUsers();
            break;
        case 4:
            cout << "Thank you for your time! We hope to see you again." << endl;
        default:
            cout << "Number not included in menu. Please try again." << endl << endl;
    }
}