#include "functions.h"

void displayWelcomeMenu() {
    cout << "Welcome to the Spotify Library Backend Manager!" << endl << endl;
    cout << "Please make a selection:" << endl;
    cout << setw(22) << "1. Display Library" << endl;
    cout << setw(22) << "2. Import Playlist" << endl;
    cout << setw(22) << "3. Modify Playlist" << endl;
    cout << setw(23) << "4. Display Playlist" << endl;
    cout << setw(22) << "5. Delete Playlist" << endl;
    cout << setw(22) << "6. Export Playlist" << endl;
}