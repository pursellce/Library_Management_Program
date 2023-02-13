/*
Author: Connor Pursell
Date: 3/19/21
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "books.h"
#ifndef BOOK_H
#define BOOK_H

using namespace std;


booksList::booksList()
{
	count = 0;
}

int booksList::GetCount() {return count;}
void booksList::incCount() {count++;}
void booksList::decCount(){count--;}
vector<book> booksList:: GetBooks() {return books;};







void booksList::LoadBooks(booksList &bookslist)
{
	
	ifstream fin;
	
	string author, title, line;
	string filename;
	int ISBNNum, libIDNum;
	float cost;
	string status;
	book temp;
	
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
		str>> libIDNum >>title >>author >>ISBNNum >>cost >>status;
		temp.SetAuthor(author);
		temp.SetTitle(title);
		temp.SetStatus(status);
		temp.SetISBNNum(ISBNNum);
		temp.SetLibIDNum(libIDNum);
		temp.SetCost(cost);
		bookslist.AddBook(temp);
		bookslist.incCount();
	}
	
	fin.close();
}
void booksList::StoreBooks(booksList &bookslist)
{
	ofstream fout ("books.dat");
	fout.open("books.dat");
	
	for(int i=0; i<bookslist.GetCount(); i++)
	{
		fout<<books.at(i).GetLibIDNum() <<"	"<<books.at(i).GetTitle()<<"	";
		fout<<books.at(i).GetAuthor()<<"	"<<books.at(i).GetISBNNum()<<"	";
		fout<<books.at(i).GetCost()<<"	"<<books.at(i).GetStatus()<<endl;
	}
	cout<<"Books stored."<<endl;
	fout.close();
}


void booksList::AddBook (book newBook)
{
	books.push_back(newBook);
	booksList::incCount();
}

void booksList::DeleteBook (int libIDNum)
{
	unsigned int i;
	bool found = false;
	for(i=0; i<booksList::GetCount(); i++)
	if (books.at(i).GetLibIDNum()==libIDNum)
	{
		
			found = true;
			books.erase(books.begin()+i);
			booksList::decCount();
	}

	if (!found)
	{
		cout<<"Book not found." <<endl;   
	}
}

void booksList::ModifyBook (int libIDNum)
{
	unsigned int i;
	string newStatus;
	bool found = false;
	for(i=0; i<booksList::GetCount(); i++)
	{
		if (books.at(i).GetLibIDNum()==libIDNum)
		{
			found = true;
			cout<<"Enter new status: Available, Checked out, Damaged" <<endl;
			cin.ignore();
			getline (cin, newStatus);
			books.at(i).SetStatus(newStatus);
		}
	}
	if (!found)
	{
		cout<<"Book not found." <<endl;   
	}
}
			
			
int booksList::FindBook (int libIDNum, booksList &bookslist)
{
	unsigned int i;
	bool found = false;
	for(i=0; i<booksList::GetCount(); i++)
	{
		if (books.at(i).GetLibIDNum()==libIDNum)
		{
			found=true;
			return books.at(i).GetLibIDNum();
		}
		
	}
	if (!found)
	{
		cout<<"Book not found." <<endl;   
	}
	
	
}



void booksList::PrintAll()
{
	unsigned int i;
	for(i=0; i<booksList::GetCount(); i++)
	{
			cout<<"Title: " <<books.at(i).GetTitle()<<endl;
			cout<<"Author: " <<books.at(i).GetAuthor()<<endl;
			cout<<"ISBN: " <<books.at(i).GetISBNNum()<<endl;
			cout<<"Libaray ID number: "<<books.at(i).GetLibIDNum()<<endl;
			cout<<"Cost: $"<<books.at(i).GetCost()<<endl;
			cout<<"Status: " <<books.at(i).GetStatus()<<endl<<endl;
	}
		
}

void booksList::PrintEntry (int libIDNum)
{
	unsigned int i;
	bool found = false;
	for(i=0; i<booksList::GetCount(); i++)
	{
		if (books.at(i).GetLibIDNum()==libIDNum)
		{
			found = true;
			cout<<"Title: " <<books.at(i).GetTitle()<<endl;
			cout<<"Author: " <<books.at(i).GetAuthor()<<endl;
			cout<<"ISBN: " <<books.at(i).GetISBNNum()<<endl;
			cout<<"Libaray ID number: "<<books.at(i).GetLibIDNum()<<endl;
			cout<<"Cost: $"<<books.at(i).GetCost()<<endl;
			cout<<"Status: " <<books.at(i).GetStatus()<<endl;
		}
	}
	if (!found)
	{
		cout<<"Book not found." <<endl;   
	}
}







#endif