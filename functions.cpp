/*
    Title: Functions.cpp
    Purpose: Show main menu and if the user wants to enter a new song
    use getNewSongInfo
*/
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
    cout << setw(18) << "8. End Program" << endl;
    cout << "Selection: ";
}

void getNewSongInfo(Playlist* Playlist) {
    string Title, Artist, Duration, YearStr, RatingStr;
    int Year;
    double Rating;

    cin.ignore(); 

    cout << setw(19) << "Title: ";
    getline(cin, Title);

    cout << setw(19) << "Artist: ";
    getline(cin, Artist);

    cout << setw(19) << "Duration (x:xx): ";
    getline(cin, Duration);

    cout << setw(19) << "Release Year: ";
    getline(cin, YearStr);
    Year = stoi(YearStr);

    cout << setw(19) << "Rating: ";
    getline(cin, RatingStr);
    Rating = stod(RatingStr);

    Song* newSong = new Song(Title, Artist, Duration, Year, Rating);

    // After adding the song
    Playlist->addSong(newSong);

    Title.clear(); Artist.clear(); Duration.clear(); YearStr.clear(); RatingStr.clear();
    Year = 0; Rating = 0.0;
}