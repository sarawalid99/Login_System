#include"CS112-203-2nd-Section10&9-20210495-20211054-20210215-A4-LoginFunctions.h"
vector <user> user_info;
fstream file;
int n = 0 ;
string decrypt;
bool check;
void rcvr_inf()
{

    user user1;
    file.open("user information.txt" , ios::in);

    while(!file.eof() && !file.fail())
        {
            getline(file,user1.Email);
            getline(file,user1.phone_number);
            getline(file,user1.name);
            getline(file,user1.username);
            getline(file,user1.password);
           for(int i =0;i<user1.password.length();i++){
                 if(!(user1.password[i] == '\n'))
                    {user1.password[i] -= 3;}
            }
            decrypt = "";
            user_info.push_back(user1);
        }
        file.close();

};


void sv_inf()
{   file.open("user information.txt", ios::out);
    for (int i=0; i < user_info.size() ;i++){
        for (int j=0; j < user_info[i].Email.size() ;j++)
            {
                file.put((user_info[i].Email)[j]);
            }
        file.put('\n');
    for (int j=0; j < user_info[i].phone_number.size() ;j++)
            {
                file.put(user_info[i].phone_number[j]);
            }
        file.put('\n');

        for (int j=0; j < user_info[i].name.size() ;j++)
            {
                file.put(user_info[i].name[j]);
            }
        file.put('\n');

        for (int j=0; j < user_info[i].username.size() ;j++)
            {
                file.put(user_info[i].username[j]);
            }
        file.put('\n');

        for (int j=0; j < user_info[i].password.size() ;j++)
            {
                user_info[i].password[j] += 3;
                file.put(user_info[i].password[j]);
            }
            if(i+1 != user_info.size())
                {file.put('\n');}

    }
    file.close();
}

void registeration()
{   int flag = 0;
    int counter = 0;
    user user1;
    regex mail_exp ("[a-zA-Z0-9_.-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+");
    regex phn_exp ("01[0-9]{9}");
    regex usrnm_exp ("[a-zA-Z0-9.-_\s]+");
    regex psswrd_exp ("(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])[a-zA-Z0-9]+{8,}");
    regex nm_exp ("[A-Z][a-z\s]{3,}");
    string mail;
    string phn_num;
    string nm;
    string usrnm ;
    string psswrd,psswrd_cnfrm ;
    while(true){
    if(counter == 0){
    cout << "please enter the Email address like the form user@mail.o" << endl;
    cout << "notice: before the @ capital letter,(-),(_),(.) and numbers are allowed"<<endl;
    cout << "but after @ only capital letters and (-) are allowed "<<endl;
    cout << "no special characters are allowed !!"<< endl;

    cin >> mail;
    if (!(regex_match(mail,mail_exp)))
        {
            system("cls");
            cout << "invalid email form" << endl;

            continue;
        }


 for (int i=0; i < user_info.size() ;i++)
    {
       if(user_info[i].Email == mail)
        {   system("cls");
            cout<<"this email already exists please try to use another email\n"<<endl;
            flag = 1;
            break;
        }
    }
    if(flag)
        {
            flag = 0;

            continue;

        }
    else
    {
        user1.Email = mail;
        counter+=1;
        system("cls");
    }
    }
   else if(counter == 1)
{
cout<<"now please enter your phone number as it's starts with 01 and has 11 degits"<<endl;
cin >> phn_num;
if(!(regex_match(phn_num,phn_exp)))
    {   system("cls");
        cout<< "invalid phone number form\n"<<endl;

        continue;
    }
 for (int i=0; i < user_info.size() ;i++)
    {
       if(user_info[i].phone_number == phn_num)
        {   system("cls");
            cout<<"this phone number already exists please try to use another phone number\n"<<endl;
            flag = 1;
            break;
        }
    }
    if(flag)
        {
            flag = 0;

            continue;

        }
    else
    {
        user1.phone_number = phn_num;
        counter+=1;
        system("cls");
    }
}
 else if(counter == 2)
{cout<<"now please enter your name"<<endl;
cout<<"notice: that names have capital letters at first , length of 4 letters or more and no numbers or special"<<endl;

            cin.clear();
            cin.sync();
            getline(cin,nm);


if(!(regex_match(nm,nm_exp)))
    {   system("cls");
        cout<< "invalid name form\n"<<endl;

        continue;
    }
 for (int i=0; i < user_info.size() ;i++)
    {
       if(user_info[i].name == nm)
        {   system("cls");
            cout<<"this name already exists please try to use another name\n"<<endl;
            flag = 1;

            break;
        }
    }
    if(flag)
        {
            flag = 0;

            continue;

        }
    else
    {
        user1.name = nm;
        counter+=1;
        system("cls");
    }
}

else if(counter == 3)
{

    cout <<"now please enter your username you can use (-),(.),(_) and numbers "<<endl;
    cout <<"you cannot use special characters"<<endl;
   cin.clear();
            cin.sync();
            getline(cin,usrnm);
    if(!(regex_match(usrnm,usrnm_exp)))
    {   system("cls");
        cout<< "invalid username form\n"<<endl;

        continue;
    }
 for (int i=0; i < user_info.size() ;i++)
    {
       if(user_info[i].username == usrnm)
        {   system("cls");
            cout<<"this username already exists please try to use another username\n"<<endl;
            flag = 1;

            break;
        }
    }
    if(flag)
        {
            flag = 0;

            continue;

        }
    else
    {
        user1.username = usrnm;
        counter+=1;
        system("cls");
    }
}
else if(counter == 4)
{
char letter;
    cout <<"now please enter your password"<<endl;
    cout <<"password should Capital and small letters and numbers"<<endl;
    cout <<"you cannot use special characters at all !!"<<endl;
    while(true)
        {
            letter = _getch();
            if(letter == 13){
                break;
            }
           else if(letter == 8)
                {
                     if(psswrd.length() != 0){
                         cout<< "\b \b";
                            psswrd.erase((psswrd.size()-1), 1);}
                }
            else if(letter < 0){
                letter = _getch();
            }
           else if((letter >= 65 && letter <=90 ) ||(letter >= 97 && letter <=122 ) || (letter >= 48 && letter <=57 )){
                psswrd += letter;
                cout<<"*";
            }


        }
         for (int i=0; i < user_info.size() ;i++)
    {
       if(user_info[i].password == psswrd)
        {   system("cls");
            cout<<"\n this password already exists please try to use another password\n"<<endl;
            flag = 1;

            break;
        }
    }


    if(!(regex_match(psswrd,psswrd_exp)))
    {   system("cls");
        cout<<"\nthis password is weak please follow the strong password instructions\n"<<endl;
        psswrd = "";

        continue;
    }




    cout << "\now please enter the password confirmation: " <<endl;
      while(true)
        {

             letter = _getch();
            if(letter == 13){
                break;
            }
           else if(letter == 8)
                {
                     if(psswrd_cnfrm.length() != 0){
                         cout<< "\b \b";
                            psswrd_cnfrm.erase((psswrd_cnfrm.size()-1), 1);}
                }
            else if(letter < 0){
                letter = _getch();
            }
           else if((letter >= 65 && letter <=90 )|| (letter >= 97 && letter <=122 )||  (letter >= 48 && letter <=57 )){
                psswrd_cnfrm += letter;
                cout<<"*";
            }



        }

    if(psswrd != psswrd_cnfrm)
        {   system("cls");
            cout <<"\nthe two passwords are not identical please try again\n"<<endl;
            psswrd_cnfrm = "";
            psswrd = "";

            continue;
        }
    if(flag)
        {
            flag = 0;

            continue;

        }
    else
    {
        user1.password = psswrd;
        counter+=1;
        system("cls");
    }


}
if(counter == 5)
{
    user_info.push_back(user1);
    cout <<"\nCongratulations you've successfully registerd !!" <<endl;
    for(int i=0 ; i < 1000000; i++){}
    system("cls");
    break;
}

}
}

bool log_in(){
    int flag1 = 0 , flag2 = 0 ;
    char letter;
    string user_name , psswrd;
    cout << "Enter username : ";
    cin >> user_name ;
    cout << "Enter password : ";
    while(true)
        {
            letter = _getch();
            if(letter == 13){
                break;
            }
           else if(letter == 8)
                {

                    if(psswrd.length() != 0){
                                cout<< "\b \b";
                            psswrd.erase((psswrd.size()-1), 1);}

                }
            else if(letter < 0){
                letter = _getch();
            }
           else if((letter >= 65 && letter <=90 )|| (letter >= 97 && letter <=122 )||  (letter >= 48 && letter <=57 )){
                psswrd += letter;
                cout<<"*";
            }

        }
        cout << endl;
    for (int i=0; i < user_info.size() ;i++)
    {
        if (user_info[i].username == user_name)
        {
            flag1 = 1;
            if (user_info[i].password== psswrd)
            {
                flag2 = 1;
                n = i;
                system("cls");
                break;
            }

//break;
        }
    }
    if (flag1 == 0)
    {system("cls");
        cout << "Wrong username , Try again "<< endl;
        return false ;
    }
    else if (flag2 == 0 )
    {system("cls");
        cout << "Wrong password , Try again " << endl;
        return false;
    }

    else
       {system("cls");
         cout << "Successful login , welcome " + user_info[n].name << endl;
         return true ;
       }
}

void change_pass(){
    int flag1 = 0;
    regex psswrd_exp ("(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])[a-zA-Z0-9]+{8,}");
    char letter;
    string psswrd = "" , new_psswrd = "", conf_psswrd = "";

    if(!check)
    {
        cout << "You have to log in to change your password "<< endl;
         for (int i =  0 ; i < 3 ; i++){
        if (log_in())
        {
            break ;
        }
        else if (i == 2)
        {system("cls");
            cout << "Failed login"<<endl;


            return ;
        }
    }
    }


    for (int i = 0 ; i < 3 ; i++){
    cout << "Enter the old password : ";
     while(true)
        {
            letter = _getch();
            if(letter == 13){
                break;
            }
           else if(letter == 8)
                {
                     if(psswrd.length() != 0){
                         cout<< "\b \b";
                            psswrd.erase((psswrd.size()-1), 1);}
                }
            else if(letter < 0){
                letter = _getch();
            }
           else if((letter >= 65 && letter <=90 ) ||(letter >= 97 && letter <=122 ) || (letter >= 48 && letter <=57 )){
                psswrd += letter;
                cout<<"*";
            }
        }
        if (user_info[n].password != psswrd)
        {system("cls");
            cout << " \n Wrong password " << endl;

            psswrd = "";
            if (i == 2)
            {
                return;
            }
        }
        else
        {
            system("cls");
            break;
        }
    }
    /****************************************************************************/
  for (int i = 0 ; i <3 ; i++){
     cout <<"\npassword should Capital and small letters and numbers"<<endl;
    cout <<"you cannot use special characters at all !!"<<endl;
     cout << "\n Enter new password : ";

     while(true)
        {
            letter = _getch();
            if(letter == 13){
                break;
            }
           else if(letter == 8)
                {
                     if(new_psswrd.length() != 0){
                         cout<< "\b \b";
                            new_psswrd.erase((new_psswrd.size()-1), 1);}
                }
            else if(letter < 0){
                letter = _getch();
            }
           else if((letter >= 65 && letter <=90 )|| (letter >= 97 && letter <=122 ) || (letter >= 48 && letter <=57 )){
                new_psswrd += letter;
                cout<<"*";
            }
        }

        if (psswrd == new_psswrd)
        {   system("cls");
                cout << "\n This password exists , Enter another password ";
                new_psswrd = "" ;
                if (i == 2)
                {

                    return;
                }
                else{continue;}
        }




            if (!regex_match(new_psswrd,psswrd_exp))
        {   system("cls");
            cout << "\n password is weak , please enter another password ";
            if (i == 2)
                {
                    return;
                }
            else{
                    continue;}
        }
        cout << "\nEnter the new password confirmation :";
        while(true)
        {
            letter = _getch();
            if(letter == 13){
                break;
            }
           else if(letter == 8)
                {
                     if(conf_psswrd.length() != 0){
                         cout<< "\b \b";
                            conf_psswrd.erase((conf_psswrd.size()-1), 1);}
                }
            else if(letter < 0){
                letter = _getch();
            }
           else if((letter >= 65 && letter <=90 )|| (letter >= 97 && letter <=122 )||  (letter >= 48 && letter <=57 )){
                conf_psswrd += letter;
                cout<<"*";
            }
        }
        if (conf_psswrd != new_psswrd)
           {    system("cls");
                cout << "\nThe two passwords are not identical " << endl;
                conf_psswrd = "";


           }
        else{
                break;}

}

    user_info[n].password = new_psswrd;
    system("cls");
    cout<<"password changed successfully!!"<<endl;

}
