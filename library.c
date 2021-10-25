#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "linked_list.h"

//Allocate enough memory for 27 linked lists, make sure each entry is an empty list.
struct song_node ** construct_lib(){
  //calloc makes everything empty
  struct song_node ** lib = calloc(27, sizeof(struct song_node *));
  return lib;
}

//find the index to be add to
int find_index(char artist[100]){
  int index = 26; //default to 27

  //if not empty string
  if(strcmp(artist, "")!=0){

  //turn to lowercase if it's uppercase
  char f_letter = artist[0];
  if(f_letter<'a' && f_letter >= 'A'){
   f_letter = tolower(f_letter);
 }

  //put to its according alphabet.
  int ind = f_letter-'a';
  if(ind >=0 && ind <26){
    index = ind;
  }
}
return index;
}

//Add song nodes.
void add_song(struct song_node ** lib, char artist[100], char name[100]){
  int index = find_index(artist); //finds index to insert to

  //insert song into library
  lib[index] = insert_order(lib[index],artist, name);
}

//Search for a song given song and artist name (return a pointer).
struct song_node * search_song(struct song_node ** lib, char artist[100], char song[100]){
  int index = find_index(artist);
  return find_song(lib[index], artist, song);
}

//Search for an artist (return a pointer).
struct song_node * search_artist(struct song_node ** lib, char artist[100]){
  int index = find_index(artist);
  return find_artist(lib[index], artist);
}

//Print out all the entries under a certain letter.
void print_letter(struct song_node ** lib, char a){
  if(lib == NULL) printf("NULL\n");
  char a_temp [100];
  a_temp[0]=a;
  int index = find_index(a_temp);
  print_list(lib[index]);
}

//Print out all the songs of a certain artist
void print_artist(struct song_node ** lib, char artist[100]){
  if(lib == NULL) printf("NULL\n");
  int index = find_index(artist);
  struct song_node * first = find_artist(lib[index], artist);
  struct song_node * temp = first;
  printf("%s: ", artist);
  while(strcmp(first -> artist, temp->artist) == 0){
    print_node(temp);
    temp = temp->next;
  }
  printf("\n");
}

//Print out the entire library.
void print_lib(struct song_node ** lib){
  int i;
  if(lib == NULL) printf("NULL\n");
  for(i=0;i<27;i++){
    if(lib[i] != NULL){
      printf("%c: ", 'a' + i);
      print_list(lib[i]);
    }
  }
}

//Shuffle - print out a series of randomly chosen songs.
void shuffle (struct song_node ** lib){
  // prints a random number of songs from 1-5
  int num = (rand() % 5)+1;
  int index;
  struct song_node * song;

  while(num--){
    //updates index so it can prints from all the different letters.
    index = rand() %27;

    //make sure the song chosen is not null.
    while ((song = rand_song(lib[index])) == NULL) index = rand() %27;

    //prints song
    print_node(song);
    printf("\n");
  }
}

//Delete a song
void del_song(struct song_node ** lib, char artist[100], char song[100]){
  if(lib != NULL){
 int index = find_index(artist);

 lib[index] = remove_node(lib[index], artist, song);
}

}

//Clear out all the linked lists in the library.
struct song_node ** clear_lib(struct song_node ** lib){
  int i;
  for(i=0;i<27;i++){
    free_list(lib[i]);
  }
  return lib;
}

// Clear with print statements
struct song_node ** clear_lib_test(struct song_node ** lib){
  int i;
  for(i=0;i<27;i++){
    free_list_print(lib[i]);
  }
  return lib;
}
