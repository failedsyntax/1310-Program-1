#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <fstream>

#include "Playlist.h"
#include "song.h"
#include "MusicStorage.h"

using namespace std;

// Prototypes
void displayWelcomeMenu();
void getNewSongInfo(Playlist* Playlist);
#endif