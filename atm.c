#include <stdio.h>
#include <stdlib.h>

// Function declarations
void checkBalance(float balance);
float depositMoney(float balance);
float withdrawMoney(float balance);

int main() {
    float balance = 10000.0;  // Initial balance
    int pin, enteredPin;
    int choice;
    char cont;

    pin = 1234;  // Default PIN

    printf("*******************************\n");
    printf("      WELCOME TO C BANK ATM    \n");
    printf("*******************************\n\n");

    printf("Enter your 4-digit PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin != pin) {
        printf("Incorrect PIN! Access denied.\n");
        return 0;
    }

    do {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        printf("\n========= ATM MAIN MENU =========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("=================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = depositMoney(balance);
                break;
            case 3:
                balance = withdrawMoney(balance);
                break;
            case 4:
                printf("\nThank you for using C BANK ATM!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }

        printf("\nDo you want to perform another transaction? (y/n): ");
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y');

    printf("\nThank you! Have a nice day!\n");
    return 0;
}

// Function to display balance
void checkBalance(float balance) {
    printf("\nYour current balance is: ₹%.2f\n", balance);
}

// Function to deposit money
float depositMoney(float balance) {
    float deposit;
    printf("\nEnter amount to deposit: ₹");
    scanf("%f", &deposit);

    if (deposit <= 0) {
        printf("Invalid deposit amount.\n");
    } else {
        balance += deposit;
        printf("₹%.2f deposited successfully!\n", deposit);
        printf("Updated balance: ₹%.2f\n", balance);
    }
    return balance;
}

// Function to withdraw money
float withdrawMoney(float balance) {
    float withdraw;
    printf("\nEnter amount to withdraw: ₹");
    scanf("%f", &withdraw);

    if (withdraw <= 0) {
        printf("Invalid withdrawal amount.\n");
    } else if (withdraw > balance) {
        printf("Insufficient balance!\n");
    } else {
        balance -= withdraw;
        printf("Please collect your cash: ₹%.2f\n", withdraw);
        printf("Remaining balance: ₹%.2f\n", balance);
    }
    return balance;
}
