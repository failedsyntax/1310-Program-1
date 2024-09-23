#include <iostream>

using namespace std;

class videoGame{
    
    private:

        string gameName;
        string author;
        string publisher;
        int yearReleased;
        int rating;

    public:

        videoGame();

        videoGame(string,string,string, int, int);

        ~videoGame();

        string getGameName();

        string getAuthor();

        string getPublisher();
        
        int getYear();

        int getRating();

        void setName(string);
        
        void setAuthor(string);

        void setPublisher(string);

        void setYearReleased(int);

        void setRating(int);






};