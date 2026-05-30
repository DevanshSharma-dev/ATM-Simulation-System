# ATM-Simulation-System

A comprehensive, console-based **ATM Simulation System** developed in C++ utilizing core Object-Oriented Programming (OOP) concepts.

# Features
 **User Authentication:** Secure secure access validate through Account Number and a 4-digit PIN.
 **Balance Inquiry:** Real-time check of current account balance.
 **Cash Deposit & Withdrawal:** Fully functional money transaction with strict error handling (e.g., overdraft limits, negative numbers).
 **Transaction History:** Generates a mini-statement listing all actions performed during the session.
 **Multi-Account Support:** Built-in repository handling multiple user accounts independently.

# OOP Concepts Demonstrated
**Encapsulation:** Hidden properties like `balance`, `pin`, and `transactionHistory` inside the `Account` class, exposed strictly via public member functions.
**Data Abstraction:** Simplifies real-world entity operations where users interact via choices without internal logic overhead.
**Classes and Objects:** Clear logical models separating Account properties from ATM hardware capabilities.

# How to Run
1. Compile using any standard C++ compiler (e.g., g++):
```bash
   g++ atm_system.cpp -o atm_system
