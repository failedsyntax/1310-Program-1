/*
    Title: Song.h
    Purpose: Header for song.cpp, has the variables for the songs.
*/
#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


class Song{
    private:
        string title;
        string artist;
        string duration;
        int year;
        double rating;

    public:
        //constructor
        Song();
        //Overloaded constructor
        Song(string, string, string, int, double);
        //Destructor
        ~Song();

        //accessor
        string getTitle() const;
        string getArtist() const;
        string getDuration() const;
        int getYear() const;
        double getRating() const;
        
        //mutators
        void setTitle(string);
        void setArtist(string);
        void setDuration(string);
        void setYear(int);
        void setRating(double);
};
#endif