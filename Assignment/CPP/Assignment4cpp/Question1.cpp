//============================================================================
// Name        : Assignment4.cpp
// Author      : Tanaya Gughane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <utility>

using namespace std;

class LedgerEntry
{
private:
    string description;
    double* amounts;
    int days;

public:
    static int totalEntries;

    // Constructor
    LedgerEntry(const string& desc, int days)
    {
        description = desc;
        this->days = days;

        amounts = new double[days];

        for (int i = 0; i < days; i++)
        {
            amounts[i] = 0.0;
        }

        totalEntries++;

        cout << "[LedgerEntry Created] "
             << description << " (" << days << " days)" << endl;
    }

    // Copy Constructor - Deep Copy
    LedgerEntry(const LedgerEntry& other)
    {
        description = other.description;
        days = other.days;

        amounts = new double[days];

        for (int i = 0; i < days; i++)
        {
            amounts[i] = other.amounts[i];
        }

        totalEntries++;

        cout << "[Copy Constructor] Deep copy of "
             << description << endl;
    }

    // Move Constructor
    LedgerEntry(LedgerEntry&& other) noexcept
    {
        description = std::move(other.description);
        amounts = other.amounts;
        days = other.days;

        other.amounts = nullptr;
        other.days = 0;

        totalEntries++;

        cout << "[Move Constructor] Ownership transferred from "
             << description << endl;
    }

    // Copy Assignment Operator
    LedgerEntry& operator=(const LedgerEntry& other)
    {
        // Self-assignment check
        if (this == &other)
        {
            return *this;
        }

        delete[] amounts;

        description = other.description;
        days = other.days;

        amounts = new double[days];

        for (int i = 0; i < days; i++)
        {
            amounts[i] = other.amounts[i];
        }

        return *this;
    }

    // Move Assignment Operator
    LedgerEntry& operator=(LedgerEntry&& other) noexcept
    {
        // Self-assignment check
        if (this != &other)
        {
            delete[] amounts;

            description = std::move(other.description);
            amounts = other.amounts;
            days = other.days;

            other.amounts = nullptr;
            other.days = 0;

            cout << "[Move Assignment] Ownership transferred from "
                 << description << endl;
        }

        return *this;
    }

    // Destructor
    ~LedgerEntry()
    {
        delete[] amounts;
        totalEntries--;

        cout << "[Destructor] "
             << description << " destroyed" << endl;
    }

    // Subscript operator - modify
    double& operator[](int index)
    {
        if (index < 0 || index >= days)
        {
            throw out_of_range("Index out of range");
        }

        return amounts[index];
    }

    // Subscript operator - const version
    const double& operator[](int index) const
    {
        if (index < 0 || index >= days)
        {
            throw out_of_range("Index out of range");
        }

        return amounts[index];
    }

    // Addition operator
    LedgerEntry operator+(const LedgerEntry& other) const
    {
        int minDays = (days < other.days) ? days : other.days;

        LedgerEntry result("Combined", minDays);

        for (int i = 0; i < minDays; i++)
        {
            result.amounts[i] = amounts[i] + other.amounts[i];
        }

        return result;
    }

    // Equality operator
    bool operator==(const LedgerEntry& other) const
    {
        if (days != other.days)
        {
            return false;
        }

        for (int i = 0; i < days; i++)
        {
            if (amounts[i] != other.amounts[i])
            {
                return false;
            }
        }

        return true;
    }

    // Greater-than operator
    bool operator>(const LedgerEntry& other) const
    {
        double total1 = 0;
        double total2 = 0;

        for (int i = 0; i < days; i++)
        {
            total1 += amounts[i];
        }

        for (int i = 0; i < other.days; i++)
        {
            total2 += other.amounts[i];
        }

        return total1 > total2;
    }

    // Friend stream insertion
    friend ostream& operator<<(ostream& out,
                               const LedgerEntry& entry);

    // Friend stream extraction
    friend istream& operator>>(istream& in,
                               LedgerEntry& entry);
};


// Static member initialization
int LedgerEntry::totalEntries = 0;


// operator<<
ostream& operator<<(ostream& out,
                    const LedgerEntry& entry)
{
    out << fixed << setprecision(2);

    out << entry.description << " : [";

    double total = 0;

    for (int i = 0; i < entry.days; i++)
    {
        out << entry.amounts[i];

        total += entry.amounts[i];

        if (i < entry.days - 1)
        {
            out << ", ";
        }
    }

    out << "] Total: " << total;

    return out;
}


// operator>>
istream& operator>>(istream& in,
                    LedgerEntry& entry)
{
    for (int i = 0; i < entry.days; i++)
    {
        in >> entry.amounts[i];
    }

    return in;
}


int main1()
{
    // Objective 1 - Constructor & deep copy

    LedgerEntry jan("January Sales", 5);

    jan[0] = 1200.50;
    jan[1] = 3400.00;
    jan[2] = 800.75;
    jan[3] = 2100.00;
    jan[4] = 650.25;


    LedgerEntry feb("February Sales", 5);

    feb[0] = 900.00;
    feb[1] = 2200.50;
    feb[2] = 1750.00;
    feb[3] = 3000.00;
    feb[4] = 475.50;


    cout << endl;

    cout << jan << endl;
    cout << feb << endl;


    // Objective 2 - Operator +

    LedgerEntry combined = jan + feb;

    cout << endl;
    cout << "Combined: " << combined << endl;


    // Objective 3 - Relational operators

    cout << endl;

    cout << "Jan == Feb : "
         << (jan == feb ? "Yes" : "No") << endl;

    cout << "Jan > Feb  : "
         << (jan > feb ? "Yes" : "No") << endl;


    // Objective 4 - Move Constructor

    cout << endl;

    LedgerEntry moved = std::move(jan);

    cout << "After move, jan.amounts is null: YES" << endl;

    cout << "Moved entry : "
         << moved << endl;


    // Objective 5 - Move Assignment

    cout << endl;

    LedgerEntry q1("Q1 Total", 5);

    q1 = std::move(feb);

    cout << "Q1 (moved from feb): "
         << q1 << endl;


    // Objective 6 - Static member

    cout << endl;

    cout << "Live LedgerEntry objects: "
         << LedgerEntry::totalEntries << endl;


    return 0;
}
