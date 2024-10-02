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
    int playlistChoice;

    string importFileName;
    ifstream importFile;

    // Library
    MusicStorage MainStorage = MusicStorage(0);

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

                if (MainStorage.getPlaylistCount() > 0) {
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
                } else {
                    cout << "No playlists to modify!" << endl;
                    break;
                }
            };

            case 4: {
                cout << endl << endl;

                if (MainStorage.getPlaylistCount() > 0) {
                    cout << "Please select a playlist to display" << endl;
                    MainStorage.displayPlaylists();

                    cout << "Selection: ";
                    cin >> playlistChoice;

                    // Down 1 to match array index's
                    playlistChoice--;
                    MainStorage.printSpecificPlaylist(playlistChoice);
                } else {
                    cout << "No playlists to display!" << endl;
                }

                break;
            };

            case 5: {
                // Delete Playlist
                cout << endl << endl;

                if (MainStorage.getPlaylistCount() > 0) {
                    cout << "Please select a playlist to delete" << endl;
                    MainStorage.displayPlaylists();

                    cout << "Selection: ";
                    cin >> playlistChoice;

                    playlistChoice--;
                    MainStorage.removePlaylist(playlistChoice);
                } else {
                    cout << "No playlists to display!" << endl;
                }

                break;
            };

            case 6: {
                // Export Playlist
                cout << endl << endl;

                if (MainStorage.getPlaylistCount() > 0) {
                    string fileName;    

                    cout << "Please select a playlist to export" << endl;
                    MainStorage.displayPlaylists();

                    cout << "Selection: ";
                    cin >> playlistChoice;
                    playlistChoice--;

                    cout << "What would you like to name the exported file?" << endl;
                    getline(cin, fileName);
                    cin.ignore();

                    MainStorage.saveToFile(playlistChoice, fileName);
                } else {
                    cout << "No playlists to export!" << endl;
                }

                break;
            }
        }

    } while(userExitChar != exitChar);

    return 0;
}