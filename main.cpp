#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "includes/UserManager.h"


using namespace std;


void choiceFunc(int &choice, UserManager &m);

int main(){
    UserManager manager;
    int choice;

    do{
        cout << endl << "-----------------------------------------------------" << endl << endl;
        cout << "Please select one of the following choices: " << endl;
        cout << "\t 1 - Register User" << endl;
        cout << "\t 2 - Login" << endl;
        cout << "\t 3 - Show Users" << endl;
        cout << "\t 4 - Search User" << endl;
        cout << "\t 5 - Delete User" << endl;
        cout << "\t 6 - Exit" << endl << endl;

        cout << "Input:  ";

        cin >> choice;

        if(cin.fail()){
            cin.clear();
            cin.ignore();
            choice = 7;
        }
        choiceFunc(choice, manager);                  
        
    }while(choice!=6);
    

    return 0;
}

void choiceFunc(int &choice, UserManager &m){
    string name, pass;
    bool valid;

    switch (choice){
        case 1:
            do{
                cout << "Enter Username: ";
                cin >> name;

                valid = m.userInputCheck(name);
                if(!valid){
                    cout << endl << "Error. Username must comply with the following: " << endl
                        << "    Username cannot start with a number" << endl 
                        << "    Username can only contain the characters A-Z, a-z, 0-9, '-', and '_'." << endl << endl;
                }

                //name = m.userInputMod(name);
            }while(!valid);

            do{
                cout << "Enter Password: ";
                cin >> pass;

                valid = m.passInputCheck(pass);
                if(!valid){
                    cout << endl <<"Error. Password can only contain the characters A-Z, a-z, 0-9, '-', and '_'." << endl << endl;
                }
            }while(!valid);


            m.registerUser(name, pass);
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
            cout << "Search user name: ";
        
            cin >> name;

            if(m.searchUser(name)){
                cout << endl << "User " << name << " is in database!" << endl << endl;
            }else{
                cout << endl << "User " << name << " is not in database!" << endl << endl;
            }
            
            break;
        case 5:
            cout << "Delete user name: ";
      
            cin >> name;

            if(m.searchUser(name)){
                m.deleteUser(name);
                cout << endl << "User " << name << " is now deleted from database!" << endl << endl;
            }else{
                cout << endl << "User " << name << " is not in database!" << endl << endl;
            }

            break;
        case 6:
            cout << "Thank you for your time! " << endl << endl;
            break;
        case 7:
            cout << endl << "ERROR! Unknown input." << endl << endl;
            break;
        default:
            cout << "ERROR! Unknown input. Goodbye." << endl << endl;
            break;
    }
} 
