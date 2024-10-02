#include "MusicStorage.h"

MusicStorage::MusicStorage(int size) : maxPlaylists(size), currentPlaylists(0) {
    playlists = new Playlist*[maxPlaylists];
}

MusicStorage::~MusicStorage(){
    for (int i = 0; i < currentPlaylists; ++i){
        delete playlists[i];
    }
    delete[] playlists;
    cout << "Released Memory for the Array of pointers" << endl;
}

int MusicStorage::getPlaylistCount() {
    return currentPlaylists;
}

// re-wrote by jack
void MusicStorage::addPlaylist(const Playlist& playlist){
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

    playlists[currentPlaylists++] = new Playlist(playlist);
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

bool MusicStorage::loadFromFile(const char* filename){
    string title;
    string artist;
    string album;
    string line;
    int year = 0;
    int rating = 0;

    ifstream file(filename);
    if (!file){
        cout << "Unable to open file." << endl;
        return false;
    }

    Playlist* newPlaylist = new Playlist(100);

    while (getline(file, line)){
        size_t i = 0;
        char currentChar;
        while(i < line.size() && line[i] != ','){
            title += line[i];
            i++;
        }
        i++;

        while (i < line.size() && line[i] != ','){
            artist += line [i];
            i++;
        }
        i++;

        while (i < line.size() && line [i] != ','){
            album += line[i];
            i++;
        }
        i++;

        while (i < line.size() && line[i]!= ','){
            year = year * 10 + (line[i] - '\0');
            i++;
        }
        i++;

        while (i < line.size()){
            rating = rating * 10 + (line [i] - '\0');
            i++;
        }

        if (year < 0 || year > 2023 || rating < 0 || rating > 4){
            cout << "Cannot enter data: " << line << endl;
            continue;
        }

        Song song (title.data(), artist.data(), album.data(), year, rating);
        newPlaylist->addSong(song);

        title.clear();
        artist.clear();
        album.clear();
        year = 0;
        rating = 0;
    }

    addPlaylist(*newPlaylist);

    delete newPlaylist;

    file.close();
    return true;
}

