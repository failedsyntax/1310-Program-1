#ifndef TEXT.H
#define TEXT.H

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;


class text{
    private:
        const char* txtarray;
        int txtlength;
    public:
        text(const char*);

        ~text();

        void displayTxt();

        const char* GettxtSize();

        int Gettxtlength();

};

#endif