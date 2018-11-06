#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include "UtPod.h"
#include "song.h"
using namespace std;


int main(int argc, char *argv[]) {
    cout << "File test - file:\t" << argv[1] << endl;

    ifstream testFile;
    testFile.open(argv[1]);
    if(testFile.is_open()) {
        cout << "File opened. Begin tests." << endl;

        int memSize = 0;
        if(argv[2] != NULL)
            memSize = atoi(argv[2]);

        //construct the UtPod
        UtPod t = UtPod(memSize);

        string line;
        int i = 1;
        //reads each line and parses for information.
        while(getline(testFile, line)) {
            try {
                //cout << "Test " << i++ << " ------------------------" << endl;
                string cmd = "";
                string title = "";
                string artist = "";
                int size = 0;

                //parse string into 4 and assign: cmd, title, artist, memory

                string::size_type posBegin =  0, posEnd = 0, posTemp;
                bool quote = false;
                string::size_type len = 1;
                string lineSplit[4];
                int i = 0;

                //split line on commas into array of strings
                while(posEnd != string::npos && i < 4) {
                    posEnd = line.find_first_of(',', posBegin);

                    // Check for optional quotes
                    if((posTemp = line.find_first_of('"', posBegin)) < posEnd) {
                        posBegin = posTemp + 1;
                        posEnd = line.find_first_of('"', posBegin);
                        quote = true;
                    }

                    // If next comma or quote not found, read the whole string
                    len = posEnd == string::npos ? string::npos : posEnd - posBegin;
                    lineSplit[i] = line.substr(posBegin, len);

                    posBegin = posEnd + 1;

                    if(quote)
                        posBegin++;
                    quote = false;

                    i++;
                }


                for(int i = 0; i < 4; i++) {
                    if(lineSplit[i].c_str()[lineSplit[i].length() - 1] == '\r')
                        lineSplit[i] = lineSplit[i].substr(0, lineSplit[i].length() - 1);
                }

                //assign arguments
                cmd = lineSplit[0];
                title = lineSplit[1];
                artist = lineSplit[2];

                if(lineSplit[3].length() != 0) {
                    size = atoi(lineSplit[3].c_str());
                }

                int result = 0;

                if(cmd == "add") {
                    Song s(title, artist, size);
                    result = t.addSong(s);
                    if(result == 0)
                        cout << "Song " << title << " has been added to the playlist." << endl;
                    else
                        cout << "Error:\t" << result << " while adding song " << title << " to playlist " << endl;

                } else if(cmd == "rm") {
                    Song s(title, artist, size);
                    result = t.removeSong(s);
                    if(result == 0)
                        cout << "Song " << title << " has been removed from the playlist." << endl;
                    else
    		    cout << "Error:\t" << result << " while removing song " << title << " to playlist " << endl;

                } else if(cmd == "shw") {
                    cout << "Song playlist:" << endl;
    		      cout << endl;
                    t.showSongList();
    		      cout << endl;

                } else if(cmd == "srt") {
                    t.sortSongList();
                    cout << "UtPod has been sorted. Sorted playlist:" << endl;
    		      cout << endl;
                    t.showSongList();
    		      cout << endl;

                } else if(cmd == "shf") {
                    t.shuffle();
                    cout << "UtPod has been shuffled. Shuffled playlist:" << endl;
    		          cout << endl;
                    t.showSongList();
    		          cout << endl;

                } else if(cmd == "clr") {
                    t.clearMemory();
                    cout << "UtPod cleared." << endl;

                } else if(cmd == "getTMem") {
                    cout << "Total memory:\t" << t.getTotalMemory() << endl;

                } else if(cmd == "getRMem") {
                    cout << "Remaining memory:\t" << t.getRemainingMemory() << endl;

                } else if(cmd == "cmt") {
                    cout << "______________________________" << endl;
                    cout << "\n|| " << title << " ||" << endl;

                } else if(cmd == "end") {
                    testFile.close();
                    cout << "File closed. End of program execution." << endl;
                    return 1;

                } else {
                    cout << "Invalid command. Moving to next line." << endl;
                }
            } catch (const std::exception& e) {
                std::cout << "<<Exception>> " << e.what() << endl;
            }
        }

        testFile.close();
        cout << "File closed. End of program execution." << endl;
        return 1;

    } else {
        cout << "File err. Did not open." << endl;
        return 0;
    }
}
