/*
Author: Connor Pursell
Date: 4/17/21
*/

#include <iostream>
#include <string>
#include "audioCD.h"


using namespace std;
	
	
	audioCD::audioCD ()
	{
		artist = "none";
		title = "none";
		numTracks = 0;
		releaseDate = "00/00/0000";
		genre = "none";
	}
	
	audioCD::audioCD(int libID, float cost, string status, string loanPeriod, string artist, string title, int numTracks, string releaseDate, string genre)
	{
		this->libID = libID;
		this->cost =cost;
		this->status = status;
		this->loanPeriod = loanPeriod;
		this->artist = artist;
		this->title = title;
		this->numTracks = numTracks;
		this-> releaseDate = releaseDate;
		this->genre = genre;
	}
	void audioCD::SetArtist (string artist) {this->artist = artist;}
	void audioCD::SetTitle(string title) {this->title = title;}
	void audioCD::SetNumTracks(int numTracks){this->numTracks = numTracks;}
	void audioCD::SetReleaseDate(string releaseDate) {this->releaseDate = releaseDate;}
	void audioCD::SetGenre(string genre){this->genre = genre;}
	void audioCD::Print()
	{
			libraryItem::Print();
			cout<<"Title: " <<title<<endl;
			cout<<"Artist: " <<artist<<endl;
			cout<<"Number of tracks: " <<numTracks<<endl;
			cout<<"Genre: " <<genre<<endl;
			cout<<"Release date:" <<releaseDate<<endl;
	}
	
	string audioCD::GetArtist(){return artist;}
	string audioCD::GetTitle() {return title;}
	int audioCD::GetNumTracks() {return numTracks;}
	string audioCD::GetReleaseDate() {return releaseDate;}
	string audioCD::GetGenre() {return genre;}
	