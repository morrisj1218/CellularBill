// CellularBill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Constants
	const double REG_SERVICE_FEE = 10.00;
	const double REG_COST_PER_MIN = 0.20;
	const double PRE_SERVICE_FEE = 25.00;
	const double PRE_DAY_PER_MIN = 0.10;
	const double PRE_NIGHT_PER_MIN = 0.05;
	
	// Declare Variables
	char serviceCode;
	int accountNum;
	int reg_Minutes;
	int preDay_Minutes;
	int preNight_Minutes;
	double regAmountDue;
	double preDay_Charges;
	double preNight_Charges;
	double preTotal_AmtDue;

	cout << fixed << showpoint << setprecision(2);

	cout << "Enter customer account number: ";
	cin >> accountNum;
	cout << endl;

	cout << "Enter service code (R for Regular or P for Premium): ";
	cin >> serviceCode;
	cout << endl;

	switch (serviceCode)
	{
	case 'r':
	case 'R':
	{
		cout << "Enter total number of minutes used: ";
		cin >> reg_Minutes;
		cout << endl;

		if (reg_Minutes <= 50)
		{
			regAmountDue = REG_SERVICE_FEE;
		}
		else
		{
			regAmountDue = REG_SERVICE_FEE + ((reg_Minutes - 50) * REG_COST_PER_MIN);
		}

		cout << "***********************************************************************" << endl;
		cout << setfill('.') << left << setw(35) << "Account Number: " << right << " " << accountNum << endl;
		cout << setfill('.') << left << setw(35) << "Type of Service: " << right << " " << serviceCode << endl;
		cout << setfill('.') << left << setw(35) << "Number of Minutes Used: " << right << " " << reg_Minutes << endl;
		cout << setfill('.') << left << setw(35) << "Total Amount Due: "
			<< setfill(' ') << right << " $" << setw(6) << regAmountDue << endl;
		break;
	}

	case 'p':
	case 'P':
	{
		cout << "Enter total number of minutes used between 6am and 6pm: ";
		cin >> preDay_Minutes;
		cout << endl;

		cout << "Enter total number of minutes used between 6pm and 6am: ";
		cin >> preNight_Minutes;
		cout << endl;

		break;
	}

	default:
	{

		break;
	}

	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
