/*
Author: Connor Pursell
Date: 3/19/21
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>

#include "loans.h"



using namespace std;

	


	int loansList::GetCount() {return count;}
	void loansList::incCount() {count++;}
	void loansList::decCount(){count--;}
	
	vector<loan> loansList::GetLoans() {return loans;}
	
	
	
	void loansList::StoreLoans(loansList &loanslist)
	{
	ofstream fout ("loans.dat");
	fout.open("loans.dat");
	
	for(int i=0; i<loanslist.GetCount(); i++)
	{
		fout<<loanslist.GetLoans().at(i).GetLoanID() <<"	"<<loanslist.GetLoans().at(i).GetPatronID()<<"	"<<loanslist.GetLoans().at(i).GetItemID()<<"	";
		fout<<loanslist.GetLoans().at(i).GetDueDate()<<"	"<<loanslist.GetLoans().at(i).GetDueDateString()<<"	"<<loanslist.GetLoans().at(i).GetStatus();
	}
	cout<<"Loans stored."<<endl;
	fout.close();
}


	void loansList::LoadLoans (loansList &loanslist, patronsList &patronslist, libraryItemList &libraryitemlist)
	{
	
	ifstream fin;
	string filename, line;
	int loanID, patronID, ItemID;
	time_t dueDateInt;
	string dueDateString, status;
	loan temp;
	
	cout<<"Enter file name:"<<endl;
	cin>>filename;
	fin.open(filename);
	if (fin.is_open()){cout<<"File opened"<<endl;}
	else{cout<<"File not found"<<endl;}
	while(!fin.eof())
	{
		stringstream str;
		getline(fin, line);
		str<<line;
		str>> loanID>>patronID>>ItemID>>dueDateInt>>dueDateString>>status;
		temp.SetLoanID(loanID);
		temp.SetPatronID(patronID);
		temp.SetItemID(ItemID);
		temp.SetDueDate(dueDateInt, dueDateString);
		temp.SetStatus(status);
		loanslist.CheckoutItem(loanID, patronID, ItemID, temp, patronslist, libraryitemlist);
		loanslist.incCount();
	}
	cout<<"Loans loaded"<<endl;
	fin.close();
}
	
	
	
	
	void loansList::PrintLoan (int loanID, patronsList patronslist, libraryItemList libraryitemlist)
	{
		unsigned int i;
		unsigned int j;
		
		
		bool found = false;
		for(i=0; i<loansList::GetCount(); i++)
		{
			if (loans.at(i).GetLoanID()==loanID)
			{
				found = true;
				cout<<"Patron:";
				for(j=0; j<patronslist.GetCount(); j++)
				{
					if(loans.at(i).GetPatronID()==patronslist.GetPatrons().at(j).GetIDNum())
						{cout<<patronslist.GetPatrons().at(j).GetName();}
				}
				cout<<endl<<"Item:";
				for(j=0; j<libraryitemlist.GetCount(); j++)
				{
					if(loans.at(i).GetItemID()==libraryitemlist.GetItems().at(j)->GetLibID())
						{libraryitemlist.GetItems().at(j)->Print();}
				}
				cout<<endl<<"Due date:"<<loans.at(i).GetDueDateString()<<endl;
				cout<<endl<<"Status:"<<loans.at(i).GetStatus()<<endl;
			}
		}
		if (!found)
		{
		cout<<"Loan not found." <<endl;   
		}
	}
	
	
	void loansList::CheckoutItem(int patronID, int ItemID, int loanID, loan newLoan, patronsList &patronslist, libraryItemList &libraryitemlist) //update patron's Itemsout, set Item status, create new loan)
	{
		unsigned int i;
		
		//create new loan
		loans.push_back(newLoan);
		loans.back().SetLoanID(loanID);
		loans.back().SetPatronID(patronID);
		loans.back().SetItemID(ItemID);
		loans.back().SetDueDate();
		loansList::incCount();
		
		//update patrons Items out
		for (i=0; i<patronslist.GetCount(); i++)
		{
			if(patronslist.GetPatrons().at(i).GetIDNum() == patronID)
			{
				patronslist.GetPatrons().at(i).SetItemsOut(patronslist.GetPatrons().at(i).GetItemsOut()+1);
			}
		}
		//update Item status
		string status = "checked out";
		for (i=0; i<libraryitemlist.GetCount(); i++)
		{
			if(libraryitemlist.GetItems().at(i)->GetLibID() == ItemID)
			{
				libraryitemlist.GetItems().at(i)->SetStatus(status);

			}
		}
	}
	
	void loansList::ReturnItem (int patronID, int ItemID, int loanID, patronsList &patronslist, libraryItemList &libraryitemlist) //update patron's Itemsout, reset Item status, delete loan)
	{
		unsigned int i;
		bool found = false;
		
		//update patrons Items out
		for (i=0; i<patronslist.GetCount(); i++)
		{
			if(patronslist.GetPatrons().at(i).GetIDNum() == patronID)
			{
				patronslist.GetPatrons().at(i).SetItemsOut(patronslist.GetPatrons().at(i).GetItemsOut()-1);
			}
		}
		//update Item status
		string status = "available";
		for (i=0; i<libraryitemlist.GetCount(); i++)
		{
			if(libraryitemlist.GetItems().at(i)->GetLibID() == ItemID)
			{
				libraryitemlist.GetItems().at(i)->SetStatus(status);
			}
		}
		
		
		for(i=0; i<loansList::GetCount(); i++)
		{
			if (loans.at(i).GetLoanID()==loanID)
			{
					found = true;
					loans.erase(loans.begin()+i);
					loansList::decCount();
			}
		}
	if (!found)
	{
		cout<<"Loan not found." <<endl;   
	}
		
	}

	void loansList::ModifyLoan (int loanID) //update status: check if overdue or not
	{
		time_t rawtime = time(0);
		int newpatronID, newItemID;
		string overdue = "overdue";
		unsigned int i;
		bool found = false;
		char choice;
		for(i=0; i<loansList::GetCount(); i++)
		{
			if (loans.at(i).GetLoanID()==loanID)
			{
				found = true;
				cout<<"What do you want to modify? a)Patron ID b)Item library ID. Status will be updated automatically."<<endl;
				cin>> choice;
				while (choice != 'a' && choice != 'b')      
				{
					cin>>choice;
				}
				switch (choice)
				{
					case 'a':
					{
						cout<<"Enter new patron ID:" <<endl;
						cin>>newpatronID;
						loans.at(i).SetPatronID(newpatronID);
						break;
					}
					case 'b':
					{
						cout<<"Enter new item library ID:" <<endl;
						cin>>newItemID;
						loans.at(i).SetItemID(newItemID);
						break;		
					}					
				}
			}
		}
			
	
		for(i=0; i<loansList::GetCount(); i++)
		{
			if (loans.at(i).GetDueDate() >= rawtime)
			{
				loans.at(i).SetStatus(overdue);
			}
		}
		if (!found)
		{
			cout<<"Loan not found." <<endl;   
		}
	}
	
	void loansList::RenewLoan (int loanID) //update loan due date
	{
		unsigned int i;
		bool found = false;
		for(i=0; i<loansList::GetCount(); i++)
		{
			if (loans.at(i).GetLoanID()==loanID)			
			{
				found = true;
				loans.at(i).SetDueDate();
			}
		}
		if (!found)
		{
			cout<<"Loan not found." <<endl;   
		}
	}
			
			
	void loansList::PrintOverdue (patronsList patronslist, libraryItemList libraryitemlist)	//find all Items overdue and print all; update Items with status 'overdue'
	{
		unsigned int i;
		time_t rawtime;
		string time_str;
		string overdue = "overdue";
		bool found = false;
		for(i=0; i<loansList::GetCount(); i++)
		{
			if (loans.at(i).GetDueDate() >= rawtime)
			{
				loans.at(i).SetStatus(overdue);
			}
		}
		for(i=0; i<loansList::GetCount(); i++)
		{
			if (loans.at(i).GetStatus()=="overdue")			//find patron
			{
				found = true;
				loansList::PrintLoan(loans.at(i).GetLoanID(), patronslist, libraryitemlist);
			}
		}
		if (!found)
		{
			cout<<"No overdue Items found." <<endl;   
		}
	}
	
	
	void loansList::PrintPatronItems (int patronID, patronsList patronslist, libraryItemList libraryitemlist) //Find and Print all Items for particular patron
	{
		unsigned int i;
		unsigned int j;
		bool found = false;
		for(j=0; j<patronslist.GetCount(); j++)
		{
			if(patronslist.GetPatrons().at(j).GetIDNum() == patronID)
			{	
				found = true;
				cout<<patronslist.GetPatrons().at(j).GetName() <<"'s current Items:"<<endl;
			}
		}
		if (!found)
		{cout<<"Patron not found"<<endl;}
		for(i=0; i<loansList::GetCount(); i++)
		{
			if (loans.at(i).GetPatronID()==patronID)			//find patron
			{
				found = true;
				for(j=0; j<libraryitemlist.GetCount(); j++)
				{
					if(loans.at(i).GetItemID()==libraryitemlist.GetItems().at(j)->GetLibID())
						{libraryitemlist.GetItems().at(j)->Print();cout<<endl<<endl;}
					else {cout<<"None"<<endl;}
				}
				
			}
		}	
		if (found = false)
		{cout<<"Patron not found"<<endl;}
	}	
				
				
				
	void loansList::ReportLost (int patronID, int ItemID, int loanID, patronsList &patronslist, libraryItemList &libraryitemlist)    //(update patron fines, delete Item, delete loan)
	{
		unsigned int i;
		unsigned int j;
		bool foundpatron = false;
		bool foundItem = false; 
		bool foundloan = false;
		float costofLoss;
		for(i=0; i<libraryitemlist.GetCount(); i++)			//get cost & delete Item from list
		{
			if (libraryitemlist.GetItems().at(i)->GetLibID() == ItemID)
			{
				foundItem= true;
				costofLoss = libraryitemlist.GetItems().at(i)->GetCost();
				libraryitemlist.DeleteItem(ItemID);
			}
		}
			if(!foundItem)
			{
				cout<<"Item not found."<<endl;
			}
				
		for(j=0; j<patronslist.GetCount(); j++)		//add cost to Patron's fine balance
				{
					foundpatron = true;
					if(patronslist.GetPatrons().at(j).GetIDNum()==patronID)
					{
						patronslist.UpdateFine(patronID, costofLoss);
						
					}
				}
				if (!foundpatron)
				{
					cout<<"Patron not found." <<endl;
				}
				
		for(i=0; i<loansList::GetCount(); i++)		//delete loan
		{
			if(loans.at(i).GetLoanID() == loanID)
			{
				foundloan = true;
				loans.erase(loans.begin()+i);
				loansList::decCount();
			}
		}
		if (!foundloan)
		{
			cout<<"Loan not found."<<endl;
		}
		
	}
	