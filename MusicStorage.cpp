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

void MusicStorage::addPlaylist(const Playlist& playlist){
    if (currentPlaylists < maxPlaylists){
        playlists[currentPlaylists++] = new Playlist(playlist);
    }
    else {
        cout << "No more Playlists can be added." << endl;
    }
}

void MusicStorage::removePlaylist(int index){
    if (index < 0 || index >= currentPlaylists){
        cout << "Please enter the correct index" << endl;
        return;
    }
    delete playlists[index];
    for (int i = index; i < currentPlaylists - 1; ++i){
        playlists[i] = playlists[i + 1];
    }

    --currentPlaylists;
}

Playlist* MusicStorage::getPlaylist(int index) {
    if (index <= maxPlaylists) {
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

