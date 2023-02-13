/*
Author: Connor Pursell
Date: 4/17/21
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "libraryItem.h"

using namespace std;

	libraryItem::libraryItem()
	{
		libID =  0;
		cost = 0.00;
		status = "unknown";
		loanPeriod = "0 days";
		type = "unknown";
	}
	
	libraryItem::libraryItem(int libID, float cost, string status, string loanPeriod, string type)
	{
		this->libID = libID;
		this->cost =  cost;
		this->status = status;
		this->loanPeriod = loanPeriod;	
		this-> type = type;
	}
	
	int libraryItem::GetLibID () {return libID;}
	float libraryItem::GetCost() {return cost;}
	string libraryItem::GetStatus() {return status;}
	string libraryItem::GetLoanPeriod() {return loanPeriod;}
	string libraryItem::GetType() {return type;}
	
	void libraryItem::Print()
	{
			cout<<*this;
	}
	void libraryItem::SetLibID(int libID) {this -> libID = libID;}
	void libraryItem::SetCost (float cost) {this ->cost = cost;}
	void libraryItem::SetStatus (string status) {this-> status = status;}
	void libraryItem::SetLoanPeriod (string loanPeriod) {this-> loanPeriod = loanPeriod;}
	void libraryItem::SetType (string type) {this->type = type;}
	
	
	
	ostream &operator<<(ostream &output, const libraryItem &L)
	{
		output <<"Library ID: "<<L.libID<<endl<<"Cost: $"<<L.cost <<endl;
		output <<"Status: " <<L.status<<endl<<"Loan Period: "<<L.loanPeriod<<endl;
		output <<"Type: " <<L.type <<endl;
		
		return output;
	}