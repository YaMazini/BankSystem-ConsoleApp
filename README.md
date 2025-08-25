# BankSystem-ConsoleApp
A C++ console banking system to practice OOP and clean code principles. 🏦


# Bank System Console Application

A comprehensive C++ console-based banking system designed to demonstrate Object-Oriented Programming (OOP) principles, clean code architecture, and practical file-based data management. This project showcases a real-world banking system implementation with proper separation of concerns and layered architecture.

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Architecture](#architecture)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Security Features](#security-features)
- [Future Enhancements](#future-enhancements)
- [Contributing](#contributing)
- [License](#license)

## 🎯 Overview

This banking system serves multiple educational and practical purposes:
- **Educational**: Demonstrates OOP concepts, clean code principles, and separation of concerns
- **Practical**: Functions as a complete banking system with real-world features
- **Scalable**: Built with a layered architecture that allows easy extension and UI replacement

The project evolved from a functional programming approach to a full Object-Oriented design, showcasing the transformation process and benefits of OOP architecture.

## ✨ Features

### 🔐 Authentication System
- Secure user login with username and password validation
- User session management with real-time display
- Login register tracking with timestamps
- Role-based access control

### 👥 Client Management (CRUD Operations)
- **Create**: Add new clients to the system
- **Read**: View client information and search functionality
- **Update**: Modify existing client details
- **Delete**: Remove clients from the system
- Client information lookup and validation

### 💰 Transaction Management
- **Withdraw**: Process money withdrawals with balance validation
- **Deposit**: Handle money deposits
- **Total Balances**: Calculate and display total system balances
- **Transfer**: Money transfer between accounts
- **Transfer Log**: Comprehensive transaction history with source/destination tracking

### 🌍 Currency Exchange System
- **Currency List**: Display available currencies
- **Currency Finder**: Search for specific currencies
- **Rate Management**: Update exchange rates
- **Currency Calculator**: Convert amounts between different currencies

### 👨‍💼 User Management
- **User CRUD Operations**: Complete user lifecycle management
- **User Search**: Find and display user information
- **Admin Protection**: Prevents deletion of admin user (Yahya Mazini)
- Role and permission management

### 📊 System Features
- **Real-time DateTime Display**: Shows current date and time
- **Login Register**: Tracks user login history
- **Session Management**: Maintains user session state
- **Secure Logout**: Proper session termination
- **Exit Screen**: Clean application shutdown

## 🏗️ Architecture

### Layered Architecture Design
The application follows a clean, three-tier architecture:

```
┌─────────────────────────────────┐
│        Presentation Layer       │
│         (UI Layer)              │
├─────────────────────────────────┤
│        Business Layer           │
│       (Logic Layer)             │
├─────────────────────────────────┤
│         Data Layer              │
│      (File Management)          │
└─────────────────────────────────┘
```

### Key Architectural Benefits
- **Separation of Concerns**: Each layer has distinct responsibilities
- **Maintainability**: Easy to modify and extend functionality
- **Testability**: Business logic separated from UI and data layers
- **Scalability**: Can easily replace console UI with GUI (WinForms/WPF)
- **Portability**: Same logic can be reused across different platforms

### Custom Libraries
The project utilizes custom-built libraries:
- `clsString`: String manipulation utilities
- `clsDate`: Date and time handling
- Additional utility classes for enhanced functionality

## 🚀 Getting Started

### Prerequisites
- C++ Compiler (GCC, MSVC, or Clang)
- Standard C++ libraries

### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/YaMazini/BankSystem-ConsoleApp.git
   cd BankSystem-ConsoleApp
   ```

2. **Compile the application**
   ```bash
   g++ *.cpp -o BankSystem
   ```

3. **Run the application**
   ```bash
   ./BankSystem
   ```

### Initial Setup
- The system will initialize with default data files
- Default admin credentials: 
  - Username: [Check Users.txt file]
  - Password: [Check Users.txt file - encrypted]

## 📖 Usage

### Main Menu Navigation
1. **Login**: Enter credentials to access the system
2. **Client Management**: Access CRUD operations for clients
3. **Transactions**: Perform financial operations
4. **Currency Exchange**: Manage currencies and conversions
5. **User Management**: Administer system users
6. **Login Register**: View access history
7. **Logout**: End current session

### Sample Workflow
```
1. Login with valid credentials
2. Navigate to Client Management
3. Create/Update client information
4. Perform transactions (deposit/withdraw/transfer)
5. View transaction history
6. Logout securely
```

## 📁 File Structure

The system uses file-based storage as a lightweight database solution:

```
📦 Data Files
├── 📄 Clients.txt          # Client information storage
├── 📄 Currencies.txt       # Currency data and exchange rates
├── 📄 LoginRegister.txt    # User login history
├── 📄 TransferLog.txt      # Transaction history and logs
└── 📄 Users.txt            # User credentials and roles
```

### File Responsibilities
- **Clients.txt**: Manages all client-related data and operations
- **Currencies.txt**: Handles currency information and exchange rates
- **LoginRegister.txt**: Tracks user access patterns and login history
- **TransferLog.txt**: Records all financial transactions with detailed logs
- **Users.txt**: Stores user credentials with encrypted passwords

## 🔒 Security Features

### Password Encryption
- Implements primitive password encryption for demonstration
- Shows practical approach to password security
- Can be extended with advanced encryption algorithms

### Access Control
- Role-based user management
- Admin user protection (prevents accidental deletion)
- Session-based authentication

### Data Integrity
- File-based validation and error handling
- Transaction logging for audit trails
- Consistent data state management

## 🔮 Future Enhancements

### Planned Improvements
- **GUI Implementation**: Migrate to Windows Forms or WPF
- **Database Integration**: Replace file system with SQL database
- **Advanced Security**: Implement stronger encryption algorithms
- **Web Interface**: Develop web-based banking portal
- **Mobile App**: Create mobile banking application
- **API Development**: Build RESTful API for third-party integration

### Technology Migration
- **C# Version**: Port entire system to C# with enhanced features
- **Cross-Platform**: Make compatible with Linux and macOS
- **Cloud Integration**: Add cloud storage and backup capabilities

## 🤝 Contributing

Contributions are welcome! The project is designed for easy extension:

### Guidelines
1. **Respect Architecture**: Maintain separation between data/logic/UI layers
2. **Follow OOP Principles**: Use proper encapsulation and inheritance
3. **Clean Code**: Maintain readable and well-documented code
4. **Testing**: Ensure new features don't break existing functionality

### Development Areas
- New transaction types
- Additional currency support
- Enhanced security features
- Performance optimizations
- UI/UX improvements

## 📝 Development Notes

### Evolution History
- **Phase 1**: Functional Programming implementation
- **Phase 2**: Migration to Object-Oriented design
- **Phase 3**: Implementation of layered architecture
- **Current**: Clean code with separation of concerns

### Learning Outcomes
This project demonstrates:
- **OOP Mastery**: Practical application of inheritance, polymorphism, encapsulation
- **Clean Architecture**: Proper layer separation and dependency management
- **File I/O Operations**: Comprehensive file handling in C++
- **Real-World Application**: Banking domain knowledge implementation
- **Code Evolution**: Transformation from procedural to object-oriented design

 📞 Support

For questions, suggestions, or contributions:
- **Repository**: https://github.com/YaMazini/BankSystem-ConsoleApp
- **Issues**: Use GitHub Issues for bug reports and feature requests
- **Discussions**: Use GitHub Discussions for general questions
- **Email**: yohananmazini@gmail.com

---

**Note**: This project serves as an educational tool and a foundation for more complex banking applications. It demonstrates the principles and patterns used in enterprise-level software development while maintaining simplicity for learning purposes. 
