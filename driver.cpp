/*
    Title: Driver.cpp
    Purpose: Main driver function, main menu for the program.
    Allows the user to input choices to effect txt files.
*/

#include "Playlist.h"
#include "song.h"
#include "MusicStorage.h"
#include "functions.h"

int main() {
    // Menu
    char exitChar = 'n';
    char userExitChar;

    int userMenu;
    int playlistChoice;

    string importFileName;
    ifstream importFile;

    // Library
    MusicStorage MainStorage = MusicStorage(1);

    do {
        // Welcome Menu
        displayWelcomeMenu();
        cin >> userMenu;

        switch(userMenu) {
            case 1: {
                // Display all Playlists and their songs
                cout << endl << endl;
                if (MainStorage.getPlaylistCount() > 0) {
                    cout << "Entire Library Storage:" << endl;
                    MainStorage.displayPlaylists();
                } else {
                    cout << "There are no playlists to display!" << endl;
                }

                break;
            };

            case 2: {
                // Import Playlist
                cout << endl << "Please input a file of songs to import: ";
                cin.ignore();
                getline(cin, importFileName);

                cout << "Importing songs from " << importFileName << " now.." << endl << endl;
                bool LoadedFile = MainStorage.loadFromFile(importFileName.c_str());
                
                if (LoadedFile != true) {
                    cout << "Something happened when importing " << importFileName << "!" << endl;
                } else {
                    cout << "Successfully imported songs from " << importFileName << "!" << endl;
                }
                break;
            };

            case 3: {
                // Edit Playlist
                int playlistToModifySelection;
                int modifyChoice;
                int removeSelection;

                Playlist* PlaylistToModify;

                if (MainStorage.getPlaylistCount() > 0) {
                    cout << "Please select a playlist to modify" << endl;
                    MainStorage.printPlaylists();

                    cout << endl << "Selection: ";
                    cin >> playlistToModifySelection;
                    PlaylistToModify = MainStorage.getPlaylist(playlistToModifySelection);

                    cout << endl << "\nWhat do you want to do?" << endl;
                    cout << setw(10) << "1. Add song(s)" << endl;
                    cout << setw(10) << "2. Remove song(s)" << endl << endl;

                    cout << "Selection: ";
                    cin >> modifyChoice;

                    // Add Song
                    if (modifyChoice == 1) {
                        getNewSongInfo(PlaylistToModify);
                        break;
                    // Remove Song
                    } else if(modifyChoice == 2) {
                        PlaylistToModify->printSong();
                        cout << "Please select a song to remove: ";
                        cin >> removeSelection;

                        PlaylistToModify->removeSong(removeSelection - 1);
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
                // Display specific Playlist
                cout << endl << endl;

                if (MainStorage.getPlaylistCount() > 0) {
                    cout << "Please select a playlist to display" << endl;
                    MainStorage.printPlaylists();

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
                // Create Playlist
                cout << endl << endl;

                int newPlaylistSize, SongsToAddNow;

                cout << "How many songs can the playlist contain? ";
                cin >> newPlaylistSize;

                cout << "How many songs would you like to add now? ";
                cin >> SongsToAddNow;

                // Create new playlist
                Playlist* newPlaylist = new Playlist(newPlaylistSize);

                // Add songs if any currently
                if (SongsToAddNow > 0) { // More than one
                    for (int i = 0; i < SongsToAddNow; i++) {
                        cout << "Please input info about Song " << (i + 1) << ":" << endl;
                        getNewSongInfo(newPlaylist);
                    };
                };

                // Add to main library
                MainStorage.addPlaylist(newPlaylist);

                break;

            };

            case 6: {
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
                    cout << "No playlists to delete!" << endl;
                }

                break;
            };

            case 7: {
                // Export Playlist
                cout << endl << endl;

                if (MainStorage.getPlaylistCount() > 0) {
                    string fileName;    

                    cout << "Please select a playlist to export" << endl;
                    MainStorage.displayPlaylists();

                    cout << "Selection: ";
                    cin >> playlistChoice;
                    playlistChoice--;

                    cin.ignore();

                    cout << "What would you like to name the exported file?" << endl;
                    getline(cin, fileName);

                    bool didSave = MainStorage.saveToFile(playlistChoice, fileName);

                    if (didSave == true) {
                        cout << "Successfully exported Playlist " << (playlistChoice + 1);
                        cout << " as file " << fileName << "!" << endl << endl;
                    } else {
                        cout << "Something happened while trying to export Playlist " << (playlistChoice + 1);
                        cout << " as file" << fileName << "!" << endl << endl;
                    }
                } else {
                    cout << "No playlists to export!" << endl;
                }

                break;
            };

            case 8: { // End Program
                cout << "You are now attempting to exit the Spotify Server Backend" << endl;
                cout << "Please type 'n' to confirm exit: ";

                cin >> userExitChar;

                if (userExitChar != exitChar) {
                    cout << endl << "You didn't input the exit character!" << endl;
                    cout << "Returning to menu.." << endl << endl;
                } else {
                    cout << endl << "Clearing local data.." << endl << endl;
                    MainStorage.~MusicStorage();
                    cout << "Exiting backend.. Goodbye!" << endl;
                }

                break;
            }
        }

    } while(userExitChar != exitChar);

    return 0;
}