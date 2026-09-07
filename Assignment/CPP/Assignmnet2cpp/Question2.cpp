//============================================================================
// Name        : Question2.cpp
// Author      : Tanaya Gughane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

// Function 1: Integer quantity
double reorderCost(int qty, double unitPrice)
{
    return qty * unitPrice;
}

// Function 2: Double quantity
double reorderCost(double qty, double unitPrice)
{
    return qty * unitPrice;
}

// Function 3: Quantity + Tax
double reorderCost(int qty, double unitPrice, double taxRate)
{
    double cost = qty * unitPrice;
    double tax = cost * taxRate / 100;

    return cost + tax;
}


// Default Argument Function
double applyDiscount(double price, double discountPercent = 10.0)
{
    return price - (price * discountPercent / 100);
}


int main2()
{
    // 1. Calling int quantity version
    double result1 = reorderCost(10, 100.0);

    // 2. Calling double quantity version
    double result2 = reorderCost(10.5, 100.0);

    // 3. Calling version with tax
    double result3 = reorderCost(10, 100.0, 18.0);


    cout << "Reorder Cost (int quantity)    : "
         << result1 << endl;

    cout << "Reorder Cost (double quantity) : "
         << result2 << endl;

    cout << "Reorder Cost (with tax)        : "
         << result3 << endl;


    // Default argument
    double discount1 = applyDiscount(1000);

    // Custom discount
    double discount2 = applyDiscount(1000, 20);


    cout << "\nPrice after default 10% discount : "
         << discount1 << endl;

    cout << "Price after 20% discount          : "
         << discount2 << endl;


    return 0;
}



