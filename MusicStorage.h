#ifndef storage.h
#define storage.h

/*
Pointer to an array of pointers to the data.
 Data stored is the data class.
o Examples: parking lot, toy box, galaxy (holds stars).
o Requirements: be able to read items from a file, be able to print the contents
to the screen
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Playlist.h"

class MusicStorage{
    private:
        Playlist** playlists;
        int maxPlaylists;
        int currentPlaylists;
    public:
        MusicStorage(int size);
        ~MusicStorage();

        void addPlaylist(const Playlist& playlist);

        void removePlaylist(int index);

        void printPlaylist() const;

        bool loadFromFile(const char* filename);

};

#endif