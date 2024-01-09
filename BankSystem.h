#ifndef BANKSYSTEM_H
#define BANKSYSTEM_H

const int Max = 100;

class BankAccount {
public:
    char Name[20];
    char LName[30];
    char PhoneNum[30];
    char City[30];
    char Address[100];
    int deposit;
    int Pass;
    int AccountNum;
};

class BankSystem {
private:
    BankAccount accounts[Max];
    int accountCount;

public:
    BankSystem();

    void displayMenu();
    void addAccount();
    void removeAccount();
    void editAccount();
    void changePassword();
    void showAllAccounts();
    void searchByName();
    void listAccountsByDeposit();
    void drawFromAccount();
    void transferAmount();
    void seeAccount();
    void runLottery();
    void handleInvalidChoice();
    void clearScreen();
    void waitForEnter();
    void run();
};

int random(int low, int high);

#endif // BANKSYSTEM_H
