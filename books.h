/*
Author: Connor Pursell
Date: 3/19/21
*/
#ifndef BOOKS_H
#define BOOKS_H
#include <iostream>
#include <string>
#include <vector>
#include "book.h"

using namespace std;

class booksList
{
	private:
	int count = 0;
	vector <book> books;
	
	public:
	booksList();
	vector<book> GetBooks();
	void incCount();
	void decCount();
	int GetCount();
	
	void LoadBooks(booksList &bookslist);
	void StoreBooks(booksList &bookslist);
	
	void AddBook (book newBook);
	void DeleteBook (int libIDNum);
	void ModifyBook (int libIDNum);
	int FindBook (int libIDNum, booksList &bookslist);
	void PrintAll();
	void PrintEntry (int libIDNum);
	
};
#endif 