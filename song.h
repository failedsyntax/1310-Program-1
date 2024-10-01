#ifndef SONG.H
#define SONG.H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


class Song{
    private:
        char* title;
        char* artist;
        char* album;
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
        const char* getAlbum() const;
        int getYear() const;
        int getRating() const;
        //mutators
        void setTitle(const char*);
        void setArtist(const char*);
        void setAlbum(const char*);
        void setYear(int);
        void setRating(int);
};
#endif