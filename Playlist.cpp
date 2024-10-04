#include "Playlist.h"
#include <iomanip>

Playlist::Playlist(int size){
    maxSize = size;
    currentSize = 0;

    
    songs = new Song* [maxSize];
}

// Playlist destructor
Playlist::~Playlist() {
    cout << "\nDestroying Playlist" << endl;
    for (int i = 0; i < currentSize; ++i) {
        delete songs[i];
    }
    delete[] songs;
    cout << "Playlist destroyed" << endl;
}



void Playlist::addSong(Song* song) {
    if (currentSize >= maxSize) {

        // Song limit reached, expand playlist size
        int updatedMax = maxSize * 2;
        Song** newSongList = new Song*[updatedMax];

        // Copy existing songs to the new array
        for (int i = 0; i < currentSize; ++i) {
            newSongList[i] = songs[i];
        }

        // Release old array and update to new
        delete[] songs;
        songs = newSongList;
        maxSize = updatedMax;
    }
    songs[currentSize++] = song; // Allocate new Song object
    cout << "Added song: " << songs[currentSize - 1]->getTitle() << endl << endl;
}

void Playlist::removeSong(int index){
    if (index < 0 || index >= currentSize){
        cout << "Not a valid entry." << endl;
        return;
    }
    
    delete songs[index];

    for (int i = index; i < currentSize - 1; ++i){
        songs[i] = songs[i + 1];
    }
    songs[--currentSize] = nullptr;
    --currentSize;
}

void Playlist::printSong() const{ // finish this
    if (currentSize == 0){
        cout << "There is nothing in the Playlist." << endl;
        return;
    } else {
        for (int i = 0; i < currentSize; i++) {
            cout << setw(17) << "Song #" << (i + 1) << ":" << endl;
            cout << setw(25) << "Title: " << songs[i]->getTitle() << endl;
            cout << setw(25) << "Artist: " << songs[i]->getArtist() << endl;
            cout << setw(25) << "Duration: " << songs[i]->getDuration() << endl;
            cout << setw(25) << "Year: " << songs[i]->getYear() << endl;
            cout << setw(25) << "Rating: " << songs[i]->getRating() << endl;
        }
    }
}

int Playlist::getSongCount() {
    return currentSize;
}