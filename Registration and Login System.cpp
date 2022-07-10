#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
using namespace std;

void Login();
void Register();
void Forgot();


int main()
{
  int Option;

 cout<<"*******Welcome to the Portal********\n\n";
 cout<<"..............MENU..............\n\n";
 cout<<"Press 1 to Login"<<endl;
 cout<<"Press 2 to Register"<<endl;
 cout<<"Press 3 if you forgot the password"<<endl;
 cout<<"Press 4 to Exit"<<endl;
 cout<<"Enter your Option:";
 cin>>Option;

 switch(Option)
  {
 case 1:
      Login();
      break;
 case 2:
      Register();
      break;
 case 3:
     Forgot();
     break;
 case 4:
      cout<<"*******THANK YOU*******"<<endl;
      break;

 default:
       system("cls");
      cout<<" Please select Options from 1 to 4 "<<endl;
      main();
  }

}

//Defining Login function

void Login()

{
int cnt=0;
string Username,Password,Mobile_No,userId,pin,mobile_no;
system("cls");
cout<<" Enter the Username and Password"<<endl;//User has to login using username and password
cout<<" Enter USERNAME: ";
cin>>userId;
cout<<" Enter PASSWORD: ";
cin>>pin;
ifstream input("data.txt");
  while(input>>Username>>Password)
  {
      if((Username==userId)&&(Password==pin))
        {
          cnt=1;
          system("cls");
        }

  }
  input.close();

    if(cnt==1)
    {
     cout<<"Your LOGIN is Successful \n\n";
     main();
    }
    else
    {  cout<<" LOGIN ERROR.USER is not registered \n\n";
       main();
    }

}



//Defining  Registration function
void Register()
{
    int cnt=0;
    string reg_Id,reg_pin,Username,Password;
    system("cls");
    cout<<"Create USERNAME: ";
    cin>>reg_Id;
    cout<<"Create Password: ";
    cin>>reg_pin;
    ifstream input("data.txt");
  while(input>>Username>>Password)
  {
      if(Username==reg_Id||Password==reg_pin)
        {
          cnt=1;
          system("cls");
        }

  }
  input.close();

    if(cnt==1)
    {
        cout<<"Already Username/Password exist.Try with different credentials\n";
        main();
    }

    else{
    ofstream f1("data.txt",ios::app);//write inside the file ,file gets open and app append the text at the end
    f1<<reg_Id<<"     "<<reg_pin<<endl;
    system("cls");
    cout<<"   Registration is Sucessfull   \n";
    main();
    }
}



//Defining forgot function
void Forgot()
{
   int Option;
   system("cls");
   cout<<" You forgot the password.No Problem "<<endl;
   cout<<"Press 1 to search your id by USERNAME"<<endl;
   cout<<"Press 2 to go back to the main menu"<<endl;
   cout<<"Enter your choice: ";
   cin>>Option;
   switch(Option)
   {
   case 1:
    {
        int cnt=0;
        string userId,f_Id,f_pass;
        cout<<"Enter the username you have remembered:";
        cin>>userId;

        ifstream f2("data.txt");
        while(f2>>f_Id>>f_pass)
        {
            if(f_Id==userId)
            {
                cnt=1;
            }
        }
        f2.close();

        if(cnt==1)
        {
            cout<<"Your account is Found \n";
            cout<<"Your password is:  "<<f_pass;
            cout<<"\n\n";
            main();
        }
        else
        {
            cout<<"Sorry, your account is not found ";
            cout<<"\n\n";
            main();
        }
        break;

    }
   case 2:
       {
       main();
       }

   default:
       {
    cout<<"Wrong choice.Please try again"<<endl;
    main();
       }
   }
}












