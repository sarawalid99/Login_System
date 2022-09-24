#include "CS112-203-2nd-Section10&9-20210495-20211054-20210215-A4-LoginFunctions.h"
// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: login app.cpp
// Last Modification Date: 14/5/2022
// Abd El-fattah Mohammed Abd El- basset - 20210215
// Shahd Mostafa Mahmoud Badawy  20211054 -
// Sara Walid Farouk Mohamed  20210495 -
// Teaching Assistant:  Afaf
// Purpose:  system for registering new users, program asks
//the user if he wants to (1) Register, (2) Login, (3) Change Password, (4) Exit


int main()
{
    bool check;
    bool check1 = true;
    int option;
    rcvr_inf();

while(check1){
        {
     cout<<"Welcome to the registeration app!! "<<endl;
     cout<<"choose an option to do:  "<<endl;
     cout<<"  1- Register a new user"<<endl;
     cout<<"  2- login with your account"<<endl;
     cout<<"  3- change the password" <<endl;
     cout<<"  0- exit " <<endl;
}
cin >> option ;
if (option == 1)
     {
system("cls");
registeration();
     }
     else if (option == 2)
      {
    system("cls");
    for (int i =  0 ; i < 3 ; i++){
            check = log_in();
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
        change_pass();
     }
      else if (option == 0)
      {
system("cls");
cout <<" thanks for using our app :) "<<endl;
sv_inf();
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

