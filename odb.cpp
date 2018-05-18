// ODB-X-1.0.cpp : Reads OBD COM port information through Windows API
// to provide engine diagnostic information
// Isonyx
// Created 10/28/2015

#include "stdafx.h"
#include "engine.h"
#include <iostream>

using namespace std;

int main()
{
	int myInput = 0;
	Engine thePower = Engine("COM1");

	cout << "Engine diagnostics menu" << endl;
	cout << "Select from the following options:" << endl;
	cout << "1. Query RPMs rom engine (rpm)" << endl
		<< "2. Retrieve instantaneous speed (km/h)"
		<< "3. Query Engine Load percentage (%)"
		<< "4. Retrieve coolant temperature (C)" << endl;

	switch (myInput)
	{
	default:
		cout << "Your number was not found in the directory!";
		main();
	case 1:
		cout << thePower.getRPM() << " rpm" << endl;
	case 2:
		cout << thePower.getSpeed() << " speed" << endl;
	case 3:
		cout << thePower.getEngineLoad() << " %" << endl;
	case 4:
		cout << thePower.getCoolantTemp() << " C" << endl;
	}

    return 0;
}
