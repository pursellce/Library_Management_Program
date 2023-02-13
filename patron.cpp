/*
Author: Connor Pursell
Date: 3/19/21
*/
#include <iostream>
#include <string>
#include "patron.h"

using namespace std;

	patron::patron()
	{
		name = "none";
		IDNum = 0;
		fineBalance = 0.00;
		itemsOut = 0;
	}
	
	patron::patron(string name, int IDNum, float fineBalance, int itemsOut)
	{
		this->name = name;
		this->IDNum = IDNum;
		this->fineBalance = fineBalance;
		this->itemsOut = itemsOut;
	}
	

	
	string patron::GetName () {return name;}
	int patron::GetIDNum() {return IDNum;}
	float patron::GetFineBalance() {return fineBalance;}
	int patron::GetItemsOut() {return itemsOut;}
	
	
	void patron::SetName(string name)
	{
		this->name = name;
	}
	void patron::SetIDNum (int IDNum)
	{
		this->IDNum = IDNum;
	}
	void patron::SetFineBalance (float fineBalance)
	{
		this->fineBalance = fineBalance;
	}
	void patron::SetItemsOut (int booksOut)
	{
		this->itemsOut = itemsOut;
	}
	
	
	
	
	
	
	
	
	
	