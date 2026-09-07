//============================================================================
// Name        : Question3.cpp
// Author      : Tanaya Gughane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <string>
using namespace std;

class Patient
{
private:
    int patientId;
    string name;
    int age;
    const int registrationFee;

public:

    // Default Constructor
    Patient()
        : patientId(0), name("Unknown"), age(0), registrationFee(500)
    {
        cout << "Default Constructor called" << endl;
    }

    // Parameterized Constructor
    Patient(int id, string n, int a)
        : patientId(id), name(n), age(a), registrationFee(500)
    {
        cout << "Parameterized Constructor called" << endl;
    }

    // Parameterized Constructor with registration fee
    Patient(int id, string n, int a, int fee)
        : patientId(id), name(n), age(a), registrationFee(fee)
    {
        cout << "Parameterized Constructor with fee called" << endl;
    }

    // Display Patient Details
    void display() const
    {
        cout << "\nPatient ID       : " << patientId << endl;
        cout << "Patient Name     : " << name << endl;
        cout << "Age              : " << age << endl;
        cout << "Registration Fee : Rs. " << registrationFee << endl;
    }

    // Destructor
    ~Patient()
    {
        cout << "Destructor called for Patient ID: "
             << patientId << endl;
    }
};


int main3()
{
    cout << "===== HOSPITAL PATIENT REGISTRY =====" << endl;

    // Default constructor
    Patient p1;

    // Parameterized constructor
    Patient p2(101, "Tanaya", 22);

    // Parameterized constructor with fee
    Patient p3(102, "Apurva", 25, 1000);

    cout << "\n===== PATIENT DETAILS =====" << endl;

    p1.display();
    p2.display();
    p3.display();


    // Dynamic Array of Objects
    int n;

    cout << "\nEnter number of patients: ";
    cin >> n;

    Patient* patients = new Patient[n];

    cout << "\nDynamic Patient Array Created." << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "\nPatient " << i + 1 << ":" << endl;
        patients[i].display();
    }

    // Release dynamic memory
    delete[] patients;

    cout << "\nDynamic Patient Array Deleted." << endl;

    return 0;
}

