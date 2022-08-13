#include<iostream>
#include<string.h>
using namespace std;

class Bank {
protected:
public:
    float bank_balance;
    Bank(){
        bank_balance = 40000.00;
    }
//protected:
    float get_balance() {
        return bank_balance;
    }
}bnk;

class Employee : public Bank {

    int e_id;
    string e_name;
    string pass;
public :
    Employee(){
        e_id = 1;
        e_name = "Gaurang";
        pass = "G";
    }
    void disp_customer();
    void createAccount();
    friend void employee_choice(string name, string pas);
}admin;

class Customer : public Bank {
//protected:
public:
    int c_id;
    string c_name;
    string pass;
    string pin;
    float balance;
    Customer *next;
public:
    Customer(int id, string name, float blnc, string ps) {
        c_id = id;
        c_name = name;
        balance = blnc;
        pass = ps;
        next = NULL;
    }
    void pinCreate(int id);
    void check_cust_balance(int id);
    friend void customer_choice(int id);
}*head=NULL;

void Employee :: disp_customer()
{
    Customer * p = head;
    while(p!=NULL) {
        cout<<"\n--------------------------------------";
        cout<<"\nid : "<<p->c_id;
        cout<<"\nName: "<<p->c_name;
        cout<<"\nBalance: "<<p->balance;
        cout<<"\n--------------------------------------";
        p = p->next;
    }
}

void employee_choice(string name, string pas) {
    int ch;
    if(admin.e_name == name && admin.pass == pas) {
            cout<<"\nLogin successfully...\n";
        while(1) {
            cout<<"\n1. Show bank balance";
            cout<<"\n2. Create account(customer)";
            cout<<"\n3. Show all customers.";
            cout<<"\n0. goto previous menu.";
            cout<<"\nEnter your choice: ";
            cin>>ch;
            switch(ch) {

                case 1: cout<<"\n------------------------------------------------------";
                        cout<<"\nThe bank have total balance is : "<<bnk.get_balance();
                        cout<<"\n------------------------------------------------------";
                        break;

                case 2: admin.createAccount();
                        break;

                case 3: cout<<"\nThe details are follows as: ";
                        admin.disp_customer();
                        break;

                case 0: return;

                default : cout<<"\nInvalid choice!!";
            }
        }
    }
    else {
        cout<<"\nInvalid Id or Password..";
    }
}

void check_cust_balance(int id) {

    string pn;
    Customer *p = head;
    while(p!= NULL){
        if(id == p->c_id) {
            if(p->pin.empty()){
                cout<<"\nFirst enable your pin security.";
                break;
            }
            else{
                cout<<"Enter your pin: ";
                fflush(stdin);
                getline(cin,pn);
                if(pn == p->pin){
                    cout<<"\n------------------------------------\nAvailable balance: "<<p->balance<<"\n------------------------------------";
                    break;
                }
            }//end of empty else
        }// end of (id) if
        p = p->next;
    }// end of while
}// end of check_cust

void pinCreate(int id) {

    string pn1,pn2;
    Customer *p = head;
    while(p!= NULL){
        if(id == p->c_id) {

                if(p->pin.empty()) {
                    cout<<"\nEnter pin(pin must be 6 character): ";
                    fflush(stdin);
                    getline(cin,pn1);
                    if(pn1.length() == 6){
                        cout<<"\nConform pin: ";
                        fflush(stdin);
                        getline(cin,pn2);
                        if(pn1 == pn2){
                            p->pin = pn2;
                            cout<<"\nPin created successfully..";
                            break;
                        }
                        else {
                            cout<<"\nPin not matched..";
                        }
                    }
                    else{
                        cout<<"\nPlease,Enter pin only and only 6 digit.";
                    }
                }
            }
            p = p->next;
        }// end of while

}// end of pinCreate

void customer_choice(int id) {

    int valid = 0;
    string ps;
    Customer *p = head;
    while(p!= NULL){
        if(id == p->c_id) {
            cout<<"\nEnter your password: ";
            fflush(stdin);
            getline(cin,ps);
            if(ps == p->pass) {
                valid = p->c_id;
                cout<<"\nLogin successfully..\n";
                break;
            }
        }
        p = p->next;
    }
    if(valid == 0) {
        cout<<"\nInvalid password or id..\n";
        return;
    }
    else{
        int ch;
            while(1){
            cout<<"\n1. Enable pin security.";
            cout<<"\n2. Check your bank balance.";
            cout<<"\n3. Withdraw money.";
            cout<<"\n4. Deposit money.";
            cout<<"\n0. goto previous menu.";
            cout<<"\nEnter choice: ";
            cin>>ch;
            switch(ch) {

                case 1: pinCreate(id);
                        break;

                case 2: check_cust_balance(id);
                        break;

                case 3: withdrow_money(id);
                        break;

                case 0: return;

                default : cout<<"\nInvalid choice!!";
            }
        }
    }
}

void Employee :: createAccount() {

    int id;
    string name;
    float balance;
    string pass;
    cout<<"\nEnter customer id: ";
    cin>>id;
    cout<<"\nEnter the customer name: ";
    fflush(stdin);
    getline(cin,name);
    cout<<"Now how much money you want to add in your account: ";
    cin>>balance;
    cout<<"\nEnter your password: ";
    fflush(stdin);
    getline(cin,pass);
    bnk.bank_balance += balance;
    Customer* tmp = new Customer(id,name,balance,pass);
    if(head == NULL) {
        head = tmp;
    }
    else{
        Customer *p;
        p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }

    cout<<"\nAccount opening process successfully done.\nYour details follows as: ";
    cout<<"\nCustomer id: "<<id;
    cout<<"\nCustomer name: "<<name;
    cout<<"\nAvailable balance: "<<balance;
    cout<<"\nPassword: "<<pass;
}
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
