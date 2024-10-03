#include <iostream>

using namespace std;

<<<<<<< Updated upstream
=======
int main()
{
    // Menu
    char exitChar = 'n';
    char userExitChar;

    int userMenu;
    int playlistChoice;

    string importFileName;
    ifstream importFile;

    // Library
    MusicStorage MainStorage = MusicStorage(5);

    do
    {
        // Welcome Menu
        displayWelcomeMenu();
        cin >> userMenu;

        switch (userMenu)
        {
        case 1:
        {
            // Display all Playlists and their songs

            if (MainStorage.getPlaylistCount() > 0)
            {
                MainStorage.displayPlaylists();
            }
            else
            {
                cout << "No playlists to display!" << endl;
            }

            break;
        };

        case 2:
        {
            // Import Playlist
            cout << "Please input a file of songs to import:" << endl;
            cin.ignore();
            getline(cin, importFileName);

            cout << "Importing songs from " << importFileName << " now.." << endl;
            bool LoadedFile = MainStorage.loadFromFile(importFileName.c_str());
            cout << "Finished file" << endl;
            if (LoadedFile != true)
            {
                cout << "Something happened when importing " << importFileName << "!" << endl;
            }
            else
            {
                cout << "Successfully imported songs from " << importFileName << "!" << endl;
            }
            break;
        };

        case 3:
        {
            // Edit Playlist
            int playlistToModifySelection;
            int modifyChoice;

            Playlist *PlaylistToModify;

            if (MainStorage.getPlaylistCount() > 0)
            {
                cout << "Please select a playlist to modify" << endl;
                MainStorage.displayPlaylists();


                cout << "Selection: ";
                cin >> playlistToModifySelection;
                PlaylistToModify = MainStorage.getPlaylist(playlistToModifySelection);
                cout << PlaylistToModify; 
                cout << "\nWhat do you want to do?" << endl;
                cout << setw(10) << "1. Add song(s)" << endl;
                cout << setw(10) << "2. Remove song(s)" << endl;

                cout << "Selection: ";
                cin >> modifyChoice;

                // Add Song
                if (modifyChoice == 1)
                {
                    getNewSongInfo(PlaylistToModify);
                    break;
                    // Remove Song
                }
                else if (modifyChoice == 2)
                {

                    break;
                    // Not a selection
                }
                else
                {
                    cout << "You didn't select a valid option!" << endl;
                    break;
                }
            }
            else
            {
                cout << "No playlists to modify!" << endl;
                break;
            }
        };

        case 4:
        {
            // Display specific Playlist
            cout << endl
                 << endl;

            if (MainStorage.getPlaylistCount() > 0)
            {
                cout << "Please select a playlist to display" << endl;
                MainStorage.displayPlaylists();

                cout << "Selection: ";
                cin >> playlistChoice;

                // Down 1 to match array index's
                playlistChoice--;
                MainStorage.printSpecificPlaylist(playlistChoice);
            }
            else
            {
                cout << "No playlists to display!" << endl;
            }

            break;
        };

        case 5:
        {
            // Create Playlist
            cout << endl
                 << endl;

            int newPlaylistSize, SongsToAddNow;
            int currentPlaylistCount = MainStorage.getPlaylistCount();

            cout << "How many songs can the playlist contain? ";
            cin >> newPlaylistSize;

            cout << "How many songs would you like to add now? ";
            cin >> SongsToAddNow;

            // Create new playlist
            Playlist *newPlaylist = new Playlist(newPlaylistSize);

            // Add songs if any currently
            if (SongsToAddNow > 0)
            { // More than one
                for (int i = 0; i < SongsToAddNow; i++)
                {
                    cout << "Please input info about song " << (i + 1) << endl;
                    getNewSongInfo(newPlaylist);
                };

                // Add to main library
                MainStorage.addPlaylist(newPlaylist);
            };

            break;
        };

        case 6:
        {
            // Delete Playlist
            cout << endl
                 << endl;

            if (MainStorage.getPlaylistCount() > 0)
            {
                cout << "Please select a playlist to delete" << endl;
                MainStorage.displayPlaylists();

                cout << "Selection: ";
                cin >> playlistChoice;

                playlistChoice--;
                MainStorage.removePlaylist(playlistChoice);
            }
            else
            {
                cout << "No playlists to display!" << endl;
            }

            break;
        };

        case 7:
        {
            // Export Playlist
            cout << endl
                 << endl;

            if (MainStorage.getPlaylistCount() > 0)
            {
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
            }
            else
            {
                cout << "No playlists to export!" << endl;
            }

            break;
        }
        }

    } while (userExitChar != exitChar);

    return 0;
}
>>>>>>> Stashed changes
