#ifndef STORAGE.H
#define STORAGE.H

#include <iostream>
#include <data.cpp>
using namespace std;

class musicLibrary{
    
    private:
        musicLibrary** musicPTR;
        int numSongs;
        int songCount;

    musicLibrary();

    musicLibrary(musicLibrary** mp, int songs, int count);
    

    ~musicLibrary();

    void printDisplay(musicLibrary**);

    
    

};

#endif