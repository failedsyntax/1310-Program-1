#include "Playlist.h"

Playlist::Playlist(int size) : maxSize(size), currentSize(0){
    songs = new Song* [maxSize];
}

// Playlist destructor
Playlist::~Playlist() {
    cout << "Destroying Playlist" << endl;
    for (int i = 0; i < currentSize; ++i) {
        cout << "Deleting song " << i << ": " << songs[i]->getTitle() << endl;
        delete songs[i];
    }
    delete[] songs;
    cout << "Playlist destroyed" << endl;
}



void Playlist::addSong(const Song& song) {
    cout << "Current Size: " << currentSize << ", Max Size: " << maxSize << endl;

    if (currentSize >= maxSize) {
        // Song limit reached, expand playlist size
        maxSize = (maxSize == 0) ? 1 : maxSize++;  // Double the size or set to 1 if initially 0
        cout << "Resizing to: " << maxSize << endl;
        Song** newSongList = new Song*[maxSize];

        // Copy existing songs to the new array
        for (int i = 0; i < currentSize; ++i) {
            newSongList[i] = songs[i];
        }

        // Release old array and update to new
        delete[] songs;

        songs = newSongList;

        cout << "Resized successfully. Current Size: " << currentSize << endl;
    }

    songs[currentSize++] = new Song(song); // Allocate new Song object
    cout << "Added song: " << song.getTitle() << endl;
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