/*
Author: Connor Pursell
Date: 3/19/21
*/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "menus.h"

using namespace std;


int main()
{
	bool exit=false;
	int option;
	do
	{
		cout<<endl <<"Library Menu" <<endl <<endl;
		cout<<"Choose menu: 1) Patron 2)Library Item 3)Loan 4)Exit" <<endl;
		cin>>option;  
		while (option != 1 && option != 2 && option != 3 && option != 4)      
		{
			cout<<"Please select valid option 1 or 2 or 3: 1)Patron 2)Library Item 3)Loan 4)Exit"<<endl;
			cin>>option;
		}
	   switch (option)
	   {
		   case 1:
		   {
				PrintPatronMenu();
				break;
		   }
		   
		   case 2:
		   {
			   PrintItemMenu();
			   break;
		   }
		   
		   case 3:
		   {
			   PrintLoanMenu();
			   break;
		   }
		   case 4:
		   {
			   exit=true;
		   }
	   }
	}while (exit==false);
	
	return 0;
}