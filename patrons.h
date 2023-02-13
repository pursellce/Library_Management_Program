/*
Author: Connor Pursell
Date: 3/19/21
*/
#ifndef PATRONS_H
#define PATRONS_H
#include <iostream>
#include <string>
#include <vector>
#include<iterator>
#include "patron.h"

using namespace std;

class patronsList
{
	private:
	int count;
	vector<patron> patrons;
	
	public:
	
	patronsList();
	vector<patron> GetPatrons();
	void incCount();
	void decCount();
	int GetCount();
	
	void StorePatrons(patronsList &patronslist);
	void LoadPatrons (patronsList &patronslist);
	
	void AddPatron(patron NewPatron);
	void DeletePatron(int IDNum);
	void ModifyPatron(int IDNum);
	void UpdateFine(int IDNum, float cost);
	void UpdateItemsOut(int IDNum);
	int FindPatron(int IDNum, patronsList &patronsList);
	void PrintAll();
	void PrintEntry(int IDNum);
	
};
#endif