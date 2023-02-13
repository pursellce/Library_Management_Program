/*
Author: Connor Pursell
Date: 3/19/21
*/
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <fstream>
#include "loans.h"
#include "patrons.h"
#include "libraryItem.h"
#include "libraryitems.h"
#include "menus.h"




using namespace std;
loansList loanslist;
patronsList patronslist;
libraryItemList libraryitemlist;


void PrintPatronMenu ()
{
	char choice;
	bool quit = false;
	do
	{
		cout<<endl<<"Patron Menu" <<endl <<endl;
		cout<<"a - Add patron" <<endl;
		cout<<"b - Remove patron" <<endl;
		cout<<"c - Modify patron" <<endl;
		cout<<"d - Print one patron" <<endl;
		cout<<"e - Print all patrons" <<endl;
		cout<<"f - Load patrons from file" <<endl;
		cout<<"g - Store patrons to patrons.dat" <<endl;
		cout<<"q - Quit and return to main menu" <<endl <<endl;
		cout<<"Choose an option: ";
		cin>> choice;
		cin.ignore();
		choice =  tolower(choice);
		
		while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'e' && choice != 'f' && choice != 'g' && choice != 'q')      
		{
			cout<<"Please select valid option: a - add patron b - remove patron c - modify patron d - print one patron e - print all patrons f -load patrons  g - store patrons q - quit"<<endl;
			cin>>choice;
			choice = tolower (choice);
			
		}
		switch (choice)
		{
			case 'a':
			{
				bool Found = false;
				unsigned int i;
				int newIDNum;
				string newName;
				patron temp;
				cout<<"Enter new patron's full name:" <<endl;
				getline (cin, newName);
				cout<<"Enter new patron's ID Num:"<<endl;
				cin>> newIDNum;
				if(patronslist.GetCount()>0)
				{
					do
					{
					
						for (i=0; i<patronslist.GetCount(); i++)
						{
						   if(patronslist.GetPatrons().at(i).GetIDNum() == newIDNum)
						   {
							   Found = true;
							   cout<<"ID number already in use. Please enter unique ID number."<<endl;
							   cin>>newIDNum;
						   }
						   else 
						   {
								Found = false;
							}
						}
						
					}while (Found == true);
				}
				Found= false;
				
				temp.SetName(newName);
				temp.SetIDNum(newIDNum);
				patronslist.AddPatron(temp);
				break;
			}
			
			case 'b':
			{
				int IDtoDelete;
				cout<<"Enter patron ID num to be removed:"<<endl;
				cin>>IDtoDelete;
				patronslist.DeletePatron(IDtoDelete);
			   
			   break;
			}
			
			case 'c':
			{
				int IDtoModify;
				cout<<"Enter patron's ID to be modified:"<<endl;
				cin>>IDtoModify;
				patronslist.ModifyPatron(IDtoModify);
				break;
			}
			
			case 'd':
			{
				int IDtoPrint;
				cout<<"Enter patron's ID to be printed:"<<endl;
				cin>>IDtoPrint;
				patronslist.PrintEntry(IDtoPrint);
				break;
			}
			
			case 'e':
			{
				cout<<"All Patrons:" <<endl;
				patronslist.PrintAll();
				break;
			}
			case 'f':
			{

				patronslist.LoadPatrons(patronslist);
				break;
			}
			
			case 'g':
			{
				patronslist.StorePatrons(patronslist);
			}
			case 'q':
			{
				quit = true;
				break;
			}
		}
	}while(quit == false);
}











void PrintItemMenu ()
{
	char choice;
	bool quit = false;
	do
	{
		cout<<endl<<"Library Item Menu" <<endl <<endl;
		cout<<"a - Add library item" <<endl;
		cout<<"b - Remove library item" <<endl;
		cout<<"c - Modify library item" <<endl;
		cout<<"d - Print one library item" <<endl;
		cout<<"e - Print all library items" <<endl;
		cout<<"f - Load library items from file" <<endl;
		cout<<"g - Store library items to libraryitems.dat" <<endl;
		cout<<"q - Quit and return to main menu" <<endl <<endl;
		cout<<"Choose an option: ";
		cin>> choice;
		choice =  tolower(choice);
		while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'e' && choice != 'f' && choice != 'g' && choice != 'q')      
		{
			cout<<"Please select valid option: a - add library item b - remove library item c - modify library item d - print one library item e - print all library items  f - load library items  g - store library items  q - quit"<<endl;
			cin>>choice;
			choice = tolower (choice);
		}
		switch (choice)
		{
			case 'a':
			{
				libraryitemlist.AddItem();
				break;
			}
		
			case 'b':
			{
				int IDtoDelete;
				cout<<"Enter library ID number to be removed:"<<endl;
				cin>>IDtoDelete;
				libraryitemlist.DeleteItem(IDtoDelete);  
			   break;
			}
			
			case 'c':
			{
				int IDtoModify;
				cout<<"Enter book's library ID to be modified:"<<endl;
				cin>>IDtoModify;
				libraryitemlist.ModifyItem(IDtoModify);
				break;
			}
			
			case 'd':
			{
				int IDtoPrint;
				cout<<"Enter book's library ID to be printed:"<<endl;
				cin>>IDtoPrint;
				libraryitemlist.PrintEntry(IDtoPrint);
				break;
			}
			
			case 'e':
			{
				cout<<"All Books:" <<endl;
				libraryitemlist.PrintAll();
				break;
			}
			
			case 'f':
			{

				libraryitemlist.LoadItems(libraryitemlist);
				break;
			}
			
			case 'g':
			{
				libraryitemlist.StoreItems(libraryitemlist);
			}
			case 'q':
			{
				quit = true;
				break;
			}
			
			
		}
	}while (quit==false);
}


void PrintLoanMenu()
{
	char choice;
	bool quit = false;
	do
	{
	cout<<endl<<"Loan Menu" <<endl <<endl;
	cout<<"a - Checkout itemk" <<endl;
	cout<<"b - Return item" <<endl;
	cout<<"c - Re-checkout item" <<endl;
	cout<<"d - Print all overdue itemd" <<endl;
	cout<<"e - Print all items for patron" <<endl;
	cout<<"f- Report item lost"<<endl;
	cout<<"g- Print loan"<<endl;
	cout<<"h - Load loans from file"<<endl;
	cout<<"i- Save loans to loans.dat" <<endl;
	cout<<"q - Quit and return to main menu" <<endl <<endl;
	cout<<"Choose an option: ";
	cin>> choice;
	choice =  tolower(choice);
	while (choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd' && choice != 'e' && choice != 'f' && choice != 'g' && choice != 'h' && choice != 'i' && choice != 'q')      
	{
		cout<<"Please select valid option: a - Checkout book  b - Return book  c - Re-checkout book  d - Print overdue books  e - Print all books for patron  f - Report book lost  g - Print loan  h- load loans  i - store loans q - quit"<<endl;
		cin>>choice;
		choice = tolower (choice);
	}
	switch (choice)
	{
		case 'a':
		{
			bool Found = false;
			bool Found2 = false;
			unsigned int i;
			int patronID, itemID, loanID;
			loan temp;
			cout<<"Checkout"<<endl;
			cout<<"Enter patron ID:"<<endl;
			cin>>patronID;
			cout<<"Enter item library ID:" <<endl;
			cin>>itemID;
			cout<<"Enter unique loan ID:"<<endl;
			cin>>loanID;
			if(loanslist.GetCount()>0)
			{
				do
				{
					for (i=0; i<loanslist.GetCount(); i++)
					{
					   if(loanslist.GetLoans().at(i).GetLoanID() == loanID)
						  {
						   Found = true;
						   cout<<"ID number already in use. Please enter unique ID number."<<endl;
						   cin>>loanID;
					   }
					   else {Found = false;}
					}
				}while (Found == true);
			}
			do
			{
				Found2 =  false;
				for(i=0; i<libraryitemlist.GetCount(); i++)
				{
					if((libraryitemlist.GetItems().at(i)->GetStatus() == "checked out")||(libraryitemlist.GetItems().at(i)->GetStatus() == "damaged")|| (libraryitemlist.GetItems().at(i)->GetStatus() == "lost"))
					{
						Found2 = true;
						cout<<"Item is currently unavailable for checkout. Please enter another item library ID number:"<<endl;
						cin>>itemID;
					}
					else 
					{Found2=false;}
				}
			}while (Found == true);
						
					
			loanslist.CheckoutItem(patronID, itemID, loanID, temp, patronslist, libraryitemlist);
			break;
		}
		
		case 'b':
		{
			int patronID, itemID, loanID;
		
			cout<<"Return"<<endl;
			cout<<"Enter patron ID:"<<endl;
			cin>>patronID;
			cout<<"Enter item library ID:" <<endl;
			cin>>itemID;
			cout<<"Enter unique loan ID:"<<endl;
			cin>>loanID;
			loanslist.ReturnItem(patronID, itemID, loanID, patronslist, libraryitemlist);
			break;
		}
		
		case 'c':
		{
			int loanID;
			cout<<"Re-checkout"<<endl;
			cout<<"Enter unique loan ID:"<<endl;
			cin>>loanID;
			loanslist.RenewLoan(loanID);
			break;
		}
		
		case 'd':
		{
			cout<<"Overdue items:"<<endl;
			loanslist.PrintOverdue(patronslist, libraryitemlist);
			break;
		}
		
		case 'e':
		{
			int patronID;
			cout<<"Enter patron ID:"<<endl;
			cin>>patronID;
			loanslist.PrintPatronItems(patronID, patronslist, libraryitemlist);
			break;
		}
		
		case 'f':
		{
			int patronID, itemID, loanID;
			cout<<"Report lost item" <<endl;
			cout<<"Enter patron ID:"<<endl;
			cin>>patronID;
			cout<<"Enter item library ID:" <<endl;
			cin>>itemID;
			cout<<"Enter unique loan ID:"<<endl;
			cin>>loanID;
			loanslist.ReportLost(patronID, itemID, loanID, patronslist, libraryitemlist);
			break;
		}
		
		case 'g':
		{
			int loanID;
			cout<<"Print Loan"<<endl;
			cout<<"Enter loan ID to print:"; cin>>loanID;
			loanslist.PrintLoan(loanID, patronslist, libraryitemlist);
			break;
		}
		
		case 'h':
		{
			loanslist.LoadLoans(loanslist, patronslist, libraryitemlist);
			break;
		}
			
		case 'i':
		{
			loanslist.StoreLoans(loanslist);
		}
		
		case 'q':
		{
			quit = true;
			break;
		}
	}
	}while (quit==false);		
			
}