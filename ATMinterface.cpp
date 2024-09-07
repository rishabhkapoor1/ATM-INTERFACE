#include <iostream>
#include <string>

using namespace std;

// Function prototypes
void displayMenu();
void deposit(double &balance);
void withdraw(double &balance);
void checkBalance(const double &balance);
bool validatePIN(const string &enteredPIN);

int main() {
    // Constants and initial values
    const string correctPIN = "1234"; // Default PIN
    double balance = 1000.00; // Starting balance
    string enteredPIN;
    int choice;

    // PIN validation
    cout << "Enter your PIN: ";
    cin >> enteredPIN;

    if (!validatePIN(enteredPIN)) {
        cout << "Invalid PIN. Exiting.\n";
        return 1; // Exit with error code
    }

    while (true) {
        // Display menu and get user's choice
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: // Deposit
                deposit(balance);
                break;
            case 2: // Withdraw
                withdraw(balance);
                break;
            case 3: // Check Balance
                checkBalance(balance);
                break;
            case 4: // Exit
                cout << "Thank you for using the ATM. Goodbye!\n";
                return 0; // Exit with success code
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}

// Function to display the ATM menu
void displayMenu() {
    cout << "\nATM Menu:\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. Check Balance\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Function to handle deposit
void deposit(double &balance) {
    double amount;
    cout << "Enter deposit amount: ";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "Deposit successful. Your new balance is $" << balance << endl;
    } else {
        cout << "Invalid amount. Deposit failed.\n";
    }
}

// Function to handle withdrawal
void withdraw(double &balance) {
    double amount;
    cout << "Enter withdrawal amount: ";
    cin >> amount;

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrawal successful. Your new balance is $" << balance << endl;
    } else if (amount > balance) {
        cout << "Insufficient funds. Withdrawal failed.\n";
    } else {
        cout << "Invalid amount. Withdrawal failed.\n";
    }
}

// Function to check balance
void checkBalance(const double &balance) {
    cout << "Your current balance is $" << balance << endl;
}

// Function to validate the PIN
bool validatePIN(const string &enteredPIN) {
    const string correctPIN = "1234"; // Default PIN
    return enteredPIN == correctPIN;
}
