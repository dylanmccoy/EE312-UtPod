#include <string>   
#include "song.h"

using namespace std;


Song::Song() {
    this->songTitle = "";
    this->songArtist = "";
    this->songSize = 0;
}

Song::Song(string artist, string title, int size) {
    this->songTitle = title;
    this->songArtist = artist;
    this->songSize = size;
}

bool Song::operator == (const Song &s) {
    if (this->songTitle == s.songTitle) {
        if (this->songArtist == s.songArtist) {
            if (this->songSize == s.songSize) {
                return true;
            }
        }
    }
    return false;
}

bool Song::operator > (const Song &s) {     // a > b returns true if a is alphabetically after b
    if (this->songArtist > s.songArtist) {
        return true;
    }
    if (this->songArtist == s.songArtist) {
        if (this->songTitle > s.songTitle) {
            return true;
        }
    }
    if (this->songArtist == s.songArtist) {
        if (this->songTitle == s.songTitle) {
            if (this->songSize > s.songSize) {
                return true;
            }
        }
    }
    return false;
}

bool Song::operator < (const Song &s) {     // a < b returns true if a is alphabetically before b
    if (this->songArtist < s.songArtist) {
        return true;
    }
    if (this->songArtist == s.songArtist) {
        if (songTitle < s.songTitle) {
            return true;
        }
    }
    if (this->songArtist == s.songArtist) {
        if (this->songTitle == s.songTitle) {
            if (this->songSize < s.songSize) {
                return true;
            }
        }
    }
    return false;        
}