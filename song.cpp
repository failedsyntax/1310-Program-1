#include "song.h"

//constructor
Song::Song(){
    title = "";
    artist = "";
    duration = "";
    year = 0;
    rating = 0.0;
}

//Overloaded Constructor
Song::Song(string t, string a, string dr, int y, double r){
    title = t;
    artist = a;
    duration = dr;

    year = y;
    rating = r;
}

// Song destructor
Song::~Song() {}

//Accessors
string Song::getTitle() const{
    return title;
}

string Song::getArtist() const{
    return artist;
}

string Song::getDuration() const{
    return duration;
}

int Song::getYear() const{
    return year;
}

double Song::getRating() const{
    return rating;
}

//Mutators

void Song::setTitle(string t){
    title = t;
}

void Song::setArtist(string a){
    artist = a;
}

void Song::setDuration(string dr){
    duration = dr;
}

void Song::setYear(int y){
    year = y;
}

void Song::setRating(double r){
    if (r <= 5 && r >= 0){
        rating = r;
    }
    else{
        cout << "Please enter a rating between 0 and 5." << endl;
    }
}
