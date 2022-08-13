#include "Customer.cpp"
using namespace std;

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
    void delete_cust(int id);
    friend void employee_choice(string name, string pas);
}admin;


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

void Employee :: delete_cust(int id) {

    string ps;
    int flg = 0;
    Customer *tmp,*p;
    p = head;
    while(p!= NULL) {
        if(p->c_id == id) {
            cout<<"\nEnter password: ";
            fflush(stdin);
            getline(cin,ps);
            if(ps == p->pass) {
                tmp->next = p->next;
                free(p);
                cout<<"\nDelete successfully..";
                flg = 1;
                break;
            }
        }//end of if (id)
        tmp = p;
        p = p->next;
    }// end of while
    if(flg == 0) {
        cout<<"\nSomething, went wrong!!";
    }
}// end of delete_cust

void employee_choice(string name, string pas) {
    int ch,id;
    if(admin.e_name == name && admin.pass == pas) {
            cout<<"\nLogin successfully...\n";
        while(1) {
            cout<<"\n1. Show bank balance";
            cout<<"\n2. Create account(customer)";
            cout<<"\n3. Show all customers.";
            cout<<"\n4. Delete customer.";
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

                case 4: cout<<"Enter customer id to delete: ";
                        cin>>id;
                        admin.delete_cust(id);
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
