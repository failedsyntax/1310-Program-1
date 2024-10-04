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
        // Automatically increase array size & move over playlists
        maxPlaylists * 2;
        Playlist **updatedPlaylists = new Playlist *[maxPlaylists];

        for (int i = 0; i < currentPlaylists; i++)
        { // Transfer existing playlists
            updatedPlaylists[i] = playlists[i];
        };

        // Release old playlist and update
        delete[] playlists;

        playlists = updatedPlaylists;
    };

    playlists[currentPlaylists++] = newPlaylist;
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

        delete[] playlists;
        playlists = updatedPlaylist;
    }

    cout << "Successfully deleted Playlist " << (index + 1) << endl << endl;
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
        cout << setw(1) <<(i + 1) << ". ";
        cout << setw(8) << "Playlist " << (i + 1) << endl;
        playlists[i]->printSong();
        cout << "----------------------------------------" << endl << endl;
    };
}

void MusicStorage::printPlaylists() const
{
    for (int i = 0; i < currentPlaylists; ++i)
    {
        cout << (i + 1) << ".   Playlist " << (i + 1) << endl;
    }
}

void MusicStorage::printSpecificPlaylist(int playlistNum)
{
    cout << endl << endl << "Printing playlist " << playlistNum + 1 << ":" << endl;
    playlists[playlistNum]->printSong();
}

bool MusicStorage::saveToFile(int index, string fileName)
{
    if (index < 0 || index >= currentPlaylists) {
        cout << "Index is out of bounds!" << endl;
        return false;
    }

    ofstream saveFile;
    saveFile.open(fileName);

    if (!saveFile.is_open()) {
        cout << "Couldn't open file to export!" << endl;
        return false;
    }

    Playlist *SelectedPlaylist = playlists[index];
    Song** PlaylistSongs = SelectedPlaylist->GetSongs();

    cout << "Found " << SelectedPlaylist->getSongCount();
    cout << " songs to export!" << endl << endl;
    for (int i = 0; i < SelectedPlaylist->getSongCount(); i++)
    {
        saveFile << PlaylistSongs[i]->getTitle() << "#";
        saveFile << PlaylistSongs[i]->getArtist() << "#";
        saveFile << PlaylistSongs[i]->getDuration() << "#";
        saveFile << PlaylistSongs[i]->getYear() << "#";
        saveFile << PlaylistSongs[i]->getRating() << "\n";
    }

    saveFile.close();

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

    Playlist *newPlaylist = new Playlist(1);

    while (getline(file, title, '#'))
    {
        getline(file, artist, '#');
        getline(file, duration, '#');
        getline(file, tmp, '#'); // Year
        year = stoi(tmp);
        getline(file, tmp); // Rating
        rating = stod(tmp);

        cout << "Adding New Song:" << endl;
        cout << setw(13) << "Title: " << title << endl;
        cout << setw(13) << "Artist: " << artist << endl;
        cout << setw(13) << "Duration: " << duration << endl;
        cout << setw(13) << "Year: " << year << endl;
        cout << setw(13) << "Rating: " << rating << endl << endl;

        Song *newSong = new Song(title, artist, duration, year, rating);

        newPlaylist->addSong(newSong);

        title.clear();
        artist.clear();
        duration.clear();
        tmp.clear();

        year = 0;
        rating = 0.0;
    }

    addPlaylist(newPlaylist);
    // delete newPlaylist;
    file.close();
    return true;
}