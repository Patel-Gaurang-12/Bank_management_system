
using namespace std;

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
    void withdraw_money(int id);
    void deposit_money(int id);
    void edit_info(int id);
    void check_cust_balance(int id);
    friend void customer_choice(int id);
}*head=NULL;


void pinCreate(int id) {

    string pn1,pn2;
    Customer *p = head;
    while(p!= NULL){
        if(id == p->c_id) {

                if(p->pin.empty()) {
                        start:
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
                else {
                    int ch;
                    cout<<"\nPIN already have created,\nYou want to create again?\n 1 for Yes and 0 for no.";
                    cin>>ch;
                    if(ch == 1){
                        cout<<"\nEnter your previous PIN:";
                        fflush(stdin);
                        getline(cin,pn1);
                        if(pn1 == p->pin){
                            goto start;
                        }
                        else {
                            cout<<"\nInvalid PIN.";
                            break;
                        }
                    }
                    else {
                        cout<<"\nThank you..";
                        return;
                    }
                }
            }
            p = p->next;
        }// end of while

}// end of pinCreate

void check_cust_balance(int id) {

    string pn;
    Customer *p = head;
    while(p!= NULL){
        if(id == p->c_id) {
            if(p->pin.empty()){
                cout<<"\nYour PIN is not generated,\nPlease, first generate your pin...\n";
                break;
            }
            else{
                cout<<"\nEnter your pin: ";
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

void withdraw_money(int id) {

    float money;
    string pn;
    Customer *p = head;

    cout<<"\nEnter money: ";
    cin>>money;
    while(p!=NULL) {
        if(p->c_id == id) {
            if(p->pin.empty()) {
                cout<<"\nYour PIN is not generated,\nPlease, first generate your pin...\n";
                break;
            }
            cout<<"\nEnter your PIN: ";
            fflush(stdin);
            getline(cin,pn);
            if(p->pin == pn) {
                if(money > p->balance) {
                    cout<<"\nInsufficient Balance.";
                }
                else {
                    p->balance -= money;
                    cout<<"\nPlease,collect your money.\nThank you.";
                }
                break;
            }
            else {
                cout<<"\nInvalid PIN.";
            }
        }// end of if (id)
        p = p->next;
    }// end of while
}//end of Withdraw money

void deposit_money(int id) {

    float money;
    string pn;
    Customer *p = head;

    cout<<"\nEnter money: ";
    cin>>money;
    while(p!=NULL) {
        if(p->c_id == id) {
            if(p->pin.empty()) {
                cout<<"\nYour PIN is not generated,\nPlease, first generate your pin...\n";
                break;
            }
            cout<<"\nEnter PIN: ";
            fflush(stdin);
            getline(cin,pn);
            if(p->pin == pn) {
                if(money < 10) {
                    cout<<"\nInvalid number!!.";
                }
                else {
                    p->balance += money;
                    cout<<"\nMoney deposit successfully.\nThank you.";
                }
            }
            else {
                cout<<"\nInvalid PIN...";
            }
            break;
        }
        p = p->next;
    }
}// end of deposit

void edit_info(int id) {

    int ch;
    string ps;
    Customer *p = head;
    while(p != NULL) {
        if(p->c_id == id) {
            cout<<"\nEnter password: ";
            fflush(stdin);
            getline(cin,ps);
            if(ps == p->pass) {
            cout<<"\n1. Name";
            cout<<"\n2. Password";
            cout<<"\n0. exit";
            cout<<"\nEnter choice: ";
            cin>>ch;
            switch(ch) {
                case 1: cout<<"\nEnter a new name: ";
                        fflush(stdin);
                        getline(cin,p->c_name);
                        break;

                case 2: cout<<"\nEnter a new password: ";
                        fflush(stdin);
                        getline(cin,p->pass);
                        break;

                case 0: return;

                default : cout<<"\nInvalid choice!!";
                }
            }
        }
        p = p->next;
    }
}// end of edit_info

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
            cout<<"\n1. Generate PIN.";
            cout<<"\n2. Check your bank balance.";
            cout<<"\n3. Withdraw money.";
            cout<<"\n4. Deposit money.";
            cout<<"\n5. Edit your information.";
            cout<<"\n0. goto previous menu.";
            cout<<"\nEnter choice: ";
            cin>>ch;
            switch(ch) {

                case 1: pinCreate(id);
                        break;

                case 2: check_cust_balance(id);
                        break;

                case 3: withdraw_money(id);
                        break;

                case 4: deposit_money(id);
                        break;

                case 5: edit_info(id);
                        break;

                case 0: return;

                default : cout<<"\nInvalid choice!!";
            }
        }
    }
}
