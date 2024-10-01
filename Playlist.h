#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "song.h"

class Playlist{
    private:
        Song* songs;
        int maxSize;
        int currentSize;
    public:

    //Constructor | Updated to construct
    Playlist() {
    }; 
    Playlist(int size);

    //Destructor
    ~Playlist();

    void addSong(const Song& song);

    void removeSong(int index);

    void printSong() const;
};

#endif