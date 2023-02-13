/*
Author: Connor Pursell
Date: 3/19/21
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "libraryitems.h"



using namespace std;


libraryItemList::libraryItemList()
{
	count = 0;
}

int libraryItemList::GetCount() {return count;}
void libraryItemList::incCount() {count++;}
void libraryItemList::decCount(){count--;}
vector<libraryItem*> libraryItemList::GetItems() {return libraryItems;}





//EDIT!!!

void libraryItemList::LoadItems(libraryItemList &libraryItemslist)
{
	
	ifstream fin;
	
	string line;
	string filename;
	int libID;
	float cost;
	string status, loanPeriod, type;
	libraryItem *temp;
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
		str>> libID >>cost >>status >>loanPeriod>>type;
		temp->SetStatus(status);
		temp->SetLibID(libID);
		temp->SetCost(cost);
		temp->SetLoanPeriod(loanPeriod);
		temp->SetType(type);
		libraryItemList::AddItem(temp);
		libraryItemList::incCount();
	}
	
	fin.close();
}



void libraryItemList::StoreItems(libraryItemList &libraryItemslist)
{
	ofstream fout ("libraryItems.dat");
	fout.open("libraryItems.dat");
	
	for(int i=0; i<libraryItemslist.GetCount(); i++)
	{
		fout<<libraryItems[i]->GetLibID() <<"	"<<libraryItems[i]->GetLoanPeriod()<<"	";
		fout<<libraryItems[i]->GetCost()<<"	"<<libraryItems[i]->GetStatus();
		fout<<libraryItems[i]->GetType()<<"	";
	}
	cout<<"libraryItems stored."<<endl;
	fout.close();
}


void libraryItemList::AddItem ()
{
	libraryItem *temp;
	bool Found = false;
	int i;
	int newIDNum;
	string newTitle, newAuthor, newArtist, newStatus, newLoanPeriod, newCategory;
	string newGenre, newReleaseDate, newRunTime, newStudio;
	int selection, newISBN, newNumTracks;
	float newCost;
	cout<<"Enter new library item's library ID Num:"<<endl;
	cin>> newIDNum;
	if(libraryItemList::GetCount()>0)
	{
		do
		{
			for (i=0; i<libraryItemList::GetCount(); i++)
			{
			   if(libraryItemList::GetItems()[i]->GetLibID() == newIDNum)
			   {
				   Found = true;
				   cout<<"ID number already in use. Please enter unique ID number."<<endl;
				   cin>>newIDNum;
			   }
			   else
			   {	Found = false;}
			}
						
		}while (Found == true);
	}
	cin.ignore();
	cout<<"Enter loan period:"<<endl;
	getline (cin, newLoanPeriod);
	cout<<"Enter status (available, checked out, damaged):" <<endl;
	getline (cin, newStatus);
	cout<<"Enter  cost:"<<endl;
	cin>>newCost;
	cout<<"Enter 1 for book, 2 for CD, 3 for DVD:"<<endl;
	cin>> selection;
	while(selection != 1 && selection != 2 && selection != 3)
	{	
		cout<<"Please make valid selection- 1 for book, 2 for CD, 3 for DVD"<<endl;
		cin>>selection;
	}
	switch (selection)
	{
		case 1:
		{
			book *newBook = new book;
			cin.ignore();
			cout<<"Enter new book's title:" <<endl;
			getline (cin, newTitle);
			cout<<"Enter book's author:" <<endl;
			getline (cin, newAuthor);
			cout<<"Enter book's category:"<<endl;
			getline(cin, newCategory);
			cout<<"Enter book's ISBN number:" <<endl;
			cin>>newISBN;
			
			newBook->SetLibID(newIDNum);
			newBook->SetCost(newCost);
			newBook->SetStatus(newStatus);
			newBook->SetLoanPeriod(newLoanPeriod);
			newBook->SetTitle(newTitle);
			newBook->SetAuthor(newAuthor);
			newBook->SetISBNNum(newISBN);
			newBook->SetCategory(newCategory);
			
			libraryItems.push_back(newBook);
			libraryItemList::incCount();
			
			break;
		}
		case 2:
		{
			cin.ignore();
			audioCD *newCD = new audioCD;
			cout<<"Enter CD's artist:" <<endl;
			getline(cin, newArtist);
			cout<<"Enter CD's title:"<<endl;
			getline(cin, newTitle);
			cout<<"Enter CD's release date (MM/DD/YYYY):"<<endl;
			getline(cin, newReleaseDate);
			cout<<"Enter CD's genre:"<<endl;
			getline(cin, newGenre);
			cout<<"Enter number of tracks:"<<endl;
			cin>>newNumTracks;
					
			newCD->SetLibID(newIDNum);
			newCD->SetCost(newCost);
			newCD->SetStatus(newStatus);
			newCD->SetLoanPeriod(newLoanPeriod);
			newCD->SetArtist(newArtist);
			newCD->SetTitle(newTitle);
			newCD->SetReleaseDate(newReleaseDate);
			newCD->SetNumTracks(newNumTracks);
			newCD->SetGenre(newGenre);
			
			libraryItems.push_back(newCD);
			libraryItemList::incCount();
		
			
			break;
		}
		case 3:
		{
			cin.ignore();
			DVD *newDVD = new DVD;
			cout<<"Enter DVD's title:"<<endl;
			getline(cin, newTitle);
			cout<<"Enter DVD's category:"<<endl;
			getline(cin, newCategory);
			cout<<"Enter DVD's release date (MM/DD/YYYY):"<<endl;
			getline(cin, newReleaseDate);
			cout<<"Enter DVD's studio:"<<endl;
			getline(cin, newStudio);
			cout<<"Enter DVD's runtime:"<<endl;
			getline (cin, newRunTime);
			
			newDVD->SetLibID(newIDNum);
			newDVD->SetCost(newCost);
			newDVD->SetStatus(newStatus);
			newDVD->SetLoanPeriod(newLoanPeriod);
			newDVD->SetTitle(newTitle);
			newDVD->SetCategory(newCategory);
			newDVD->SetReleaseDate(newReleaseDate);
			newDVD->SetRunTime(newRunTime);
			newDVD->SetStudio(newStudio);
			
			libraryItems.push_back(newDVD);
			libraryItemList::incCount();
			break;
		}
	}
}

void libraryItemList::AddItem(libraryItem *temp)
{
	libraryItems.push_back(temp);
}

void libraryItemList::DeleteItem (int libID)
{
	int i;
	bool found = false;
	for(i=0; i<libraryItemList::GetCount(); i++)
	if (libraryItems[i]->GetLibID()==libID)
	{
		
			found = true;
			libraryItems.erase(libraryItems.begin()+i);
			libraryItemList::decCount();
	}

	if (!found)
	{
		cout<<"Item not found." <<endl;   
	}
}
//EDIT
void libraryItemList::ModifyItem (int libID)
{
	int i;
	string newStatus;
	bool found = false;
	for(i=0; i<libraryItemList::GetCount(); i++)
	{
		if (libraryItems[i]->GetLibID()==libID)
		{
			found = true;
			cout<<"Enter new status: Available, Checked out, Damaged, Lost" <<endl;
			cin.ignore();
			getline (cin, newStatus);
			libraryItems[i]->SetStatus(newStatus);
		}
	}
	if (!found)
	{
		cout<<"Item not found." <<endl;   
	}
}
			
			
int libraryItemList::FindItem (int libID, libraryItemList &libraryItemslist)
{
	int i;
	bool found = false;
	for(i=0; i<libraryItemList::GetCount(); i++)
	{
		if (libraryItems[i]->GetLibID()==libID)
		{
			found=true;
			return libraryItems[i]->GetLibID();
		}
		
	}
	if (!found)
	{
		cout<<"Item not found." <<endl;   
	}
	
	
}


libraryItem* libraryItemList::FindItem(int libID)
{
	
	for(int i=0; i<count; i++)
	{
		if (libraryItems[i]->GetLibID() == libID) return libraryItems[i];
	}
	return NULL;
}
	

void libraryItemList::PrintAll()
{
	int i;
	for(i=0; i<libraryItemList::GetCount(); i++)
	{
			libraryItems[i]->Print();
	}
		
}


void libraryItemList::PrintEntry (int libID)
{
	int i;
	bool found = false;
	for(i=0; i<libraryItemList::GetCount(); i++)
	{
		if (libraryItems[i]->GetLibID()==libID)
		{
			found = true;
			libraryItems[i]->Print();
		}
	}
	if (!found)
	{
		cout<<"Item not found." <<endl;   
	}
}
