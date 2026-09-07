/*
 * Question2.cpp
 *
 *  Created on: Sep 2, 2026
 *      Author: Administrator
 */


#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <iomanip>

using namespace std;

using Header      = pair<string, string>;
using HeaderList  = vector<Header>;
using Port        = unsigned int;
using IPAddress   = string;

typedef unsigned long long RequestId;

void printHeaders(const HeaderList& headers) {
    cout << "Headers:\n";
    for (const auto& h : headers) {
        cout << "  " << left << setw(17) << h.first
             << ": " << h.second << "\n";
    }
}

int main2() {
    RequestId reqId = 1748293847ULL;
    Port serverPort = 8080;

    cout << left << setw(14) << "Request ID"  << ": " << reqId << "\n";
    cout << left << setw(14) << "Server Port" << ": " << serverPort << "\n\n";

    HeaderList headers = {
        {"Content-Type", "application/json"},
        {"Authorization", "Bearer eyJhbGci..."},
        {"Accept-Language", "en-US"}
    };

    printHeaders(headers);

    return 0;
}

