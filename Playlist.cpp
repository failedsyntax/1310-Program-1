#include "Playlist.h"

Playlist::Playlist(int size) : maxSize(size), currentSize(0){
    songs = new Song[maxSize];
}

Playlist::~Playlist(){
    delete[] songs;
}

void Playlist::addSong(const Song& song){
    cout << currentSize << " " << maxSize << endl;
    if (currentSize >= maxSize){
        cout << "Cannot add more songs." << endl;
        return;
    }
    else {
        songs[currentSize++] = song;
    }
}

void Playlist::removeSong(int index){
    if (index < 0 || index >= currentSize){
        cout << "Not a valid entry." << endl;
        return;
    }
    
    for (int i = index; i < currentSize - 1; ++i){
        songs[i] = songs[i + 1];
    }
    --currentSize;
}

void Playlist::printSong() const{
    if (currentSize == 0){
        cout << "There is nothing in the Playlist." << endl;
        return;
    }
}

int Playlist::getSongCount() {
    return currentSize;
}