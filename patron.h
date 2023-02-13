/*
Author: Connor Pursell
Date: 3/19/21
*/
#include <iostream>
#include <string>

using namespace std;

class patron
{
	private:
	string name;
	int IDNum;
	float fineBalance;
	int itemsOut;

	
	public:
	patron();
	patron(string name, int IDNum, float fineBalance, int itemsOut);
	

	string GetName ();
	int GetIDNum();
	float GetFineBalance();
	int GetItemsOut();
	
	void SetName(string name);
	void SetIDNum (int IDNum);
	void SetFineBalance (float fineBalance);
	void SetItemsOut (int itemsOut);
	
};