/*
 * Question2.cpp
 *
 *  Created on: Sep 4, 2026
 *      Author: Administrator
 */


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;


// =====================================================
// BASE CLASS : Vehicle
// =====================================================

class Vehicle {
protected:
    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:

    // Constructor
    Vehicle(const string& reg, const string& owner,
            int year, double km)
        : registrationNo(reg),
          ownerName(owner),
          yearOfManufacture(year),
          kmDriven(km) {

        cout << "[Vehicle Constructor] "
             << registrationNo << " : "
             << ownerName << endl;
    }

    // Pure virtual function
    virtual double fuelCost(double kmToTravel) const = 0;

    // Virtual function
    virtual void describe() const {
        cout << registrationNo << " "
             << vehicleType() << " "
             << ownerName << " "
             << kmDriven << endl;
    }

    // Pure virtual function
    virtual string vehicleType() const = 0;

    // Virtual destructor
    virtual ~Vehicle() {
        cout << "[Vehicle Destructor] "
             << registrationNo << endl;
    }

    double getKmDriven() const {
        return kmDriven;
    }

    string getRegNo() const {
        return registrationNo;
    }
};


// =====================================================
// CAR : Single Inheritance
// =====================================================

class Car : public Vehicle {

private:
    string fuelType;
    double mileageKmPerL;

public:

    Car(const string& reg,
        const string& owner,
        int year,
        double km,
        const string& fuel,
        double mileage)
        : Vehicle(reg, owner, year, km),
          fuelType(fuel),
          mileageKmPerL(mileage) {

        cout << "[Car Constructor] "
             << registrationNo << endl;
    }

    // Function overriding
    double fuelCost(double kmToTravel) const override {

        double fuelPrice;

        if (fuelType == "Petrol")
            fuelPrice = 106.00;
        else
            fuelPrice = 93.00;

        return (kmToTravel / mileageKmPerL) * fuelPrice;
    }

    string vehicleType() const override {
        return "Car";
    }

    void describe() const override {

        cout << registrationNo
             << " | Car | "
             << ownerName
             << " | Km: "
             << kmDriven
             << " | Fuel: "
             << fuelType
             << " | Mileage: "
             << mileageKmPerL
             << " km/L"
             << endl;
    }

    ~Car() override {
        cout << "[Car Destructor] "
             << registrationNo << endl;
    }
};


// =====================================================
// TRUCK : Single Inheritance
// =====================================================

class Truck : public Vehicle {

protected:
    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:

    Truck(const string& reg,
          const string& owner,
          int year,
          double km,
          double payload,
          double efficiency)
        : Vehicle(reg, owner, year, km),
          payloadCapacityTons(payload),
          fuelEfficiencyKmpl(efficiency) {

        cout << "[Truck Constructor] "
             << registrationNo << endl;
    }

    // Function overriding
    double fuelCost(double kmToTravel) const override {

        // Efficiency drops 5% per ton
        double efficiencyDrop =
            1.0 - (0.05 * payloadCapacityTons);

        double effectiveEfficiency =
            fuelEfficiencyKmpl * efficiencyDrop;

        double fuelPrice = 93.00; // Diesel

        return (kmToTravel / effectiveEfficiency)
               * fuelPrice;
    }

    string vehicleType() const override {
        return "Truck";
    }

    void describe() const override {

        cout << registrationNo
             << " | Truck | "
             << ownerName
             << " | Km: "
             << kmDriven
             << " | Payload: "
             << payloadCapacityTons
             << " tons"
             << " | Efficiency: "
             << fuelEfficiencyKmpl
             << " km/L"
             << endl;
    }

    ~Truck() override {
        cout << "[Truck Destructor] "
             << registrationNo << endl;
    }
};


// =====================================================
// ELECTRIC TRUCK : Multilevel Inheritance
// Vehicle -> Truck -> ElectricTruck
// =====================================================

class ElectricTruck : public Truck {

private:
    double batteryCapacityKWh;
    double rangePerChargeKm;

    double batteryChargePercent;

public:

    ElectricTruck(const string& reg,
                  const string& owner,
                  int year,
                  double km,
                  double payload,
                  double efficiency,
                  double batteryCapacity,
                  double rangePerCharge,
                  double chargePercent = 85.0)

        : Truck(reg, owner, year, km,
                payload, efficiency),
          batteryCapacityKWh(batteryCapacity),
          rangePerChargeKm(rangePerCharge),
          batteryChargePercent(chargePercent) {

        cout << "[ElectricTruck Constructor] "
             << registrationNo << endl;
    }

    // Override Truck's fuelCost
    double fuelCost(double kmToTravel) const override {

        double electricityCostPerUnit = 9.50;

        return (kmToTravel / rangePerChargeKm)
               * batteryCapacityKWh
               * electricityCostPerUnit;
    }

    string vehicleType() const override {
        return "Electric Truck";
    }

    void describe() const override {

        cout << registrationNo
             << " | Electric Truck | "
             << ownerName
             << " | Km: "
             << kmDriven
             << " | Battery: "
             << batteryCapacityKWh
             << " kWh"
             << " | Range: "
             << rangePerChargeKm
             << " km"
             << endl;
    }

    double getBatteryChargePercent() const {
        return batteryChargePercent;
    }

    ~ElectricTruck() override {
        cout << "[ElectricTruck Destructor] "
             << registrationNo << endl;
    }
};


// =====================================================
// VAN : Hierarchical Inheritance
// Vehicle -> Van
// =====================================================

class Van : public Vehicle {

private:
    int seatingCapacity;
    double mileageKmPerL;

public:

    Van(const string& reg,
        const string& owner,
        int year,
        double km,
        int seats,
        double mileage)
        : Vehicle(reg, owner, year, km),
          seatingCapacity(seats),
          mileageKmPerL(mileage) {

        cout << "[Van Constructor] "
             << registrationNo << endl;
    }

    double fuelCost(double kmToTravel) const override {

        double petrolPrice = 106.00;

        return (kmToTravel / mileageKmPerL)
               * petrolPrice;
    }

    string vehicleType() const override {
        return "Van";
    }

    void describe() const override {

        cout << registrationNo
             << " | Van | "
             << ownerName
             << " | Km: "
             << kmDriven
             << " | Seats: "
             << seatingCapacity
             << " | Mileage: "
             << mileageKmPerL
             << " km/L"
             << endl;
    }

    ~Van() override {
        cout << "[Van Destructor] "
             << registrationNo << endl;
    }
};


// =====================================================
// FLEET REPORT FUNCTION
// =====================================================

void printFleetReport(const vector<Vehicle*>& fleet,
                      double tripKm) {

    cout << "\n";
    cout << "===== FLEET REPORT - Trip Distance: "
         << tripKm
         << " km =====\n\n";

    cout << left
         << setw(13) << "Reg"
         << setw(18) << "Type"
         << setw(22) << "Owner"
         << setw(12) << "Km Driven"
         << endl;

    cout << "-------------------------------------------------------------\n";

    // -------------------------------------------------
    // Vehicle information
    // -------------------------------------------------

    for (const auto* vehicle : fleet) {

        cout << left
             << setw(13) << vehicle->getRegNo()
             << setw(18) << vehicle->vehicleType()
             << setw(22) << vehicle->getKmDriven()
             << endl;
    }

    // -------------------------------------------------
    // Fuel / Charge Cost
    // -------------------------------------------------

    cout << "\n===== FUEL / CHARGE COST ESTIMATE =====\n";

    double minimumCost = 1e9;
    const Vehicle* mostEfficient = nullptr;

    cout << fixed << setprecision(2);

    for (const auto* vehicle : fleet) {

        double cost = vehicle->fuelCost(tripKm);

        cout << vehicle->getRegNo()
             << " (" << vehicle->vehicleType() << ")"
             << " : Rs. "
             << cost;

        // Identify Electric Truck using dynamic_cast
        const ElectricTruck* electricTruck =
            dynamic_cast<const ElectricTruck*>(vehicle);

        if (electricTruck != nullptr) {

            cout << "  [Battery: "
                 << electricTruck->getBatteryChargePercent()
                 << "% charged]";
        }
        else {

            if (vehicle->vehicleType() == "Car")
                cout << "  (Petrol/Diesel)";

            else if (vehicle->vehicleType() == "Truck")
                cout << "  (Diesel)";

            else if (vehicle->vehicleType() == "Van")
                cout << "  (Petrol)";
        }

        cout << endl;

        // Find minimum cost
        if (cost < minimumCost) {
            minimumCost = cost;
            mostEfficient = vehicle;
        }
    }

    // -------------------------------------------------
    // Most Efficient Vehicle
    // -------------------------------------------------

    if (mostEfficient != nullptr) {

        cout << "\nMost Efficient Vehicle: "
             << mostEfficient->getRegNo()
             << " (" << mostEfficient->vehicleType() << ")"
             << " - Rs. "
             << minimumCost
             << " for "
             << tripKm
             << " km"
             << endl;
    }
}


// =====================================================
// MAIN
// =====================================================

int main2() {

    // =================================================
    // PART B
    // Constructor / Destructor Execution Order
    // =================================================

    cout << "===== CONSTRUCTOR / DESTRUCTOR ORDER =====\n";

    {
        ElectricTruck et(
            "V-ET001",
            "Green Logistics",
            2024,
            50000,
            5.0,
            4.0,
            600.0,
            300.0
        );

        cout << "...scope ends...\n";
    }

    // =================================================
    // PART C
    // Polymorphic Fleet
    // =================================================

    cout << "\n\n===== CREATING FLEET =====\n";

    vector<Vehicle*> fleet;

    // 1. Car
    fleet.push_back(
        new Car(
            "KA01AA001",
            "Ramesh Kumar",
            2022,
            45200,
            "Petrol",
            18.0
        )
    );

    // 2. Truck
    fleet.push_back(
        new Truck(
            "MH04BB002",
            "Shyam Logistics",
            2021,
            123500,
            3.0,
            5.0
        )
    );

    // 3. Electric Truck
    fleet.push_back(
        new ElectricTruck(
            "GJ07CC003",
            "Green Fleet Co",
            2025,
            89000,
            2.0,
            5.0,
            600.0,
            300.0,
            85.0
        )
    );

    // 4. Van
    fleet.push_back(
        new Van(
            "MH12DD004",
            "City Transport",
            2023,
            67000,
            12,
            14.0
        )
    );

    // 5. Another Car
    fleet.push_back(
        new Car(
            "DL05EE005",
            "ABC Travels",
            2020,
            78500,
            "Diesel",
            20.0
        )
    );


    // =================================================
    // POLYMORPHISM
    // =================================================

    printFleetReport(fleet, 200);


    // =================================================
    // DYNAMIC_CAST SAFETY CHECK
    // =================================================

    cout << "\n===== DYNAMIC_CAST CHECK =====\n";

    for (auto* vehicle : fleet) {

        if (auto* electric =
                dynamic_cast<ElectricTruck*>(vehicle)) {

            cout << "Found Electric Truck: "
                 << electric->getRegNo()
                 << " | Battery: "
                 << electric->getBatteryChargePercent()
                 << "% charged"
                 << endl;
        }
    }


    // =================================================
    // CLEANUP
    // =================================================

    cout << "\n===== CLEANUP =====\n";

    for (auto* vehicle : fleet) {
        delete vehicle;
    }

    fleet.clear();

    return 0;
}

