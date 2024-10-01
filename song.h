#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


class Song{
    private:
        char* title;
        char* artist;
        char* duration;
        int year;
        int rating;

    public:
        //constructor
        Song();
        //Overloaded constructor
        Song(const char*, const char*, const char*, int, int);
        //Destructor
        ~Song();

        //accessor
        const char* getTitle() const;
        const char* getArtist() const;
        const char* getDuration() const;
        int getYear() const;
        int getRating() const;
        //mutators
        void setTitle(const char*);
        void setArtist(const char*);
        void setDuration(const char*);
        void setYear(int);
        void setRating(int);
};
#endif