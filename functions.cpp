#include "functions.h"

void displayWelcomeMenu() {
    cout << endl << endl << "Welcome to the Spotify Library Backend Manager!" << endl << endl;
    cout << "Please make a selection:" << endl;
    cout << setw(22) << "1. Display Library" << endl;
    cout << setw(22) << "2. Import Playlist" << endl;
    cout << setw(22) << "3. Modify Playlist" << endl;
    cout << setw(23) << "4. Display Playlist" << endl;
    cout << setw(22) << "5. Create Playlist" << endl;
    cout << setw(22) << "6. Delete Playlist" << endl;
    cout << setw(22) << "7. Export Playlist" << endl;
}

void getNewSongInfo(Playlist* Playlist) {
    string Title, Artist, Duration, YearStr, RatingStr;
    int Year;
    double Rating;

    cin.ignore(); 

    cout << "Song Title: ";
    getline(cin, Title);

    cout << "Song Artist: ";
    getline(cin, Artist);

    cout << "Song Duration (x:xx): ";
    getline(cin, Duration);

    cout << "Song Release Year: ";
    getline(cin, YearStr);
    Year = stoi(YearStr);

    cout << "Song Rating: ";
    getline(cin, RatingStr);
    Rating = stod(RatingStr);

    Song* newSong = new Song(Title, Artist, Duration, Year, Rating);

    // After adding the song
    Playlist->addSong(newSong);
}