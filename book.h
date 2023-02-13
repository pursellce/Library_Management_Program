/*
Author: Connor Pursell
Date: 4/17/21
*/
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include "libraryItem.h"

using namespace std;

class book : public libraryItem
{
	protected:
	string author;
	string title;
	int ISBNNum;
	string category;	
	
	public:
	book();
	book(int libID, float cost, string status, string loanPeriod, string author, string title, int ISBNNum, string category);
	
	string GetAuthor();
	string GetTitle();
	int GetISBNNum();
	string GetCategory();

	void Print ();
	void SetAuthor(string author);
	void SetTitle(string title);
	void SetISBNNum(int ISBNNum);
	void SetCategory (string category);


};

#endif