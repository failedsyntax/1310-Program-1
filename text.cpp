#include "text.h"

text::text(const char* txtvar){
    txtlength = strlen(txtvar);
    char* array = new char[txtlength + 1];
    strcpy(array, txtvar);
    txtarray = array;
}

text::~text(){
    delete [] txtarray;
    cout << "\nReleased the memory for the txtarray.";
}

void text::displayTxt(){
    txtlength = strlen(txtarray);
    cout << txtarray;
}

const char* text::GettxtSize(){
    return txtarray;
}

int text::Gettxtlength(){
    txtlength = strlen(txtarray);
    return txtlength;
}