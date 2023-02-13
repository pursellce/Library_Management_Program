/*
Author: Connor Pursell
Date: 3/19/21
*/
#include <iostream>
#include <string>
#include<ctime>

using namespace std;

class loan
{
	private:
	int loanID;
	int itemID;
	int patronID;
	time_t dueDateInt;
	string dueDateString;
	string status;

	public:
	loan();
	loan(int loanID, int itemID, int patronID, int dueDateInt, string dueDateString, string status);
	int GetLoanID ();
	int GetItemID();
	int GetPatronID();
	time_t GetDueDate();
	string GetDueDateString();
	string GetStatus();
	
	void SetLoanID(int loanID);
	void SetItemID(int bookID);
	void SetPatronID(int patronID);
	void SetDueDate();
	void SetDueDate(time_t dueDateInt, string dueDateString);
	void SetStatus(string status);


};