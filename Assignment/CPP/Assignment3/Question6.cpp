/*
 * Question6.cpp
 *
 *  Created on: Sep 4, 2026
 *      Author: Administrator
 */


#include <iostream>
#include <cstring>
using namespace std;

class LogBuffer
{
private:
    char* buffer;
    int capacity;
    int size;
    static int instanceCount;
    mutable int accessCount = 0;

public:

    // Constructor
    LogBuffer(int capacity)
    {
        this->capacity = capacity;
        this->size = 0;

        buffer = new char[capacity];
        buffer[0] = '\0';

        instanceCount++;

        cout << "[LogBuffer Created] capacity=" << capacity << endl;
    }

    // Copy Constructor - Deep Copy
    LogBuffer(const LogBuffer& other)
    {
        capacity = other.capacity;
        size = other.size;

        buffer = new char[capacity];

        memcpy(buffer, other.buffer, size + 1);

        instanceCount++;

        cout << "[LogBuffer Deep Copied] capacity=" << capacity << endl;
    }

    // Copy Assignment Operator
    LogBuffer& operator=(const LogBuffer& other)
    {
        // Self-assignment check
        if (this == &other)
        {
            cout << "[Self-assignment detected - no operation]" << endl;
            return *this;
        }

        // Delete old memory
        delete[] buffer;

        capacity = other.capacity;
        size = other.size;

        // Allocate new memory
        buffer = new char[capacity];

        // Deep copy
        memcpy(buffer, other.buffer, size + 1);

        cout << "[LogBuffer Assigned]" << endl;

        return *this;
    }

    // Destructor
    ~LogBuffer()
    {
        delete[] buffer;
        instanceCount--;

        cout << "[LogBuffer Destroyed]" << endl;
    }

    // Append message
    void append(const char* msg)
    {
        int msgLength = strlen(msg);

        if (size + msgLength < capacity)
        {
            strcpy(buffer + size, msg);
            size += msgLength;
        }
    }

    // Print
    void print() const
    {
        accessCount++;

        cout << buffer << endl;
    }

    // Clear buffer
    void clean()
    {
        size = 0;
        buffer[0] = '\0';
    }

    // Static getter
    static int getInstanceCount()
    {
        return instanceCount;
    }

    // Bonus getter
    int getAccessCount() const
    {
        return accessCount;
    }
};


// Static member initialization
int LogBuffer::instanceCount = 0;


int main()
{
    // Objective 1 : Basic usage
    LogBuffer log1(256);

    log1.append("Server started on port 8080");
    log1.append(" | Request received from 192.168.1.10");

    log1.print();


    // Objective 2 : Deep copy via copy constructor
    LogBuffer log2 = log1;

    log2.append(" | Cached response sent");

    cout << "log1 : ";
    log1.print();

    cout << "log2 : ";
    log2.print();


    // Objective 3 : Copy assignment operator
    LogBuffer log3(128);

    log3 = log1;

    log3.print();


    // Objective 4 : Self-assignment guard
    log1 = log1;

    log1.print();


    // Objective 5 : Static member
    cout << "Live LogBuffer objects : "
         << LogBuffer::getInstanceCount() << endl;


    // Bonus : const object and mutable
    const LogBuffer readOnly(log1);

    readOnly.print();
    readOnly.print();
    readOnly.print();

    cout << "Times printed: "
         << readOnly.getAccessCount() << endl;


    return 0;
}

