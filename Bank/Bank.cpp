
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
