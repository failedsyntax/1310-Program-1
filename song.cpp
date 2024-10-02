#include "song.h"

//constructor
Song::Song(){
    title = new char[1];
    title[0] = '\0';
    artist = new char[1];
    artist[0] = '\0';
    duration = new char [1];
    duration[0] = '\0';
    year = 0;
    rating = 0;
}

//Overloaded Constructor
Song::Song(const char* t, const char* a, const char* ab, int y, int r){
    title = new char[strlen(t) + 1];
    strcpy(title, t);

    artist = new char[strlen(a) + 1];
    strcpy(artist, a);

    duration = new char[strlen(ab) + 1];
    strcpy(duration, ab);

    year = y;
    rating = r;
}

// Song destructor
Song::~Song() {
    cout << "Destroying Song: " << title << endl;
    delete[] title;
    delete[] artist;
    delete[] duration;
    cout << "Song destroyed" << endl;
}



//Accessors

const char* Song::getTitle() const{
    return title;
}

const char* Song::getArtist() const{
    return artist;
}

const char* Song::getDuration() const{
    return duration;
}

int Song::getYear() const{
    return year;
}

int Song::getRating() const{
    return rating;
}

//Mutators

void Song::setTitle(const char* t){
    delete[] title;
    title = new char [strlen(t) + 1];
    strcpy(title, t);
}

void Song::setArtist(const char* a){
    delete[] artist;
    artist = new char[strlen(a) + 1];
    strcpy(artist, a);
}

void Song::setDuration(const char* ab){
    delete [] duration;
    duration = new char [strlen(ab) + 1];
    strcpy(duration, ab);
}

void Song::setYear(int y){
    year = y;
}

void Song::setRating(int r){
    if (r <= 4 && r >= 0){
        rating = r;
    }
    else{
        cout << "Please enter a rating between 0 and 4." << endl;
    }
}
