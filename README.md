# Hospital Patient Management System

A comprehensive C++ project demonstrating Object-Oriented Programming (OOP) concepts through a practical hospital management application.

## 📋 Project Overview

This Hospital Patient Management System automates patient record management and billing operations with a focus on implementing core OOP principles. The system handles both inpatient and outpatient data with persistent storage using binary file handling.

## ✨ Key Features

- **Patient Registration & Management**
  - Separate handling for Inpatient and Outpatient records
  - Comprehensive patient information storage
  
- **Automated Billing System**
  - Operator overloading for intuitive bill calculations
  - Different billing formulas for inpatients and outpatients
  
- **Persistent Data Storage**
  - Binary file handling for patient records
  - Save and retrieve operations
  
- **Advanced Search Functionality**
  - Quick patient lookup by ID
  - Search across both inpatient and outpatient databases
  
- **Revenue Reporting**
  - Calculate total hospital revenue
  - Separate reporting for inpatient and outpatient earnings

## 🎓 OOP Concepts Implemented

### 1. **Inheritance**
- Base class: `Patient`
- Derived classes: `Inpatient`, `Outpatient`
- Code reusability through hierarchical structure

### 2. **Encapsulation**
- Private/protected data members
- Public methods for controlled access
- Data hiding and abstraction

### 3. **Polymorphism**
- Virtual functions for runtime polymorphism
- Different implementations of `calculateBill()` in derived classes
- Base class pointer usage for polymorphic behavior

### 4. **Operator Overloading**
- Overloaded `+` operator for bill addition
- Overloaded `+=` operator for cumulative billing
- Makes code intuitive: `totalBill = bill1 + bill2 + bill3`

### 5. **File Handling**
- Binary file operations (read/write)
- Persistent data storage across program runs
- Search and retrieve specific records

## 📁 Class Structure

```
Patient (Base Class)
├── Attributes: patientID, name, age, gender, disease
├── Methods: inputData(), displayData(), calculateBill() [pure virtual]
│
├── Inpatient (Derived Class)
│   ├── Additional Attributes: roomNumber, daysAdmitted, roomChargesPerDay, medicineCharges, surgeryCharges
│   ├── Formula: Bill = (Days × Room Charges) + Medicine + Surgery
│   └── File: inpatients.dat
│
└── Outpatient (Derived Class)
    ├── Additional Attributes: tokenNumber, consultationFee, testCharges, medicineCharges
    ├── Formula: Bill = Consultation Fee + Test Charges + Medicine
    └── File: outpatients.dat

Bill (Utility Class)
├── Operator Overloading: +, +=
└── Methods: getAmount(), displayBill()
```

## 🚀 Getting Started

### Prerequisites
- C++ compiler (g++, MinGW, or Visual Studio)
- C++11 or later
- Any operating system (Windows, Linux, macOS)

### Compilation

```bash
# Using g++ (Linux/Mac)
g++ hospital_system.cpp -o hospital

# Using MinGW (Windows)
g++ hospital_system.cpp -o hospital.exe
```

### Execution

```bash
# Linux/Mac
./hospital

# Windows
hospital.exe
```

## 📱 Menu Options

```
========== MAIN MENU ==========
1. Add New Inpatient
2. Add New Outpatient
3. Display All Inpatients
4. Display All Outpatients
5. Search Patient by ID
6. Calculate Total Hospital Revenue
7. Exit
================================
```

## 💾 Data Files

- **inpatients.dat** - Binary file storing all inpatient records
- **outpatients.dat** - Binary file storing all outpatient records

## 📊 Sample Usage

### Adding an Inpatient
```
Option: 1
Patient ID: 101
Name: John Doe
Age: 45
Gender: M
Disease: Diabetes
Room Number: 201
Days Admitted: 5
Room Charges Per Day: 1000
Medicine Charges: 5000
Surgery Charges: 10000
```

### Calculating Total Revenue
```
Option: 6
→ Displays comprehensive revenue report
→ Shows inpatient and outpatient revenues separately
→ Displays total hospital revenue
```

## 🔧 Technical Specifications

- **Lines of Code**: ~418 lines
- **Main Classes**: 3 (Patient, Inpatient, Outpatient)
- **Inheritance Hierarchy**: Single level
- **File Handling**: Binary I/O operations
- **Memory Management**: Dynamic object creation and storage

## 📈 Enhancement Opportunities

### Phase 1: Immediate Enhancements
- Input validation and error handling
- Edit/update patient records
- Delete patient functionality
- Generate printable receipts

### Phase 2: Short-term Goals
- Database integration (SQLite/MySQL)
- Appointment scheduling module
- Doctor management system
- Basic GUI interface (Qt, wxWidgets)

### Phase 3: Medium-term Goals
- Multi-user support with authentication
- Network/web-based access
- Pharmacy integration
- SMS/Email notifications

### Phase 4: Long-term Vision
- Cloud storage and backup
- Mobile application (Android/iOS)
- IoT device integration
- AI-based analytics and predictions
- Electronic Health Records (EHR) compliance

## 🏥 Real-World Applications

This system can be adapted for:
- Small clinics and nursing homes
- Diagnostic centers
- Dental clinics
- Veterinary hospitals
- Physiotherapy centers
- Multi-specialty hospitals

## 📝 Code Quality

- **Modular Design**: Each class has a single responsibility
- **Maintainable**: Clean code structure for easy updates
- **Scalable**: Can be extended with new features
- **Well-commented**: Clear explanations of logic
- **Type-safe**: Proper use of C++ type system
- **Memory-efficient**: Binary storage for optimization

## 🎯 Learning Outcomes

This project demonstrates:
- ✅ Practical OOP implementation in real-world scenarios
- ✅ Inheritance and hierarchical design
- ✅ Polymorphism through virtual functions
- ✅ Operator overloading for code readability
- ✅ File I/O operations in C++
- ✅ Software design principles
- ✅ Data persistence techniques
- ✅ Healthcare domain knowledge

## 📚 References

1. **C++ OOP Concepts**
   - Inheritance and Polymorphism
   - Operator Overloading
   - File Handling (fstream)
   - Virtual Functions

2. **Hospital Management Systems**
   - Patient record management
   - Billing systems
   - Healthcare software design

3. **Best Practices**
   - Code organization and modularity
   - Error handling
   - Data validation
   - Security considerations



## 👨‍💼 Author

Developed as a Mini Project for Object-Oriented Programming Course

## 📞 Support

For issues, questions, or suggestions:
- Create an Issue on GitHub
- Submit a Pull Request with improvements
- Contact through GitHub Discussions

## 🙏 Acknowledgments

- Inspired by real-world hospital management systems
- Based on OOP principles and design patterns
- Educational project for computer science students

---

**Happy Coding! 💻**

*This project demonstrates how fundamental OOP concepts can be applied to solve real-world problems in the healthcare industry.*
