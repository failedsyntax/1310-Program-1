#ifndef storage_h
#define storage_h

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

        Playlist* getPlaylist(int index);

        void displayPlaylists();

        void printPlaylists() const;

        void printSpecificPlaylist(int playlistNum);

        bool loadFromFile(const char* fileName);

};

#endif