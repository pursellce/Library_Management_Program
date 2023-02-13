/*
Author: Connor Pursell
Date: 3/19/21
*/
#include <iostream>
#include <string>
#include <ctime>
#include "loan.h"

using namespace std;

	loan::loan()
	{
		loanID = 0;
		itemID = 0;
		patronID = 0;
		dueDateInt = 0;
		dueDateString = "none";
		status = "current";
	}
	
	loan::loan (int loanID, int itemID, int patronID, int dueDateInt, string dueDateString, string status)
	{
		this->loanID = loanID;
		this->itemID = itemID;
		this->patronID = patronID;
		this->dueDateInt = dueDateInt;
		this->status = status;
	}
	
	int loan::GetLoanID ()
	{
		return loanID;
	}
	int loan::GetItemID()
	{
		return itemID;
	}
	int loan::GetPatronID()
	{
		return patronID;
	}
	time_t loan::GetDueDate()
	{
		return dueDateInt;
	}
	string loan::GetDueDateString()
	{
		return dueDateString;
	}
	string loan::GetStatus()
	{
		return status;
	}
	
	void loan::SetLoanID(int loanID)
	{
		this->loanID = loanID;
	}
	void loan::SetItemID(int itemID)
	{
		this->itemID = itemID;
	}
	void loan::SetPatronID(int patronID)
	{
		this->patronID = patronID;
	}
	void loan::SetDueDate()
	{
		//getting date and time
		time_t rawtime = time(0);
		this->dueDateInt = rawtime+864000;		//current time + #of seconds in 10 days
		this->dueDateString = ctime(&dueDateInt);
	}
	void loan::SetDueDate(time_t dueDateInt, string dueDateString)
	{
		this->dueDateInt = dueDateInt;
		this->dueDateString = dueDateString;
	}
	void loan::SetStatus(string status)
	{
		this->status = status;
	}