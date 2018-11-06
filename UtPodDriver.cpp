/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    //cout << "Hello\n";
    UtPod t;
    
    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
    
    t.showSongList();

    //cout << "test3\n";
    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    //cout << "test4\n";
    cout << "result = " << result << endl;
    
    t.showSongList();
       
    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
       
    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
       
    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "sort" << endl;
    t.sortSongList();
    t.showSongList();

    

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
  
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    
    
    t.showSongList();
    
    //result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    t.addSong(s1);
    t.addSong(s2);
    t.addSong(s3);
    t.addSong(s4);
    //t.clearMemory();
    t.shuffle();
    cout << "hi\n";
    t.showSongList();
    t.shuffle();
    cout << "hi2\n";
    t.showSongList();
    t.sortSongList();
    t.showSongList();
    t.clearMemory();
    cout << "there should be nothing from here...\n";
    t.showSongList();
    cout << "to here\n;";
    result = t.addSong(s1);
    cout << result << endl;
    cout << result << endl;
    cout << result << endl;
    result = t.addSong(s4);
    cout << result << endl;
    result = t.addSong(s5);
    cout << result << endl;
    t.sortSongList();
    t.showSongList();
    t.shuffle();
    t.showSongList();
}
