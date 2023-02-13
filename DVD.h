/*
Author: Connor Pursell
Date: 4/17/21
*/
#ifndef DVD_H
#define DVD_H
#include <iostream>
#include <string>
#include "libraryItem.h"

using namespace std;

class DVD : public libraryItem
{
	protected:
	string title;
	string category;
	string runTime;
	string studio;
	string releaseDate;
	
	public:
	
	DVD();
	DVD(int libID, float cost, string status, string loanPeriod, string title, string category, string runtime, string studio, string releaseDate);
	
	void SetTitle(string title);
	void SetCategory (string category);
	void SetRunTime( string runTime);
	void SetStudio(string studio);
	void SetReleaseDate( string releaseDate);
	void Print();
	
	string GetTitle();
	string GetCategory();
	string GetRunTime();
	string GetStudio();
	string GetReleaseDate();
	
};
#endif