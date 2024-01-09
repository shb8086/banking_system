# Banking System

A simple console-based banking system implemented in C++.

## Table of Contents
- [Description](#description)
- [Features](#features)
- [Usage](#usage)
- [File Management](#file-management)

## Description

This C++ program is a basic banking system that allows users to perform various actions such as adding new accounts, removing accounts, editing accounts, changing passwords, and more.

## Features

- Add new account
- Remove account
- Edit account
- Change password
- Show all accounts
- Search based on first and last name
- List accounts with more than a given deposit
- Draw from account
- Transfer funds between accounts
- View account details
- Conduct a lottery

## File Management

The program supports file management for persistent data storage. Account information is saved to and loaded from a CSV file (`bank_data.csv`). This allows the system to retain data across program runs.

- `FileHandler.h` and `FileHandler.cpp` contain functions for saving and loading data to/from the CSV file.

## Usage

To use the program, follow these steps:

1. Clone the repository: `git clone https://github.com/yourusername/banking-system.git`
2. Compile the code: `g++ Main.cpp BankSystem.cpp FileHandler.cpp -o banking_system`
3. Run the program: `./banking_system`

Follow the on-screen instructions to interact with the banking system.