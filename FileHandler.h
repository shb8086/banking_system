#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "BankSystem.h"  // Include the BankSystem header for BankAccount structure

class FileHandler {
public:
    static void saveDataToFile(const BankAccount accounts[], int accountCount);
    static void loadDataFromFile(BankAccount accounts[], int& accountCount);
};

#endif // FILE_HANDLER_H
