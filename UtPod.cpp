#include <string>   
#include "UtPod.h"
#include "song.h"
#include <cstdlib>
#include <iostream>

using namespace std;

UtPod::UtPod() {
    this->songs = NULL;
    this->memSize = this->MAX_MEMORY;
}

UtPod::UtPod(int size) {
    this->songs = NULL;
    if ((size > 512) || (size <= 0)) {
        this->memSize = 512;
    }
    else {
        this->memSize = size;
    }
}

int UtPod::addSong(Song const &s) {
    if (getRemainingMemory() > s.getSize()) {
        SongNode *temp = new SongNode;
        temp->s = s;
        temp->next = this->songs;
        this->songs = temp;
        return this->SUCCESS;
    }
    else {
        return this->NO_MEMORY;
    }
}

int UtPod::removeSong(Song const &s) {
    SongNode *curNode = this->songs;        // point to head
    SongNode *prevNode = this->songs;
    if (this->songs->s == s) {
        this->songs = this->songs->next;
        delete curNode;
        return this->SUCCESS;
    }
    while (!(curNode->s == s)) {
        if (curNode == NULL) {
            return this->NOT_FOUND;
        }
        prevNode = curNode;                 // goes through linked list until prevSong is pointing at the node before s
        curNode = curNode->next;            // goes through linked list until curSong is point at s
    }
    prevNode->next = curNode->next;
    delete curNode;
    return this->SUCCESS;
}

void UtPod::clearMemory() {
    SongNode* ptr = this->songs;
    while(this->songs != NULL) {
        ptr = this->songs;
        this->songs = this->songs->next;
        delete ptr;
    }
}

int UtPod::numSongs() {
    SongNode *ptr = this->songs;
    int numSongs = 0;
    while(ptr != NULL) {
        ptr = ptr->next;
        numSongs++;
    }
    return numSongs;
}

void UtPod::swapNodesIndex(SongNode **head, int a, int b) {
    SongNode *aptr = *head;
    SongNode *aptrPrev;
    SongNode *bptr = *head;
    SongNode *bptrPrev;
    if(a == b) {
        return;
    }
    for(int i = 0; i < a; i++) {
        aptrPrev = aptr;
        aptr = aptr->next;
    }
    for(int i = 0; i < b; i++) {
        bptrPrev = bptr;
        bptr = bptr->next;
    }


    if(a == 0) {
        this->songs = bptr;
    }
    else{
        aptrPrev->next = bptr;
    }
    if(b == 0) {
        this->songs = aptr;
    }
    else{
        bptrPrev->next = aptr;
    }
    SongNode* temp = bptr->next;
    bptr->next = aptr->next;
    aptr->next = temp;

    if(a == 0) {
        this->songs = bptr;
    }
    if(b == 0) {
        this->songs = aptr;
    }
    // now aptr points to the node with index a and aptrprev points to the node with index a-1
    // same for b
    return;
}

void UtPod::shuffle() {
    int numSongs = this->numSongs();
    int a, b;
    //numSongs = 1;
    for(int i = 0; i < numSongs * 2; i++) {
        a = rand() % numSongs;
        b = rand() % numSongs;
        //cout << "a :" << a << "b :" << b << endl;
        swapNodesIndex(&this->songs,a,b);
    }
    return;
}

void UtPod::showSongList() {
    for(SongNode *ptr = this->songs; ptr != NULL; ptr = ptr->next) {
        cout << ptr->s.getTitle() << " by " << ptr->s.getArtist() << " - " << ptr->s.getSize() << " mb\n";
    }
    return;
}

void UtPod::swapNodes(SongNode **headPtr, SongNode *currX, SongNode *currY, SongNode *prevY) {
    // make 'currY' as new head 
    *headPtr = currY; 
  
    // adjust links 
    prevY->next = currX; 
  
    // Swap next pointers 
    SongNode* temp = currY->next; 
    currY->next = currX->next; 
    currX->next = temp; 
}

UtPod::SongNode* UtPod::recurSelectionSort(SongNode* head) {
    if (head->next == NULL) {
        return head;
    }

    SongNode* min = head;

    SongNode* beforeMin = NULL;
    SongNode* ptr;

    for (ptr = head; ptr->next != NULL; ptr = ptr->next) {
        if(ptr->next->s < min->s) {
            min = ptr->next;
            beforeMin = ptr;
        }
    }

    if (min != head) {
        swapNodes(&head, head, min, beforeMin);
    }
    head->next = recurSelectionSort(head->next);

    return head;
}

void UtPod::sortSongList() {
    if (this->songs == NULL) {
        return;
    }
    else {
        this->songs = recurSelectionSort(this->songs);
    }
}

int UtPod::getRemainingMemory(){
    SongNode *temp = this->songs;
    int memUsed = 0;
    while(temp != NULL) {
        memUsed += temp->s.getSize();
        temp = temp->next;
    }
    return this->memSize - memUsed;
}

UtPod::~UtPod() {
    this->clearMemory();
}

