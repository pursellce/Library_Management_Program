/*
Author: Connor Pursell
Date: 4/17/21
*/
#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
using namespace std;

class libraryItem
{
	protected:
	int libID;
	float cost;
	string status;  //(In, out, lost, damaged)
	string loanPeriod; //(how long it can be checked out for-note this could be 0)
	string type;
	
	public:
	libraryItem();
	libraryItem(int libID, float cost, string status, string loanPeriod, string type);
	
	int GetLibID ();
	float GetCost();
	string GetStatus();
	string GetLoanPeriod();
	string GetType();
	
	void virtual Print();
	void SetLibID(int libID);
	void SetCost (float cost);
	void SetStatus (string status);
	void SetLoanPeriod (string loanPeriod);
	void SetType(string type);
	
	friend ostream &operator<<(ostream &output, const libraryItem &L);
	
};
#endif