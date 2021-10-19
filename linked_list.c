#include<stdio.h>
#include<stdlib.h>

// linked list song struct
struct song_node{
char name[100];
char artist[100];
struct song_node *next;
};

//insert nodes at the front

//insert nodes in order, alphabetically by Artist then by Song
//compare song nodes


//print the entire list
void print_list (struct song_node * node){
  while(node){
  printf("{%s, %s, %p }\n", node -> artist, node -> name, node ->next);
  node = node ->next;
}
}
//find and return a pointer to a node based on artist and song name
// find and return a pointer to the first song of an artist based on artist name
//Return a pointer to random element in the list.
//remove a single specified node from the list, specified by both artist and song name.
//free the entire list
