#ifndef storage.h
#define storage.h

/*
Pointer to an array of pointers to the data.
 Data stored is the data class.
o Examples: parking lot, toy box, galaxy (holds stars).
o Requirements: be able to read items from a file, be able to print the contents
to the screen
*/

#include <iostream>
#include "data.h"

class musicstorage{
    private:
        text** textarray;
        music** musiclist;
        int txtarraysize;
    public:
        musicstorage(){
            txtarraysize = 1;
            textarray = new text* [txtarraysize];
        }
    ~musicstorage(){
        delete textarray;
        cout << "Released Memory for the Array of pointers";
    }



};
#endif