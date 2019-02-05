// CellularBill.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Programmer: Jack Morris on 02/04/2019

#include "pch.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// Constants:
	const double REG_SERVICE_FEE = 10.00;
	const double REG_COST_PER_MIN = 0.20;
	const double PRE_SERVICE_FEE = 25.00;
	const double DAY_PER_MIN = 0.10;
	const double NIGHT_PER_MIN = 0.05;

	// Variables:
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
	cout << endl;
	cout << setw(65) << setfill(' ') << right << "Nostalgic Wireless\n" << endl;

	cout << "  Enter customer account number: ";
	cin >> accountNum;
	cout << endl;

	cout << "  Enter service code (R for Regular or P for Premium): ";
	cin >> serviceCode;
	cout << endl;

	switch (serviceCode)
	{
		// CALCULATE REGULAR
		case 'r':
		case 'R':
		
			cout << "  Enter total number of minutes used: ";
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

			// DISPLAY REGULAR BILL
			cout << setw(65) << setfill('*') << " \n" << endl;

			cout << setfill('.') << setw(50) << left << "  Account Number: "
				<< setfill(' ') << right << " " << setw(7) << accountNum << endl;
			cout << setfill('.') << setw(50) << left << "  Type of Service: "
				<< right << " " << "REGULAR" << endl;
			cout << setfill('.') << setw(50) << left << "  Number of minutes accrued: "
				<< setfill(' ') << right << " " << setw(7) << reg_Minutes << endl;
			cout << endl;

			cout << setfill('.') << setw(50) << left << "  Total Amount Due: "
				<< setfill(' ') << right << " $" << setw(6) << regAmountDue << endl;
		break;

		// CALCULATE PREMIUM
		case 'p':
		case 'P':
		
			cout << "  Enter total number of minutes used between 6am and 6pm (DAYTIME): ";
			cin >> preDay_Minutes;
			cout << endl;

			cout << "  Enter total number of minutes used between 6pm and 6am (EVENING): ";
			cin >> preNight_Minutes;
			cout << endl;

			if (preDay_Minutes <= 75)
			{
				preDay_Charges = 0;
			}
			else
			{
				preDay_Charges = (preDay_Minutes - 75) * DAY_PER_MIN;
			}

			if (preNight_Minutes <= 100)
			{
				preNight_Charges = 0;
			}
			else
			{
				preNight_Charges = (preNight_Minutes - 100) * NIGHT_PER_MIN;
			}

			preTotal_AmtDue = PRE_SERVICE_FEE + preDay_Charges + preNight_Charges;

			// DISPLAY PREMIUM BILL
			cout << setw(75) << setfill('*') << " \n" << endl;

			cout << setfill('.') << setw(50) << left << "  Account Number: "
				<< setfill(' ') << right << " " << setw(7) << accountNum << endl;
			cout << setw(50) << setfill('.') << left << "  Type of Service: "
				<< right << " " << "PREMIUM" << endl;
			cout << setw(50) << setfill('.') << left << "  DAYTIME minutes accrued: "
				<< setfill(' ') << right << " " << setw(7) << preDay_Minutes << endl;
			cout << setw(50) << setfill('.') << left << "  EVENING minutes accrued: "
				<< setfill(' ') << right << " " << setw(7) << preNight_Minutes << endl;
			cout << setw(50) << setfill('.') << left << "  Service Fee: "
				<< setfill(' ') << right << " $" << setw(6) << PRE_SERVICE_FEE << endl;
			cout << setw(50) << setfill('.') << left << "  Charges for DAYTIME minutes: "
				<< setfill(' ') << right << " $" << setw(6) << preDay_Charges << endl;
			cout << setw(50) << setfill('.') << left << "  Charges for EVENING minutes: "
				<< setfill(' ') << right << " $" << setw(6) << preNight_Charges << endl;
			cout << endl;

			cout << setw(50) << setfill('.') << left << "  Total Amount Due: "
				<< setfill(' ') << right << " $" << setw(6) << preTotal_AmtDue << endl;

		break;

		default:
		cout << "  ERROR Invalid Service Code" << endl;
		cout << "  You must enter 'R', for Regular service, " << endl;
		cout << "  or 'P', for Premium service. \n" << endl; 
		cout << "  Please exit and restart application." << endl;
	}
	
	cout << "\n\n" << endl;
	system("pause");
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
