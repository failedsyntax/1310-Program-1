class musicLibrary{
    
    private:
        musicLibrary** musicPTR;
        int numSongs;
        int songCount;

    musicLibrary(){
        musicPTR = nullptr;
        numSongs = 0;
        songCount = 0;
    }

    musicLibrary(musicLibrary** mp, int songs, int count){
        musicPTR = mp;
        numSongs = songs;
        songCount = count;
    }

    ~musicLibrary(){

    }

    void printDisplay(musicLibrary*){
        
        
    }
    

};