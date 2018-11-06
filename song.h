#ifndef SONG_H
#define SONG_H

using namespace std;

class Song {
    private:
    string songTitle;
    string songArtist;
    int songSize;

    public:
    Song();
    Song(string title, string artist, int size);

    void setTitle(string title) {songTitle = title;}
    void setArtist(string artist){songArtist = artist;}
    void setSize(int size) {if(size > 0) {songSize = size;}}
    string getTitle() {return songTitle;}
    string getArtist() {return songArtist;}
    int getSize() const {return songSize;}

    bool operator == (const Song &s);

    bool operator > (const Song &s);

    bool operator < (const Song &s);
};

#endif