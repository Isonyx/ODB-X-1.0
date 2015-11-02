#include "windows.h"
#include "stdafx.h"
#include "atlstr.h"

#pragma once
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

	bool writeData(CString theData);

	bool readData();
public:
	Engine(CString thePort);

	int getRPM();
	int getSpeed();
	int getEngineLoad();
	int getCoolantTemp();
};

