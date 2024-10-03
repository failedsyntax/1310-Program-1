#include "MusicStorage.h"

MusicStorage::MusicStorage(int size)
{
    maxPlaylists = size;
    currentPlaylists = 0;
    playlists = new Playlist *[maxPlaylists];
}

MusicStorage::~MusicStorage()
{
    for (int i = 0; i < currentPlaylists; ++i)
    {
        delete playlists[i];
    }
    delete[] playlists;
}

int MusicStorage::getPlaylistCount()
{
    return currentPlaylists;
}

// re-wrote by jack
void MusicStorage::addPlaylist(Playlist *newPlaylist)
{
    if (currentPlaylists == maxPlaylists)
    {
        cout << "Max playlist count reached! Increasing.." << endl;
        cout << "Current PL: " << currentPlaylists << " | " << "Max PL: " << maxPlaylists << endl;
        // Automatically increase array size & move over playlists
        maxPlaylists * 2;
        cout << "new max: " << maxPlaylists << endl;
        Playlist **updatedPlaylists = new Playlist *[maxPlaylists];

        for (int i = 0; i < currentPlaylists; i++)
        { // Transfer existing playlists
            updatedPlaylists[i] = playlists[i];
        };

        // Release old playlist and update
        playlists[0]->printSong();
        delete[] playlists;

        playlists = updatedPlaylists;
        playlists[0]->printSong();
    };

    playlists[currentPlaylists++] = newPlaylist;
    cout << "Updated Current: " << currentPlaylists << ", Max: " << maxPlaylists << endl
         << endl;
}

void MusicStorage::removePlaylist(int index)
{
    if (index < 0 || index >= currentPlaylists)
    {
        cout << "Please enter a valid playlist (index)" << endl;
        return;
    }

    for (int i = index; i < currentPlaylists - 1; ++i)
    {
        playlists[i] = playlists[i + 1];
    };
    --currentPlaylists;

    if (currentPlaylists < maxPlaylists)
    {
        maxPlaylists--;
        Playlist **updatedPlaylist = new Playlist *[maxPlaylists];

        // copy data over
        for (int i = 0; i < currentPlaylists; ++i)
        {
            updatedPlaylist[i] = playlists[i];
        };

        // Release old playlist and update
        playlists[0]->printSong();
        updatedPlaylist[0]->printSong();

        delete[] playlists;
        playlists = updatedPlaylist;
    }
}

Playlist *MusicStorage::getPlaylist(int index)
{
    if (index <= currentPlaylists)
    {
        return playlists[index-1];
    }
    else
    {
        cout << "Playlist selection is out of bounds!" << endl;
        return nullptr;
    }
}

void MusicStorage::displayPlaylists()
{
    for (int i = 0; i < currentPlaylists; ++i)
    {
        cout << setw(15) << "Playlist " << (i + 1) << endl;
    };
}

void MusicStorage::printPlaylists() const
{
    for (int i = 0; i < currentPlaylists; ++i)
    {
        cout << "Playlist " << (i + 1) << ": " << endl;
        playlists[i]->printSong();
    }
}

void MusicStorage::printSpecificPlaylist(int playlistNum)
{
    cout << playlists[playlistNum];
    cout << "Printing playlist " << playlistNum + 1 << ":" << endl;
    playlists[playlistNum]->printSong();
}

bool MusicStorage::saveToFile(int index, string fileName)
{
    if (index <= currentPlaylists)
    {
        ofstream saveFile;

        Playlist *SelectedPlaylist = playlists[index];
        cout << "Count: " << SelectedPlaylist->getSongCount();
        for (int i = 0; i < SelectedPlaylist->getSongCount(); i++)
        {
            cout << i << " | ";
            SelectedPlaylist[i].printSong();
        }
    };

    return true;
}

bool MusicStorage::loadFromFile(const char *filename)
{
    string title;
    string artist;
    string duration;
    string tmp;
    int year = 0;
    double rating = 0;

    ifstream file(filename);
    if (!file)
    {
        cout << "Unable to open file." << endl;
        return false;
    }

    cout << "File opened successfully." << endl;

    Playlist *newPlaylist = new Playlist(1);

    // cin.ignore();

    while (getline(file, title, '#'))
    {
        getline(file, artist, '#');
        getline(file, duration, '#');
        getline(file, tmp, '#'); // Year
        year = stoi(tmp);
        getline(file, tmp, '#'); // Rating
        rating = stod(tmp);

        cout << "Title: " << title << ", Artist: " << artist << ", Duration: " << duration << ", Year: " << year << ", Rating: " << rating << endl;
        Song *newSong = new Song(title, artist, duration, year, rating);

        newPlaylist->addSong(newSong);

        title.clear();
        artist.clear();
        duration.clear();
        tmp.clear();

        year = 0;
        rating = 0.0;
    }

    cout << "Finished reading file." << endl
         << endl;

    addPlaylist(newPlaylist);
    // delete newPlaylist;
    file.close();
    return true;
}
