#ifndef LoginFunctions_H
#define LoginFunctions_H

#include <Windows.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
#include <conio.h>

using namespace std;
void receiveInfo();
void saveInfo();
void registration();
bool logIn();

void changePassword();

struct user{
    string Email ;
    string phone_number;
    string name ;
    string username ;
    string password ;
    };

#endif
