#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
    string ownerName;

public:
    void createAccount() {
        cout << "Enter Account Holder Name: ";
        getline(cin, ownerName);

        cout << "Enter Account Number: ";
        getline(cin, accountNumber);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount Credited Successfully!"<<endl;
        } else {
            cout << "Invalid Amount!"<<endl;
        }
    }

    void debit(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount Debited Successfully!"<<endl;
        } else {
            cout << "Insufficient Balance or Invalid Amount!"<<endl;
        }
    }

    void addInterest(double rate) {
        double interest = balance * rate / 100;
        balance += interest;
        cout << "Interest Added: " << interest << endl;
    }

    void displayBalance() {
        cout <<endl<< "--- Account Details ---"<<endl;
        cout << "Account Holder: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc;
    double amount, rate;
    int choice;

    acc.createAccount();

    do {
        cout <<endl<< "----- MENU -----"<<endl;
        cout << "1. Credit Money"<<endl;
        cout << "2. Debit Money"<<endl;
        cout << "3. Add Interest"<<endl;
        cout << "4. Display Balance"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter amount to credit: ";
                cin >> amount;
                acc.credit(amount);
                break;

            case 2:
                cout << "Enter amount to debit: ";
                cin >> amount;
                acc.debit(amount);
                break;

            case 3:
                cout << "Enter interest rate (%): ";
                cin >> rate;
                acc.addInterest(rate);
                break;

            case 4:
                acc.displayBalance();
                break;

            case 5:
                cout << "Thank you!"<<endl;
                break;

            default:
                cout << "Invalid Choice!"<<endl;
        }

    } while(choice != 5);

    return 0;
}

//output
//----- MENU -----
//1. Credit Money
//2. Debit Money
//3. Add Interest
//4. Display Balance
//5. Exit
//Enter your choice: 1
//Enter amount to credit: 10000
//Amount Credited Successfully!
//
//----- MENU -----
//1. Credit Money
//2. Debit Money
//3. Add Interest
//4. Display Balance
//5. Exit
//Enter your choice: 4
//
//--- Account Details ---
//Account Holder: Liku
//Account Number: 15253615
//Current Balance: 160000