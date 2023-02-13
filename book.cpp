/*
Author: Connor Pursell
Date: 4/17/21
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "book.h"

using namespace std;

	book::book()
	{
		author = "none";
		title = "none";
		ISBNNum = 0;
		category = "none";
		
	}
	book::book(int libID, float cost, string status, string loanPeriod, string author, string title, int ISBNNum, string category)

	{
		this->libID = libID;
		this->cost = cost;
		this->status = status;
		this-> loanPeriod =  loanPeriod;
		this->author = author;
		this->title = title;
		this->ISBNNum = ISBNNum;
		this->category = category;
	}
	
	string book::GetAuthor(){return author;}
	string book::GetTitle(){return title;}
	int book::GetISBNNum(){return ISBNNum;}
	string book::GetCategory(){return category;}

	void book::Print()
	{
			libraryItem::Print();
			cout<<"Title: " <<title<<endl;
			cout<<"Author: " <<author<<endl;
			cout<<"ISBN: " <<ISBNNum<<endl;
			cout<<"Genre: " <<category<<endl;
	}
	void book::SetAuthor(string author){this->author = author;}
	void book::SetTitle(string title){this->title = title;}
	void book::SetISBNNum(int ISBNNum){this-> ISBNNum = ISBNNum;}
	void book::SetCategory (string category){this->category = category;}