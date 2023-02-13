/*
Author: Connor Pursell
Date: 3/19/21
*/
#ifndef LOANS_H
#define LOANS_H
#include <string>
#include <iostream>
#include <vector>
#include "loan.h"
#include"patrons.h"
#include "libraryitems.h"

using namespace std;

class loansList
{
	private:
	int count;
	vector <loan> loans;
	
	public:
	void incCount();
	void decCount();
	int GetCount();
	vector<loan> GetLoans();

	void StoreLoans(loansList &loanslist);
	void LoadLoans (loansList &loanslist, patronsList &patronslist, libraryItemList &libraryitemlist);	

	void PrintLoan(int loanID, patronsList patronsList, libraryItemList libraryitemlist);
	void CheckoutItem(int patronID, int bookID, int loanID, loan newLoan, patronsList &patronsList, libraryItemList &libraryitemlist); 
	void ReturnItem (int patronID, int bookID, int loanID, patronsList &patronsList, libraryItemList &libraryitemlist);
	void ModifyLoan (int loanID);
	void RenewLoan (int loanID);
	void PrintOverdue (patronsList patronslist, libraryItemList libraryitemlist);	//find all books overdue and print all; update books with status 'overdue'
	void PrintPatronItems (int patronID, patronsList patronsList, libraryItemList libraryitemlist); //Find and Print all books for particular patron
	void ReportLost (int patronID, int bookID, int loanID, patronsList &patronsList, libraryItemList &libraryitemlist);    //(delete book,edit patron)


};
#endif