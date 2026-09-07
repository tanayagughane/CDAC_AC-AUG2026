//============================================================================
// Name        : Question1.cpp
// Author      : Tanaya Gughane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

enum class HttpStatus{
	OK=200,
	Created=201,
	BadRequest=400,
	Unauthorized=401,
	NotFound=404,
	ServerError=500
};

void handleResponse(HttpStatus status, const string& endpoint)
{
	string statusText;
	string message;


    switch (static_cast<int>(status))
    {
            case static_cast<int>(HttpStatus::OK):
                statusText = "200 OK";
                message = "Request successful";
                break;
            case static_cast<int>(HttpStatus::Created):
                statusText = "201 Created";
                message = "Resource created";
                break;
            case static_cast<int>(HttpStatus::BadRequest):
                statusText = "400 Bad Request";
                message = "Invalid request payload";
                break;
            case static_cast<int>(HttpStatus::Unauthorized):
                statusText = "401 Unauthorized";
                message = "Authentication required";
                break;
            case static_cast<int>(HttpStatus::NotFound):
                statusText = "404 Not Found";
                message = "Endpoint does not exist";
                break;
            case static_cast<int>(HttpStatus::ServerError):
                statusText = "500 Server Error";
                message = "Internal server error - retry later";
                break;
            default:
                statusText = "Unknown";
                message = "Unknown error";
                break;
    }

    cout << left << setw(23) << endpoint << " -> " << left << setw(18) << statusText  << " : " << message << "\n";
}

int main1() {

	handleResponse(HttpStatus::OK, "/api/users");

    handleResponse(HttpStatus::Created, "/api/products");

    handleResponse(HttpStatus::NotFound, "/api/orders");

    handleResponse(HttpStatus::ServerError, "/api/payment");

	return 0;
}
