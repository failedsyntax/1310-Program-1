#include "Playlist.h"
#include "song.h"
#include "MusicStorage.h"
#include "functions.h"

const int MAX_PLAYLISTS_IN_STORAGE = 5;

int main() {
    // Menu
    char exitChar = 'n';
    char userExitChar;

    int userMenu;

    string importFileName;
    ifstream importFile;

    // Library
    MusicStorage MainStorage = MusicStorage(MAX_PLAYLISTS_IN_STORAGE);

    do {
        // Welcome Menu
        displayWelcomeMenu();
        cin >> userMenu;

        switch(userMenu) {
            case 1: {
                // Display all Playlists and their songs
                break;
            };

            case 2: {
                cout << "Please input a file of songs to import:" << endl;
                cin.ignore();
                getline(cin, importFileName);

                cout << "Importing songs from " << importFileName << " now.." << endl;
                bool LoadedFile = MainStorage.loadFromFile(importFileName.c_str());

                if (LoadedFile != true) {
                    cout << "Something happened when importing " << importFileName << "!" << endl;
                    break;
                }
                cout << "Successfully imported songs from " << importFileName << "!" << endl;
                break;
            };

            case 3: {
                int playlistToModifySelection;
                int modifyChoice;

                Playlist* PlaylistToModify;

                cout << "Please select a playlist to modify" << endl;
                MainStorage.displayPlaylists();

                cout << "Selection: ";
                cin >> playlistToModifySelection;
                PlaylistToModify = MainStorage.getPlaylist(playlistToModifySelection);

                cout << "\nWhat do you want to do?" << endl;
                cout << setw(10) << "1. Add song(s)" << endl;
                cout << setw(10) << "2. Remove song(s)" << endl;

                cout << "Selection: ";
                cin >> modifyChoice;

                // Add Song
                if (modifyChoice == 1) {
                    getNewSongInfo(PlaylistToModify);
                    break;
                // Remove Song
                } else if(modifyChoice == 2) {

                    break;
                // Not a selection
                } else {
                    cout << "You didn't select a valid option!" << endl;
                    break;
                }
            };

            case 4: {
                cout << endl << endl;

                // Display Playlist
                int playlistChoice;

                cout << "Please select a playlist to display" << endl;
                MainStorage.displayPlaylists();

                cout << "Selection: ";
                cin >> playlistChoice;

                // Down 1 to match array index's
                playlistChoice -= 1;
                MainStorage.printSpecificPlaylist(playlistChoice);

                break;
            }
        }

    } while(userExitChar != exitChar);

    return 0;
}