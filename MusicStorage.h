#ifndef storage_h
#define storage_h

/*
    Title: MusicStorage.h
    Purpose: Header for MusicStorage.cpp
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

        Playlist* getPlaylist(int index);

        void addPlaylist(Playlist* newPlaylist);
        void removePlaylist(int index);
        void displayPlaylists();
        void printPlaylists() const;
        void printSpecificPlaylist(int playlistNum);

        bool loadFromFile(const char* fileName);
        bool saveToFile(int index, string FileName);

        int getPlaylistCount();

};

#endif