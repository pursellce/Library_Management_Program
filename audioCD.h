/*
Author: Connor Pursell
Date: 4/17/21
Assignment: Homework Project 4
Course: CSCE1040.003
*/
#ifndef AUDIOCD_H
#define AUDIOCD_H
#include <iostream>
#include <string>
#include "libraryItem.h"

using namespace std;

class audioCD : public libraryItem
{
	protected:
	string artist;
	string title;
	int numTracks;
	string releaseDate;
	string genre;
	
	public:
	
	audioCD ();
	audioCD(int libID, float cost, string status, string loanPeriod,string artist, string title, int numTracks, string releaseDate, string genre);
	void SetArtist (string artist);
	void SetTitle(string title);
	void SetNumTracks(int numTracks);
	void SetReleaseDate(string releaseDate);
	void SetGenre(string genre);
	void Print();
	
	string GetArtist();
	string GetTitle();
	int GetNumTracks();
	string GetReleaseDate();
	string GetGenre();
	
	
};

#endif