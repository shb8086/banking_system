#include "FileHandler.h"

void FileHandler::saveDataToFile(const BankAccount accounts[], int accountCount) {
    std::ofstream outputFile("bank_data.csv");

    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing!\n";
        return;
    }

    for (int i = 0; i < accountCount; ++i) {
        outputFile << std::setw(20) << accounts[i].Name << ","
                   << std::setw(30) << accounts[i].LName << ","
                   << std::setw(30) << accounts[i].PhoneNum << ","
                   << std::setw(30) << accounts[i].City << ","
                   << std::setw(100) << accounts[i].Address << ","
                   << accounts[i].deposit << ","
                   << accounts[i].Pass << ","
                   << accounts[i].AccountNum << "\n";
    }

    outputFile.close();
}

void FileHandler::loadDataFromFile(BankAccount accounts[], int& accountCount) {
    std::ifstream inputFile("bank_data.csv");

    if (!inputFile.is_open()) {
        std::cout << "No existing data file found.\n";
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        BankAccount account;

        // Assuming the CSV file format: Name,Last Name,Phone,City,Address,Deposit,Password,AccountNum
        if (!(iss >> std::setw(20) >> account.Name
                  >> std::setw(30) >> account.LName
                  >> std::setw(30) >> account.PhoneNum
                  >> std::setw(30) >> account.City
                  >> std::setw(100) >> account.Address
                  >> account.deposit
                  >> account.Pass
                  >> account.AccountNum)) {
            std::cerr << "Error reading data from file.\n";
            break;
        }

        // Add the loaded account to the array
        accounts[accountCount++] = account;
    }

    inputFile.close();
}
