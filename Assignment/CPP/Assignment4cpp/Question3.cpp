/*
 * Question3.cpp
 *
 *  Created on: Sep 4, 2026
 *      Author: Administrator
 */


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdexcept>

using namespace std;

// ======================================================
// PART A — ABSTRACT CLASS DataProcessor
// ======================================================

class DataProcessor {
public:

    // Pure virtual functions
    virtual void loadData(const string& source) = 0;

    virtual void processData() = 0;

    virtual void exportResult(const string& destination) = 0;

    virtual string processorType() const = 0;

    virtual int recordCount() const = 0;

    // Non-pure virtual function
    virtual void printSummary() const {
        cout << "Processor Type : " << processorType() << endl;
        cout << "Record Count   : " << recordCount() << endl;
    }

    // Virtual destructor
    virtual ~DataProcessor() = default;
};


// ======================================================
// CSVProcessor
// ======================================================

class CSVProcessor : public DataProcessor {

private:
    vector<string> records;

public:

    void loadData(const string& source) override {

        // Simulating CSV file data
        records = {
            "tanaya,25,mumbai",
            "apurva,30,pune",
            "jyoti,28,nagpur",
            "santosh,35,nashik",
            "gaurav,22,mumbai"
        };

        cout << "[CSV] Data loaded from: " << source << endl;
    }

    void processData() override {

        // Convert every record to uppercase
        for (string& record : records) {

            transform(record.begin(),
                      record.end(),
                      record.begin(),
                      ::toupper);
        }

        cout << "[CSV] Data processed." << endl;
    }

    void exportResult(const string& destination) override {

        cout << "[CSV EXPORT -> " << destination << "]" << endl;

        for (const string& record : records) {
            cout << record << endl;
        }
    }

    string processorType() const override {
        return "CSV Processor";
    }

    int recordCount() const override {
        return records.size();
    }
};


// ======================================================
// SensorStreamProcessor
// ======================================================

class SensorStreamProcessor : public DataProcessor {

private:
    vector<double> readings;

    double mean = 0;
    double minimum = 0;
    double maximum = 0;

public:

    void loadData(const string& source) override {

        // Simulating sensor readings
        readings = {
            23.4,
            21.8,
            25.1,
            24.6,
            22.9,
            26.3,
            23.7,
            24.2
        };

        cout << "[Sensor] Data loaded from: "
             << source << endl;
    }

    void processData() override {

        if (readings.empty())
            return;

        double sum = 0;

        minimum = readings[0];
        maximum = readings[0];

        for (double value : readings) {

            sum += value;

            if (value < minimum)
                minimum = value;

            if (value > maximum)
                maximum = value;
        }

        mean = sum / readings.size();

        cout << "[Sensor] Data processed." << endl;
    }

    void exportResult(const string& destination) override {

        cout << "[Sensor EXPORT -> "
             << destination << "]" << endl;

        cout << fixed << setprecision(2);

        cout << "Mean : " << mean << endl;
        cout << "Min  : " << minimum << endl;
        cout << "Max  : " << maximum << endl;
    }

    string processorType() const override {
        return "Sensor Stream Processor";
    }

    int recordCount() const override {
        return readings.size();
    }

    // Getter required for dynamic_cast bonus
    double getMean() const {
        return mean;
    }
};


// ======================================================
// PART B — TEMPLATE CLASS DataBuffer<T>
// ======================================================

template <typename T>
class DataBuffer {

private:

    T* data;       // dynamically allocated array

    int capacity;

    int head;      // oldest element

    int tail;      // next position to write

    int count;     // current number of elements


public:

    // Constructor
    DataBuffer(int capacity) {

        if (capacity <= 0) {
            throw invalid_argument("Capacity must be positive");
        }

        this->capacity = capacity;

        data = new T[capacity];

        head = 0;
        tail = 0;
        count = 0;
    }


    // Destructor
    ~DataBuffer() {

        delete[] data;
    }


    // Push element
    void push(const T& value) {

        data[tail] = value;

        tail = (tail + 1) % capacity;

        // If buffer is full
        if (count == capacity) {

            // Oldest element is overwritten
            head = (head + 1) % capacity;

        }
        else {

            count++;
        }
    }


    // Pop oldest element
    T pop() {

        if (isEmpty()) {

            throw underflow_error("Buffer is empty");
        }

        T value = data[head];

        head = (head + 1) % capacity;

        count--;

        return value;
    }


    // View oldest element
    T peek() const {

        if (isEmpty()) {

            throw underflow_error("Buffer is empty");
        }

        return data[head];
    }


    // Check empty
    bool isEmpty() const {

        return count == 0;
    }


    // Check full
    bool isFull() const {

        return count == capacity;
    }


    // Current size
    int size() const {

        return count;
    }


    // Friend operator <<
    template <typename U>
    friend ostream& operator<<(ostream& out,
                               const DataBuffer<U>& buf);
};


// ======================================================
// operator << for DataBuffer
// ======================================================

template <typename U>
ostream& operator<<(ostream& out,
                    const DataBuffer<U>& buf) {

    out << "[";

    for (int i = 0; i < buf.count; i++) {

        int index = (buf.head + i) % buf.capacity;

        out << buf.data[index];

        if (i < buf.count - 1)
            out << ", ";
    }

    out << "]";

    return out;
}


// ======================================================
// MAIN
// ======================================================

int main() {

    // ==================================================
    // PART A — Abstract Pointer Array
    // ==================================================

    cout << "========== PART A ==========" << endl;

    vector<DataProcessor*> pipeline;

    pipeline.push_back(new CSVProcessor());
    pipeline.push_back(new SensorStreamProcessor());


    for (auto* p : pipeline) {

        p->loadData("source_data");

        p->processData();

        p->printSummary();

        p->exportResult("output_dir");

        cout << "---" << endl;
    }


    // ==================================================
    // BONUS — dynamic_cast
    // ==================================================

    cout << endl;
    cout << "========== dynamic_cast CHECK ==========" << endl;

    for (auto* p : pipeline) {

        if (auto* csv = dynamic_cast<CSVProcessor*>(p)) {

            cout << "Found CSV Processor with "
                 << csv->recordCount()
                 << " records." << endl;
        }

        else if (auto* sensor =
                     dynamic_cast<SensorStreamProcessor*>(p)) {

            cout << "Found Sensor Processor - Mean: "
                 << sensor->getMean()
                 << endl;
        }
    }


    // ==================================================
    // Cleanup
    // ==================================================

    for (auto* p : pipeline) {

        delete p;
    }


    // ==================================================
    // PART B — DataBuffer<int>
    // ==================================================

    cout << endl;
    cout << "========== INTEGER BUFFER ==========" << endl;

    DataBuffer<int> tickBuffer(5);

    for (int i = 1; i <= 7; i++) {

        tickBuffer.push(i * 10);
    }

    cout << "Tick Buffer: "
         << tickBuffer
         << "  (10 and 20 were overwritten)"
         << endl;


    // ==================================================
    // DataBuffer<double>
    // ==================================================

    cout << endl;
    cout << "========== DOUBLE BUFFER ==========" << endl;

    DataBuffer<double> tempBuffer(4);

    tempBuffer.push(36.6);
    tempBuffer.push(37.1);
    tempBuffer.push(38.2);
    tempBuffer.push(36.9);

    cout << "Before pop: "
         << tempBuffer
         << endl;

    cout << "Popped: "
         << tempBuffer.pop()
         << endl;

    cout << "After pop:  "
         << tempBuffer
         << endl;


    // ==================================================
    // DataBuffer<string>
    // ==================================================

    cout << endl;
    cout << "========== STRING BUFFER ==========" << endl;

    DataBuffer<string> logBuffer(3);

    logBuffer.push("INFO: Server started");

    logBuffer.push("WARN: High memory usage");

    logBuffer.push("ERROR: DB connection timeout");

    logBuffer.push("INFO: Retry successful");

    cout << "Log Buffer: "
         << logBuffer
         << endl;


    // ==================================================
    // ABSTRACT CLASS OBJECT — SHOULD NOT COMPILE
    // ==================================================

    /*
        DataProcessor dp;

        ERROR:
        Cannot create object of abstract class
        because DataProcessor contains pure virtual functions.
    */


    cout << endl;
    cout << "Program completed successfully." << endl;

    return 0;
}

