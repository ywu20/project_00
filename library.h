#ifndef LIBRARY_H
#define LIBRARY_H

//Allocate enough memory for 27 linked lists, make sure each entry is an empty list.
struct song_node ** construct_lib();

//Add song nodes.
void add_song(struct song_node ** lib,char _artist[100], char _song[100]);

//Search for a song given song and artist name (return a pointer).
struct song_node * search_song(struct song_node ** lib, char _artist[100], char _song[100]);

//Search for an artist (return a pointer).
struct song_node * search_artist(struct song_node ** lib, char _artist[100]);

//Print out all the entries under a certain letter.
void print_letter(struct song_node ** lib, char a);

//Print out all the songs of a certain artist
void print_artist(struct song_node ** lib, char _artist[100]);

//Print out the entire library.
void print_lib(struct song_node ** lib);

//Shuffle - print out a series of randomly chosen songs.
void shuffle (struct song_node ** lib);

//Delete a song
void del_song(struct song_node ** lib, char _artist[100], char _song[100]);

//Clear out all the linked lists in the library.
struct song_node ** clear_lib(struct song_node ** lib);


#endif
