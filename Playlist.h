#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "song.h"

class Playlist{
    private:
        Song** songs;
        int maxSize;
        int currentSize;
    public:

    //Constructor | Updated to construct
    Playlist() : songs(nullptr), maxSize(0), currentSize(0) {}; 
    Playlist(int size);

    //Destructor
    ~Playlist();

    void addSong(Song* song);

    void removeSong(int index);

    void printSong() const;

    int getSongCount();

    Song** GetSongs();
};

#endif