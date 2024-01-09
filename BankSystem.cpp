#include "BankSystem.h"
#include "FileHandler.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <chrono>

using namespace std;

BankSystem::BankSystem() : accountCount(0) {}

void BankSystem::displayMenu() {
    cout << "--------------------------------------------------\n";
    cout << "1. Add new account\n";
    cout << "2. Remove account\n";
    cout << "3. Edit account\n";
    cout << "4. Change Password\n";
    cout << "5. Show all accounts\n";
    cout << "6. Search based on First and Last name\n";
    cout << "7. List of accounts with more than a given number\n";
    cout << "8. Draw from account\n";
    cout << "9. Transfer\n";
    cout << "10. Seeing account\n";
    cout << "11. Lottery\n";
    cout << "12. Exit\n";
    cout << "--------------------------------------------------\n";
    cout << "Choose: ";
}

void BankSystem::addAccount() {
    if (accountCount >= Max) {
        cout << "Memory Full!" << endl;
        return;
    }

    cout << "Enter account number " << accountCount + 1 << "'s information:\n";
    cout << "Name: ";
    cin.getline(accounts[accountCount].Name, 20);
    cout << "Last name: ";
    cin.getline(accounts[accountCount].LName, 30);
    cout << "Phone number: ";
    cin.getline(accounts[accountCount].PhoneNum, 30);
    cout << "City: ";
    cin.getline(accounts[accountCount].City, 30);
    cout << "Address: ";
    cin.getline(accounts[accountCount].Address, 100);

    accounts[accountCount].deposit = 0;
    accounts[accountCount].Pass = random(1000, 10000);
    accounts[accountCount].AccountNum = random(100000000, 1000000000);

    cout << "Account number: " << accounts[accountCount].AccountNum << endl;
    cout << "Password: " << accounts[accountCount].Pass << endl;

    accountCount++;
}

void BankSystem::removeAccount() {
    if (accountCount <= 0) {
        cout << "No accounts available to remove.\n";
        return;
    }

    int accountNumber, password;
    cout << "Enter account details to remove the account:\n";
    cout << "Account number: ";
    cin >> accountNumber;
    cout << "Password: ";
    cin >> password;

    int accountIndex = -1;

    for (int i = 0; i < accountCount; ++i) {
        if (accountNumber == accounts[i].AccountNum && password == accounts[i].Pass) {
            accountIndex = i;
            break;
        }
    }

    if (accountIndex != -1) {
        cout << "Are you sure you want to remove " << accounts[accountIndex].Name << " " << accounts[accountIndex].LName << "? (Y or N): ";
        char confirmation;
        cin >> confirmation;

        if (confirmation == 'Y' || confirmation == 'y') {
            for (int p = accountIndex; p < accountCount - 1; ++p) {
                accounts[p] = accounts[p + 1];
            }
            --accountCount;
            cout << "Account successfully removed.\n";
        } else {
            cout << "Account removal canceled.\n";
        }
    } else {
        cout << "Account not found. Please check the provided account number and password.\n";
    }
}


void BankSystem::editAccount() {
    if (accountCount <= 0) {
        cout << "No accounts available to edit.\n";
        return;
    }

    int accountNumber, password;
    cout << "Enter account details to edit the account:\n";
    cout << "Account number: ";
    cin >> accountNumber;
    cout << "Password: ";
    cin >> password;

    bool accountFound = false;

    for (int i = 0; i < accountCount; ++i) {
        if (accounts[i].AccountNum == accountNumber && accounts[i].Pass == password) {
            accountFound = true;

            cout << "Enter new information for the account:\n";
            cout << "New Name: ";
            cin.ignore(); // Ignore newline character
            cin.getline(accounts[i].Name, 20);
            cout << "New Last name: ";
            cin.getline(accounts[i].LName, 30);
            cout << "New Phone number: ";
            cin.getline(accounts[i].PhoneNum, 30);
            cout << "New City: ";
            cin.getline(accounts[i].City, 30);
            cout << "New Address: ";
            cin.getline(accounts[i].Address, 100);

            cout << "\nAccount successfully edited.\n";
            break;
        }
    }

    if (!accountFound) {
        cout << "Account not found. Please check the provided account number and password.\n";
    }
}


void BankSystem::changePassword() {
    if (accountCount <= 0) {
        cout << "No accounts available to change password.\n";
        return;
    }

    int accountNumber, currentPassword, newPassword, newPasswordConfirm;
    cout << "Enter account details to change the password:\n";
    cout << "Account number: ";
    cin >> accountNumber;
    cout << "Current Password: ";
    cin >> currentPassword;

    for (int i = 0; i < accountCount; ++i) {
        if (accounts[i].AccountNum == accountNumber && accounts[i].Pass == currentPassword) {
            cout << "Enter new password: ";
            cin >> newPassword;
            cout << "Enter new password again: ";
            cin >> newPasswordConfirm;

            if (newPassword == newPasswordConfirm && newPassword > 999 && newPassword < 10000) {
                accounts[i].Pass = newPassword;
                cout << "Password successfully changed.\n";
            } else {
                cout << "Invalid password. Make sure the new password is four digits and matches the confirmation.\n";
            }
            return;
        }
    }

    cout << "Account not found or incorrect password. Please check the provided account number and current password.\n";
}

void BankSystem::showAllAccounts() {
    if (accountCount <= 0) {
        cout << "No accounts available to display.\n";
    } else {
        for (int i = 0; i < accountCount; ++i) {
            cout << "Name: " << accounts[i].Name << endl;
            cout << "Last name: " << accounts[i].LName << endl;
            cout << "Phone number: " << accounts[i].PhoneNum << endl;
            cout << "City: " << accounts[i].City << endl;
            cout << "Address: " << accounts[i].Address << endl;
            cout << "Account number: " << accounts[i].AccountNum << endl;
            cout << "Password: " << accounts[i].Pass << endl;
            cout << "Deposit: " << accounts[i].deposit << " Euro" << endl;
            cout << "----------------------------------" << endl;
        }
    }
}

void BankSystem::searchByName() {
    if (accountCount <= 0) {
        cout << "No accounts available to search.\n";
        return;
    }

    string firstName, lastName;
    cout << "Enter First name: ";
    cin >> firstName;
    cout << "Enter Last name: ";
    cin >> lastName;

    bool accountFound = false;

    for (int i = 0; i < accountCount; ++i) {
        if (strcmp(accounts[i].Name, firstName.c_str()) == 0 && strcmp(accounts[i].LName, lastName.c_str()) == 0) {
            accountFound = true;
            cout << "Account details for " << firstName << " " << lastName << ":\n";
            cout << "Name: " << accounts[i].Name << endl;
            cout << "Last name: " << accounts[i].LName << endl;
            cout << "Phone number: " << accounts[i].PhoneNum << endl;
            cout << "City: " << accounts[i].City << endl;
            cout << "Address: " << accounts[i].Address << endl;
            cout << "Account number: " << accounts[i].AccountNum << endl;
            cout << "Password: " << accounts[i].Pass << endl;
            cout << "Deposit: " << accounts[i].deposit << " Euro" << endl;
            cout << "------------------------------------------" << endl;
        }
    }

    if (!accountFound) {
        cout << "No accounts found for the provided names.\n";
    }
}

void BankSystem::listAccountsByDeposit() {
    if (accountCount <= 0) {
        cout << "No accounts available to list.\n";
        return;
    }

    int minDeposit;
    cout << "Enter the minimum deposit: ";
    cin >> minDeposit;

    for (int i = 0; i < accountCount; ++i) {
        if (accounts[i].deposit >= minDeposit) {
            cout << "Name: " << accounts[i].Name << endl;
            cout << "Last name: " << accounts[i].LName << endl;
            cout << "Phone number: " << accounts[i].PhoneNum << endl;
            cout << "City: " << accounts[i].City << endl;
            cout << "Address: " << accounts[i].Address << endl;
            cout << "Account number: " << accounts[i].AccountNum << endl;
            cout << "Password: " << accounts[i].Pass << endl;
            cout << "Deposit: " << accounts[i].deposit << " Euro" << endl;
            cout << "-------------------------------------------\n" << endl;
        }
    }
}

void BankSystem::drawFromAccount() {
    if (accountCount <= 0) {
        cout << "No accounts available to draw from.\n";
        return;
    }

    int accountNumber, password, amount;
    cout << "Enter account details to draw from the account:\n";
    cout << "Account number: ";
    cin >> accountNumber;
    cout << "Password: ";
    cin >> password;

    for (int i = 0; i < accountCount; ++i) {
        if (accounts[i].AccountNum == accountNumber && accounts[i].Pass == password) {
            cout << accounts[i].Name << " " << accounts[i].LName << endl;
            cout << "Enter the amount you want to draw: ";
            cin >> amount;

            if (amount >= 0 && amount <= 200000) {
                if (accounts[i].deposit >= amount) {
                    accounts[i].deposit -= amount;
                    cout << "Your Deposit is: " << accounts[i].deposit << " Euro" << endl;
                } else {
                    cout << "Impossible!\nYour Deposit is less than the amount you want!\n";
                }
            } else {
                cout << "Invalid amount. You can draw between 0-200,000 Euro.\n";
            }
            return;
        }
    }

    cout << "Account not found or incorrect password. Please check the provided account number and password.\n";
}

void BankSystem::transferAmount() {
    if (accountCount <= 1) {
        cout << "Not enough accounts available to transfer.\n";
        return;
    }

    int sourceAccountNumber, sourcePassword, destinationAccountNumber, amount;
    cout << "Enter details for fund transfer:\n";
    cout << "Source account number: ";
    cin >> sourceAccountNumber;
    cout << "Source account password: ";
    cin >> sourcePassword;

    int sourceIndex = -1;
    for (int i = 0; i < accountCount; ++i) {
        if (accounts[i].AccountNum == sourceAccountNumber && accounts[i].Pass == sourcePassword) {
            sourceIndex = i;
            break;
        }
    }

    if (sourceIndex != -1) {
        cout << "Enter destination account number: ";
        cin >> destinationAccountNumber;

        int destinationIndex = -1;
        for (int i = 0; i < accountCount; ++i) {
            if (i != sourceIndex && accounts[i].AccountNum == destinationAccountNumber) {
                destinationIndex = i;
                break;
            }
        }

        if (destinationIndex != -1) {
            cout << "Enter the amount you want to transfer: ";
            cin >> amount;

            if (amount > 0 && amount <= accounts[sourceIndex].deposit) {
                accounts[sourceIndex].deposit -= amount;
                accounts[destinationIndex].deposit += amount;
                cout << "Transfer successful!\n";
                cout << "New deposit for source account (" << accounts[sourceIndex].AccountNum << "): " << accounts[sourceIndex].deposit << " Euro\n";
            } else {
                cout << "Invalid amount or insufficient balance in the source account.\n";
            }
        } else {
            cout << "Destination account not found.\n";
        }
    } else {
        cout << "Source account not found or incorrect password.\n";
    }
}

void BankSystem::seeAccount() {
    if (accountCount <= 0) {
        cout << "No accounts available to display.\n";
        return;
    }

    int accountNumber, password;
    cout << "Enter account details to view the account:\n";
    cout << "Account number: ";
    cin >> accountNumber;
    cout << "Password: ";
    cin >> password;

    for (int i = 0; i < accountCount; ++i) {
        if (accounts[i].AccountNum == accountNumber && accounts[i].Pass == password) {
            cin.ignore();
            cout << "Name: " << accounts[i].Name << endl;
            cout << "Last name: " << accounts[i].LName << endl;
            cout << "Phone number: " << accounts[i].PhoneNum << endl;
            cout << "City: " << accounts[i].City << endl;
            cout << "Address: " << accounts[i].Address << endl;
            cout << "Account number: " << accounts[i].AccountNum << endl;
            cout << "Password: " << accounts[i].Pass << endl;
            cout << "Deposit: " << accounts[i].deposit << " Euro\n";
            cout << "----------------------------------\n";
            return;
        }
    }

    cout << "Account not found or incorrect password.\n Please check the provided account number and password.\n";
}

void BankSystem::runLottery() {
    if (accountCount > 4) {
        int winner1 = random(1, accountCount);
        int winner2 = random(1, accountCount);
        int winner3 = random(1, accountCount);

        cout << "500,000 Euro goes to:\n1. " << accounts[winner1].Name << " " << accounts[winner1].LName << endl;
        cout << "200,000 Euro goes to:\n2. " << accounts[winner2].Name << " " << accounts[winner2].LName << endl;
        cout << "200,000 Euro goes to:\n3. " << accounts[winner3].Name << " " << accounts[winner3].LName << endl;
    } else {
        cout << "Not enough accounts for the lottery!\n";
    }
}

void BankSystem::handleInvalidChoice() {
    cout << "Invalid choice. Choose between 1-12!\n";
}

void BankSystem::clearScreen() {
#ifdef _WIN32
    // For Windows
    system("cls");
#else
    // For UNIX-like systems
    system("clear");
#endif
}

void BankSystem::waitForEnter() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void BankSystem::run() {
    FileHandler::loadDataFromFile(accounts, accountCount);
    
    int choice;
    clearScreen();

    do {
      clearScreen();
      displayMenu();
      cin >> choice;
      cin.ignore();

      switch (choice) {
          case 1:
              addAccount();
              break;
          case 2:
              removeAccount();
              break;
          case 3:
              editAccount();
              break;
          case 4:
              changePassword();
              break;
          case 5:
              showAllAccounts();
              break;
          case 6:
              searchByName();
              break;
          case 7:
              listAccountsByDeposit();
              break;
          case 8:
              drawFromAccount();
              break;
          case 9:
              transferAmount();
              break;
          case 10:
              seeAccount();
              break;
          case 11:
              runLottery();
              break;
          case 12:
              FileHandler::saveDataToFile(accounts, accountCount);
              exit(0);
          default:
              handleInvalidChoice();
      }
    waitForEnter();
  } while (choice != 12);
}

int random(int low, int high) {
    // Initialize a random engine using a high-resolution clock
    std::default_random_engine generator(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    // Define a uniform distribution for generating integers in the specified range
    std::uniform_int_distribution<int> distribution(low, high);
    // Use the generator and distribution to obtain a random number
    return static_cast<int>(distribution(generator));
}
