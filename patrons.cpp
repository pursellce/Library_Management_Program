/*
Author: Connor Pursell
Date: 3/19/21
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

#include "patrons.h"
#ifndef PATRON_H
#define PATRON_H


using namespace std;



patronsList::patronsList()
{
	count = 0;
}
int patronsList::GetCount() {return count;}
void patronsList::incCount() {count++;}
void patronsList::decCount(){count--;}

vector<patron> patronsList::GetPatrons() {return patrons;};

void patronsList::LoadPatrons(patronsList &patronslist)
{
	
	ifstream fin;
	
	string name, line;
	string filename;
	int IDNum, itemsOut;
	float fineBalance;
	patron temp;
	
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
		str>> IDNum >>name >>itemsOut >>fineBalance;
		temp.SetName(name);
		temp.SetIDNum(IDNum);
		temp.SetItemsOut(itemsOut);
		temp.SetFineBalance(fineBalance);
		patronslist.AddPatron(temp);
		patronslist.incCount();
	}
	
	fin.close();
}
void patronsList::StorePatrons(patronsList &patronslist)
{
	ofstream fout ("patrons.dat");
	
	fout.open("patrons.dat");
	
	for(int i=0; i<patronslist.GetCount(); i++)
	{
		fout<<patrons.at(i).GetIDNum() <<"	"<<patrons.at(i).GetName()<<"	";
		fout<<patrons.at(i).GetItemsOut()<<"	"<<patrons.at(i).GetFineBalance();
	}
	cout<<"Patrons stored."<<endl;
	fout.close();
}



void patronsList::AddPatron(patron NewPatron)
{
	patrons.push_back(NewPatron);
	patronsList::incCount();
}
	
void patronsList::DeletePatron(int IDNum)
{
	unsigned int i;
	bool found = false;
	for(i=0; i<patronsList::GetCount(); i++)
	if (patrons.at(i).GetIDNum()==IDNum)
	{
		
			found = true;
			patrons.erase(patrons.begin()+i);
			patronsList::decCount();
	}

	if (!found)
	{
		cout<<"Patron not found." <<endl;   
	}
}

	
void patronsList::ModifyPatron(int IDNum)
{
	unsigned int i;
	float newFineBalance;
	int newItemsOut;
	char choice;
	bool found = false;
	for(i=0; i<patronsList::GetCount(); i++)
	{
		if (patrons.at(i).GetIDNum()==IDNum)
		{
			found = true;
			cout<<"What do you want to modify? a)Fine Balance b)items Out"<<endl;
			cin>> choice;
			while (choice != 'a' && choice != 'b')      
			{
				cin>>choice;
			}
			switch (choice)
			{
				case 'a':
				{
					cout<<"Enter new fine balance:" <<endl;
					cin>>newFineBalance;
					patrons.at(i).SetFineBalance(newFineBalance);
					break;
				}
				case 'b':
				{
					cout<<"Enter new number of items out:" <<endl;
					cin>>newItemsOut;
					patrons.at(i).SetItemsOut(newItemsOut);
					break;		
				}					
			}
			break;
		}
	}
			
	if (!found)
	{
		cout<<"Patron not found." <<endl;   
	}
}

void patronsList::UpdateFine(int IDNum, float cost)
{
	unsigned int i;
	float newFineBalance;
	bool found = false;
	for(i=0; i<patronsList::GetCount(); i++)
	{
		if (patrons.at(i).GetIDNum()==IDNum)
		{
			newFineBalance= patrons.at(i).GetFineBalance()+cost;
			patrons.at(i).SetFineBalance(newFineBalance);
		}
	}
	if (!found)
	{
		cout<<"Patron not found." <<endl;   
	}
}

void patronsList::UpdateItemsOut(int IDNum)
{
	unsigned int i;
	bool found = false;
	for(i=0; i<patronsList::GetCount(); i++)
	{
		if (patrons.at(i).GetIDNum()==IDNum)
		{
			patrons.at(i).SetItemsOut(patrons.at(i).GetItemsOut()-1);
		}
	}
	if (!found)
	{
		cout<<"Patron not found." <<endl;   
	}
	
}

int patronsList::FindPatron(int IDNum, patronsList &patronsList)
{
	unsigned int i;
	bool found = false;
	for(i=0; i<patronsList::GetCount(); i++)
	{
		if (patronsList.patrons.at(i).GetIDNum()==IDNum)
		{
			found=true;
			return patronsList.patrons.at(i).GetIDNum();
		}
	}
	if (!found)
	{
		cout<<"Patron not found." <<endl;   
	}
	
	
}
void patronsList::PrintAll()
{
	cout<< fixed<<showpoint;
	cout.precision(2);
	
	unsigned int i;
	for(i=0; i<patronsList::GetCount(); i++)
	{
			cout<<"Name: " <<patrons.at(i).GetName()<<endl;
			cout<<"ID number: "<<patrons.at(i).GetIDNum()<<endl;
			cout<<"Fine balance: $"<<patrons.at(i).GetFineBalance()<<endl;
			cout<<"patrons out: " <<patrons.at(i).GetItemsOut()<<endl<<endl;
	}
		
}
void patronsList::PrintEntry(int IDNum)
{
	cout<< fixed<<showpoint;
	cout.precision(2);
	unsigned int i;
	bool found = false;
	for(i=0; i<patronsList::GetCount(); i++)
	{
		if (patrons.at(i).GetIDNum()==IDNum)
		{
			found = true;
			cout<<"Name: " <<patrons.at(i).GetName()<<endl;
			cout<<"ID number: "<<patrons.at(i).GetIDNum()<<endl;
			cout<<"Fine balance: $"<<patrons.at(i).GetFineBalance()<<endl;
			cout<<"patrons out: " <<patrons.at(i).GetItemsOut()<<endl;
		}
	}
	
	if (!found)
	{
		cout<<"Patron not found." <<endl;
	}
	
}

#endif