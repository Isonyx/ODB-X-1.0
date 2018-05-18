#include "windows.h"
#include "stdafx.h"
#include "atlstr.h"
#include "Engine.h"
#include <iostream>

using namespace std;

class Engine
{
private:
	HANDLE mySerial;
	CString myPort;
	DCB myDCB;
	COMMTIMEOUTS timeouts;
	int myRPM;
	int mySpeed;
	int myEngineLoad;
	int myCoolantTemp;
	
	bool writeData(CString theData)
	{
		DWORD bytesWritten;
		char szBuff[10 + 1] = { 0 };
		bool retVal = true;

		retVal = WriteFile(mySerial, theData, 10, &bytesWritten, NULL);

		return retVal;
	}

	bool readData()
	{
		DWORD bytesRead;
		char szBuff[10 + 1] = { 0 };
		bool retVal = true;

		retVal = ReadFile(mySerial, szBuff, 10, &bytesRead, NULL);
		
		cout << "Read the value: " << szBuff << endl;
		return retVal;
	}
public:
	Engine(CString thePort)
	{
		myDCB = { 0 };
		mySerial = CreateFile(thePort,
			GENERIC_READ | GENERIC_WRITE,
			0,
			0,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			0);

		myPort = thePort;

		//Set baud configuration
		myDCB.BaudRate = CBR_19200;
		myDCB.ByteSize = 8;
		myDCB.Parity = NOPARITY;
		myDCB.StopBits = ONESTOPBIT;

		//COM timeouts
		timeouts = { 0 };
		timeouts.ReadIntervalTimeout = 50;
		timeouts.ReadTotalTimeoutConstant = 50;
		timeouts.ReadTotalTimeoutMultiplier = 10;
		timeouts.WriteTotalTimeoutConstant = 50;
		timeouts.WriteTotalTimeoutMultiplier = 10;
	}

	int getRPM()
	{
		CString myData("010C");
		writeData(myData);
		readData();
	}

	int getSpeed()
	{
		CString myData("010D");
		writeData(myData);
		readData();
	}

	int getEngineLoad()
	{
		CString myData("0104");
		writeData(myData);
		readData();
	}

	int getCoolantTemp()
	{
		CString myData("0105");
		writeData(myData);
		readData();
	}
};