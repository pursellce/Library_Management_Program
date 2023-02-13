/*
Author: Connor Pursell
Date: 3/19/21
*/
#include <iostream>
#include <string>
#ifndef LIBRARYITEMS_H
#define LIBRARYITEMS_H
#include <vector>
#include "libraryItem.h"
#include "book.h"
#include "audioCD.h"
#include "DVD.h"

using namespace std;

class libraryItemList
{
	private:
	int count = 0;
	vector <libraryItem*> libraryItems;
	
	public:
	libraryItemList();
	vector<libraryItem*> GetItems();
	void incCount();
	void decCount();
	int GetCount();
	
	void LoadItems(libraryItemList &libraryItemslist);
	void StoreItems(libraryItemList &libraryItemslist);
	
	void AddItem ();
	void AddItem(libraryItem *temp);
	void DeleteItem (int libIDNum);
	void ModifyItem (int libIDNum);
	int FindItem (int libIDNum, libraryItemList &libraryItemslist);
	libraryItem* FindItem(int libIDNum);
	void PrintAll();
	void PrintEntry (int libIDNum);

	
	
	
};
#endif