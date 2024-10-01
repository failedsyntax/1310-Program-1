#include "Playlist.h"
#include "song.h"
#include "MusicStorage.h"

int main() {
    int numberSongs = 0;

    int songReadYear, songReadRating;
    string songReadTitle, songReadArtist, songReadDuration, ReadTmp;

    string fileName = "Songs.txt";
    Playlist TestPlaylist = Playlist(100);
    
    // Open songs file
    ifstream readFile;
    readFile.open(fileName);

    // Can't open?
    if (!readFile) {
        cout << "Unable to open " << fileName << "!" << endl;
        exit(1);
    }

    // Read file if opened
    while (getline(readFile, songReadTitle, '#')) {
        getline(readFile, songReadArtist, '#');
        getline(readFile, songReadDuration, '#');
        getline(readFile, ReadTmp, '#');
        songReadYear = stoi(ReadTmp);
        getline(readFile, ReadTmp);
        songReadRating = stoi(ReadTmp);

        Song NewSong = Song(songReadTitle.c_str(), songReadArtist.c_str(), songReadDuration.c_str(), songReadYear, songReadRating);
        TestPlaylist.addSong(NewSong);

        cout << songReadTitle << endl << songReadArtist << endl << songReadDuration << endl << songReadYear << endl << songReadRating << endl << endl;
        //break;
    }


    return 0;
}