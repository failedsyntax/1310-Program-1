#include "functions.h"

void displayWelcomeMenu() {
    cout << endl << endl << "Welcome to the Spotify Library Backend Manager!" << endl << endl;
    cout << "Please make a selection:" << endl;
    cout << setw(22) << "1. Display Library" << endl;
    cout << setw(22) << "2. Import Playlist" << endl;
    cout << setw(22) << "3. Modify Playlist" << endl;
    cout << setw(23) << "4. Display Playlist" << endl;
    cout << setw(22) << "5. Delete Playlist" << endl;
    cout << setw(22) << "6. Export Playlist" << endl;
}

void getNewSongInfo(Playlist* Playlist) {
    string Title, Artist, Duration;
    int Year, Rating;

    cin.ignore(); 

    cout << "Song Title: ";
    getline(cin, Title);

    cout << "Song Artist: ";
    getline(cin, Artist);

    cout << "Song Duration (x:xx): ";
    getline(cin, Duration);

    cout << "Song Release Year: ";
    cin >> Year;

    cout << "Song Rating: ";
    cin >> Rating;

    Song newSong = Song(Title.c_str(), Artist.c_str(), Duration.c_str(), Year, Rating);
    Playlist->addSong(newSong);
}