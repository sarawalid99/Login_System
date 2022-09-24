#ifndef CS112-203-2nd-Section10&9-20210495-20211054-20210215-A4-LoginFunctions_H
#define CS112-203-2nd-Section10&9-20210495-20211054-20210215-A4-LoginFunctions_H

#include <Windows.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
#include <conio.h>

using namespace std;
void rcvr_inf();
void sv_inf();
void registeration();
bool log_in();

void change_pass();

struct user{
    string Email ;
    string phone_number;
    string name ;
    string username ;
    string password ;
    };

#endif
