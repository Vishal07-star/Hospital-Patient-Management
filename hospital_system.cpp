#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

// Base Class: Patient
class Patient {
protected:
    int patientID;
    char name[50];
    int age;
    char gender[10];
    char disease[100];

public:
    Patient() {
        patientID = 0;
        strcpy(name, "");
        age = 0;
        strcpy(gender, "");
        strcpy(disease, "");
    }

    virtual void inputData() {
        cout << "\n--- Enter Patient Information ---" << endl;
        cout << "Enter Patient ID: ";
        cin >> patientID;
        cin.ignore();
        
        cout << "Enter Name: ";
        cin.getline(name, 50);
        
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        
        cout << "Enter Gender (M/F/Other): ";
        cin.getline(gender, 10);
        
        cout << "Enter Disease: ";
        cin.getline(disease, 100);
    }

    virtual void displayData() const {
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Disease: " << disease << endl;
    }

    virtual float calculateBill() = 0;
    virtual ~Patient() {}
    
    int getPatientID() const { return patientID; }
};

// Class for Bill with Operator Overloading
class Bill {
private:
    float amount;

public:
    Bill(float amt = 0) : amount(amt) {}

    Bill operator + (const Bill& b) {
        return Bill(amount + b.amount);
    }

    Bill& operator += (const Bill& b) {
        amount += b.amount;
        return *this;
    }

    float getAmount() const { return amount; }

    void displayBill() const {
        cout << "Total Bill: Rs. " << fixed << setprecision(2) << amount << endl;
    }
};

// Derived Class: Inpatient
class Inpatient : public Patient {
private:
    int roomNumber;
    int daysAdmitted;
    float roomChargesPerDay;
    float medicineCharges;
    float surgeryCharges;

public:
    Inpatient() : Patient() {
        roomNumber = 0;
        daysAdmitted = 0;
        roomChargesPerDay = 0;
        medicineCharges = 0;
        surgeryCharges = 0;
    }

    void inputData() override {
        Patient::inputData();
        
        cout << "--- Inpatient Specific Information ---" << endl;
        cout << "Enter Room Number: ";
        cin >> roomNumber;
        
        cout << "Enter Days Admitted: ";
        cin >> daysAdmitted;
        
        cout << "Enter Room Charges Per Day: ";
        cin >> roomChargesPerDay;
        
        cout << "Enter Medicine Charges: ";
        cin >> medicineCharges;
        
        cout << "Enter Surgery Charges: ";
        cin >> surgeryCharges;
    }

    void displayData() const override {
        cout << "\n========== INPATIENT DETAILS ==========" << endl;
        Patient::displayData();
        cout << "Room Number: " << roomNumber << endl;
        cout << "Days Admitted: " << daysAdmitted << endl;
        cout << "Room Charges (Per Day): Rs. " << roomChargesPerDay << endl;
        cout << "Medicine Charges: Rs. " << medicineCharges << endl;
        cout << "Surgery Charges: Rs. " << surgeryCharges << endl;
    }

    float calculateBill() override {
        float totalBill = (daysAdmitted * roomChargesPerDay) 
                         + medicineCharges 
                         + surgeryCharges;
        return totalBill;
    }

    void saveToFile() {
        ofstream file("inpatients.dat", ios::binary | ios::app);
        if (file.is_open()) {
            file.write((char*)this, sizeof(*this));
            file.close();
            cout << "\n✓ Inpatient record saved successfully!" << endl;
        } else {
            cout << "\n✗ Error opening file!" << endl;
        }
    }
};

// Derived Class: Outpatient
class Outpatient : public Patient {
private:
    int tokenNumber;
    float consultationFee;
    float testCharges;
    float medicineCharges;

public:
    Outpatient() : Patient() {
        tokenNumber = 0;
        consultationFee = 0;
        testCharges = 0;
        medicineCharges = 0;
    }

    void inputData() override {
        Patient::inputData();
        
        cout << "--- Outpatient Specific Information ---" << endl;
        cout << "Enter Token Number: ";
        cin >> tokenNumber;
        
        cout << "Enter Consultation Fee: ";
        cin >> consultationFee;
        
        cout << "Enter Test Charges: ";
        cin >> testCharges;
        
        cout << "Enter Medicine Charges: ";
        cin >> medicineCharges;
    }

    void displayData() const override {
        cout << "\n========== OUTPATIENT DETAILS ==========" << endl;
        Patient::displayData();
        cout << "Token Number: " << tokenNumber << endl;
        cout << "Consultation Fee: Rs. " << consultationFee << endl;
        cout << "Test Charges: Rs. " << testCharges << endl;
        cout << "Medicine Charges: Rs. " << medicineCharges << endl;
    }

    float calculateBill() override {
        float totalBill = consultationFee 
                         + testCharges 
                         + medicineCharges;
        return totalBill;
    }

    void saveToFile() {
        ofstream file("outpatients.dat", ios::binary | ios::app);
        if (file.is_open()) {
            file.write((char*)this, sizeof(*this));
            file.close();
            cout << "\n✓ Outpatient record saved successfully!" << endl;
        } else {
            cout << "\n✗ Error opening file!" << endl;
        }
    }
};

// Function Prototypes
void displayAllInpatients();
void displayAllOutpatients();
void searchPatientByID(int id);
void calculateTotalRevenue();

// Implementation Functions
void displayAllInpatients() {
    cout << "\n========== ALL INPATIENT RECORDS ==========" << endl;
    ifstream file("inpatients.dat", ios::binary);
    
    if (!file.is_open()) {
        cout << "No inpatient records found!" << endl;
        return;
    }
    
    Inpatient inp;
    int count = 0;
    
    while (file.read((char*)&inp, sizeof(inp))) {
        inp.displayData();
        Bill bill(inp.calculateBill());
        bill.displayBill();
        cout << "==========================================" << endl;
        count++;
    }
    
    file.close();
    if (count == 0) cout << "No records found!" << endl;
    else cout << "Total Inpatients: " << count << endl;
}

void displayAllOutpatients() {
    cout << "\n========== ALL OUTPATIENT RECORDS ==========" << endl;
    ifstream file("outpatients.dat", ios::binary);
    
    if (!file.is_open()) {
        cout << "No outpatient records found!" << endl;
        return;
    }
    
    Outpatient outp;
    int count = 0;
    
    while (file.read((char*)&outp, sizeof(outp))) {
        outp.displayData();
        Bill bill(outp.calculateBill());
        bill.displayBill();
        cout << "===========================================" << endl;
        count++;
    }
    
    file.close();
    if (count == 0) cout << "No records found!" << endl;
    else cout << "Total Outpatients: " << count << endl;
}

void searchPatientByID(int id) {
    cout << "\n========== SEARCHING INPATIENTS ==========" << endl;
    ifstream inFile("inpatients.dat", ios::binary);
    Inpatient inp;
    bool found = false;
    
    while (inFile.read((char*)&inp, sizeof(inp))) {
        if (inp.getPatientID() == id) {
            inp.displayData();
            Bill bill(inp.calculateBill());
            bill.displayBill();
            found = true;
            break;
        }
    }
    inFile.close();
    
    if (!found) {
        cout << "\n========== SEARCHING OUTPATIENTS ==========" << endl;
        ifstream outFile("outpatients.dat", ios::binary);
        Outpatient outp;
        
        while (outFile.read((char*)&outp, sizeof(outp))) {
            if (outp.getPatientID() == id) {
                outp.displayData();
                Bill bill(outp.calculateBill());
                bill.displayBill();
                found = true;
                break;
            }
        }
        outFile.close();
    }
    
    if (!found) cout << "\n✗ Patient with ID " << id << " not found!" << endl;
}

void calculateTotalRevenue() {
    Bill totalRevenue(0);
    
    // Calculate from inpatients
    cout << "\n========== CALCULATING INPATIENT REVENUE ==========" << endl;
    ifstream inFile("inpatients.dat", ios::binary);
    Inpatient inp;
    float inpatientTotal = 0;
    
    while (inFile.read((char*)&inp, sizeof(inp))) {
        Bill patientBill(inp.calculateBill());
        totalRevenue += patientBill;
        inpatientTotal += patientBill.getAmount();
    }
    inFile.close();
    cout << "Inpatient Revenue: Rs. " << fixed << setprecision(2) << inpatientTotal << endl;
    
    // Calculate from outpatients
    cout << "\n========== CALCULATING OUTPATIENT REVENUE ==========" << endl;
    ifstream outFile("outpatients.dat", ios::binary);
    Outpatient outp;
    float outpatientTotal = 0;
    
    while (outFile.read((char*)&outp, sizeof(outp))) {
        Bill patientBill(outp.calculateBill());
        totalRevenue += patientBill;
        outpatientTotal += patientBill.getAmount();
    }
    outFile.close();
    cout << "Outpatient Revenue: Rs. " << fixed << setprecision(2) << outpatientTotal << endl;
    
    // Display total revenue
    cout << "\n╔════════════════════════════════════════════╗" << endl;
    cout << "║    HOSPITAL TOTAL REVENUE REPORT           ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;
    cout << "Inpatient Revenue: Rs. " << fixed << setprecision(2) << inpatientTotal << endl;
    cout << "Outpatient Revenue: Rs. " << fixed << setprecision(2) << outpatientTotal << endl;
    cout << "═══════════════════════════════════════════════" << endl;
    totalRevenue.displayBill();
    cout << "═══════════════════════════════════════════════" << endl;
}

// Main Function
int main() {
    int choice;
    
    cout << "\n╔════════════════════════════════════════════╗" << endl;
    cout << "║   HOSPITAL PATIENT MANAGEMENT SYSTEM       ║" << endl;
    cout << "║   Using OOP Concepts in C++                ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;
    
    do {
        cout << "\n========== MAIN MENU ==========" << endl;
        cout << "1. Add New Inpatient" << endl;
        cout << "2. Add New Outpatient" << endl;
        cout << "3. Display All Inpatients" << endl;
        cout << "4. Display All Outpatients" << endl;
        cout << "5. Search Patient by ID" << endl;
        cout << "6. Calculate Total Hospital Revenue" << endl;
        cout << "7. Exit" << endl;
        cout << "================================" << endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                Inpatient inp;
                inp.inputData();
                inp.saveToFile();
                break;
            }
            case 2: {
                Outpatient outp;
                outp.inputData();
                outp.saveToFile();
                break;
            }
            case 3: {
                displayAllInpatients();
                break;
            }
            case 4: {
                displayAllOutpatients();
                break;
            }
            case 5: {
                int searchID;
                cout << "Enter Patient ID to search: ";
                cin >> searchID;
                searchPatientByID(searchID);
                break;
            }
            case 6: {
                calculateTotalRevenue();
                break;
            }
            case 7: {
                cout << "\n╔════════════════════════════════════════════╗" << endl;
                cout << "║  Thank you for using Hospital Management   ║" << endl;
                cout << "║            System. Goodbye!                 ║" << endl;
                cout << "╚════════════════════════════════════════════╝" << endl;
                break;
            }
            default: {
                cout << "\n✗ Invalid choice! Please enter a number between 1 and 7." << endl;
            }
        }
    } while (choice != 7);
    
    return 0;
}
