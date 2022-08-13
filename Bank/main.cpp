#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Bank.cpp"
#include "employee.cpp"

using namespace std;

int main() {

    int ch;
    string name,pass;
    while(1) {
        cout<<"\n1. Employee";
        cout<<"\n2. Customer";
        cout<<"\nEnter choice: ";
        cin>>ch;
        switch(ch) {

            case 1: cout<<"Enter name: ";
                    fflush(stdin);
                    getline(cin,name);
                    cout<<"Enter password: ";
                    fflush(stdin);
                    getline(cin,pass);
                    employee_choice(name,pass);
                    break;

            case 2: cout<<"Enter id: ";
                    cin>>ch;
                    customer_choice(ch);
                    break;

            case 0: exit(0);
            default : cout<<"Invalid Choice!!";
        }
    }
}
