#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class temp{
    string Email,Password,userName;
    string searchName,searchEmail,searchPassword;
    fstream file;
    public:
    void Login();
    void SignUp();
    void Forget_Password();
}obj;
int main(){
    char choice;
    cout<<"\n 1- Login";
    cout<<"\n 2- SignUp";
    cout<<"\n 3- Forget Password";
    cout<<"\n 4- Exit";
    cout<<"\nEnter your Choice:: ";
    cin>>choice;
    cin.ignore();
    switch(choice){
        case '1':
            obj.Login();
        break;
        case '2':
            obj.SignUp();
        break;
        case '3':
            obj.Forget_Password();
        break;
        case '4':
            return 0;
        break;
        default:
        cout<<"Invalid Selection....!";
    }
}
void temp :: SignUp(){
    cout<<"Enter User Name ::";
    getline(cin,userName);

    cout<<"Enter Email Address ::";
    getline(cin,Email);

    cout<<"Enter Password ::";
    getline(cin,Password);

    file.open("LoginData.txt",ios::out|ios::app);
    file<<userName<<"*"<<Email<<"*"<<Password<<endl;
    file.close();
}
void temp::Login() {
    string searchName, searchPassword;
    bool found = false;
    cout << "**************LOGIN***************" << endl;
    cout << "Enter User Name ::" << endl;
    getline(cin, searchName);
    cout << "Enter Password ::";
    getline(cin, searchPassword);
    file.open("LoginData.txt", ios::in);
    while (getline(file, userName, '*')) {
        getline(file, Email, '*'); 
        getline(file, Password);
        if (userName == searchName && Password == searchPassword) {
            found = true;
            cout << "\nAccount Login Successfully....!";
            cout << "\nUsername :" << userName << endl;
            cout << "\nEmail :" << Email << endl;
            break;
        }
    }
    if (!found) {
        cout << "Username or Password is Incorrect....!";
    }
    file.close();
}
void temp::Forget_Password() {
    cout << "Enter Username ::";
    getline(cin, searchName);
    cout << "Enter Your Email Address ::";
    getline(cin, searchEmail);
    file.open("LoginData.txt", ios::in);
    bool found = false; 
    while (getline(file, userName, '*')) {
        getline(file, Email, '*');
        getline(file, Password);
        if (userName == searchName && Email == searchEmail) {
            found = true;
            cout << "Account Found...!" << endl;
            cout << "Your Password is: " << Password << endl;
            break; 
        }
    }
    if (!found) {
        cout << "Account Not Found." << endl;
    }
    file.close();
}