#include "LoginFunctions.h"

int main(){
    bool check;
    bool check1 = true;
    int option;
    receiveInfo();

    while(check1){
            {
         cout << "Welcome to the registeration app!! \n";
         cout << "choose an option to do:\n";
         cout << "1- Register a new user\n";
         cout << "2- login with your account\n";
         cout << "3- change the password\n";
         cout << "0- exit\n";
    }
    cin >> option ;
    if (option == 1)
         {
    system("cls");
    registration();
         }
         else if (option == 2)
          {
        system("cls");
        for (int i =  0 ; i < 3 ; i++){
                check = logIn();
            if (check)
            {
                break ;
            }
            else if (i == 2)
            {
                cout << "Failed login"<<endl;
            }

        }
          }
          else if (option == 3)
         {
              system("cls");
              changePassword();
         }
          else if (option == 0)
          {
    system("cls");
    cout <<" thanks for using our app :) "<<endl;
    saveInfo();
    check1 = false;
          }
          else {
            system("cls");
            cout << "invalid option please try again !!"<<endl;
            cin.clear();
            cin.sync();
          }

    }

    return 0;
}

