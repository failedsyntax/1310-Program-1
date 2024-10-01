#ifndef PLAYLIST.H
#define PLAYLIST.H
#include "song.h"

class Playlist{
    private:
        Song* songs;
        int maxSize;
        int currentSize;
    public:

    //Constructor
    Playlist(int size);

    //Destructor
    ~Playlist();

    void addSong(const Song& song);

    void removeSong(int index);

    void printSong() const;
};

#endif