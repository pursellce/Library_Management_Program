/*
Author: Connor Pursell
Date: 4/17/21
*/

#include <iostream>
#include <string>
#include "DVD.h"

using namespace std;
	
	
	DVD::DVD()
	{
		title = "none";
		category = "none";
		runTime = "0hr 0min";
		studio = "none";
		releaseDate = "00/00/0000";
	}
	DVD::DVD(int libID, float cost, string status, string loanPeriod, string title, string category, string runTime, string studio, string releaseDate)
	{
		this->libID = libID;
		this->cost = cost;
		this->status = status;
		this->loanPeriod = loanPeriod;
		this->title = title;
		this->category = category;
		this-> runTime = runTime;
		this->studio = studio;
		this->releaseDate = releaseDate;		
	}
	
	void DVD::SetTitle(string title){this->title = title;}
	void DVD::SetCategory (string category){this->category = category;}
	void DVD::SetRunTime( string runTime){this->runTime = runTime;}
	void DVD::SetStudio(string studio){this->studio = studio;}
	void DVD::SetReleaseDate(string releaseDate){this->releaseDate = releaseDate;}
	void DVD::Print()
	{
			cout<<"Title: " <<title<<endl;
			cout<<"Studio: " <<studio<<endl;
			cout<<"Run time: " <<runTime<<endl;
			cout<<"Genre: " <<category<<endl;
			cout<<"Release date:" <<releaseDate<<endl;
	}
	
	
	string DVD::GetTitle(){return title;}
	string DVD::GetCategory(){return category;}
	string DVD::GetRunTime(){return runTime;}
	string DVD::GetStudio(){return studio;}
	string DVD::GetReleaseDate(){return releaseDate;}