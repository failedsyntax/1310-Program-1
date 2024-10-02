#include "MusicStorage.h"

MusicStorage::MusicStorage(int size) : maxPlaylists(size), currentPlaylists(0) {
    playlists = new Playlist*[maxPlaylists];
}

MusicStorage::~MusicStorage() {
    for (int i = 0; i < currentPlaylists; ++i) {
        delete playlists[i];
    }
    delete[] playlists;
}

int MusicStorage::getPlaylistCount() {
    return currentPlaylists;
}

// re-wrote by jack
void MusicStorage::addPlaylist(Playlist* newPlaylist){
    if (currentPlaylists == maxPlaylists) {
        cout << "Max playlist count reached! Increasing.." << endl;

        // Automatically increase array size & move over playlists
        maxPlaylists++;
        Playlist** updatedPlaylists = new Playlist* [maxPlaylists];

        for (int i = 0; i < currentPlaylists; i++) { // Transfer existing playlists
            updatedPlaylists[i] = playlists[i];
        };

        // Release old playlist and update
        delete [] playlists;
        playlists = updatedPlaylists;
    };

    playlists[currentPlaylists++] = newPlaylist;
    cout << "Updated Playlist" << endl;
}

void MusicStorage::removePlaylist(int index){
    if (index < 0 || index >= currentPlaylists){
        cout << "Please enter a valid playlist (index)" << endl;
        return;
    }

    for (int i = index; i < currentPlaylists - 1; ++i){
        playlists[i] = playlists[i + 1];
    };
    --currentPlaylists;

    if (currentPlaylists < maxPlaylists) {
        maxPlaylists--;
        Playlist** updatedPlaylist = new Playlist* [maxPlaylists];

        // copy data over
        for (int i = 0; i < currentPlaylists; ++i) {
            updatedPlaylist[i] = playlists[i];
        };

        // Release old playlist and update
        delete [] playlists;
        playlists = updatedPlaylist;
    }

}

Playlist* MusicStorage::getPlaylist(int index) {
    if (index <= currentPlaylists) {
        return playlists[index];
    } else {
        cout << "Playlist selection is out of bounds!" << endl;
        return nullptr;
    }
}

void MusicStorage::displayPlaylists() {
    for (int i = 0; i < currentPlaylists; ++i) {
        cout << setw(15) << "Playlist " << (i + 1) << endl;
    };
}

void MusicStorage::printPlaylists() const{
    for (int i = 0; i < currentPlaylists; ++i){
        cout << "Playlist " << (i + 1) << ": " << endl;
        playlists[i]->printSong();
    }
}

void MusicStorage::printSpecificPlaylist(int playlistNum) {
    cout << "Printing playlist " << playlistNum + 1 << ":" << endl;
    playlists[playlistNum]->printSong();
}

bool MusicStorage::saveToFile(int index, string fileName) {
    if (index <= currentPlaylists) {
        ofstream saveFile;

        Playlist* SelectedPlaylist = playlists[index];
        cout << "Count: " << SelectedPlaylist->getSongCount();
        for (int i = 0; i < SelectedPlaylist-> getSongCount(); i++) {
            cout << i << " | "; SelectedPlaylist[i].printSong(); 
        }
    };

    return true;
}

bool MusicStorage::loadFromFile(const char* filename) {
    string title;
    string artist;
    string duration;
    string tmp;
    int year = 0;
    int rating = 0;

    ifstream file(filename);
    if (!file) {
        cout << "Unable to open file." << endl;
        return false;
    }

    cout << "File opened successfully." << endl;

    Playlist* newPlaylist = new Playlist(0);

    while (getline(file >> ws, title, '#')) {
        getline(file, artist, '#');
        getline(file, duration, '#');
        getline(file, tmp, '#'); // Year
        year = stoi(tmp);
        getline(file, tmp, '#'); // Rating
        rating = stoi(tmp);

        cout << "Title: " << title << ", Artist: " << artist << ", Duration: " << duration << ", Year: " << year << ", Rating: " << rating << endl;
        Song newSong = Song(title.c_str(), artist.c_str(), duration.c_str(), year, rating);
        
        newPlaylist->addSong(newSong);

        cout << "Song added to playlist." << endl;

        title.clear();
        artist.clear();
        duration.clear();
        year = 0;
        rating = 0;
        tmp.clear();
    }

    cout << "Finished reading file." << endl;

    addPlaylist(newPlaylist); // Pass the pointer to addPlaylist

    cout << "Playlist added." << endl;

    delete newPlaylist; // Use delete instead of delete[]

    cout << "here2" << endl;

    file.close();
    return true;
}


