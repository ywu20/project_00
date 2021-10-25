#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"
#include "library.h"
#include<time.h>



//test for insert, construct lists. If type is 'f', insert to the front, otherwise insert in order
struct song_node * construct_list (struct song_node * start, char type){
 start = NULL;
 if (type == 'f'){
 //insert_front initialize test
 start = insert_front (start, "pearl jam", "alive");
 start = insert_front (start, "pearl jam", "even flow");
 start = insert_front (start, "pearl jam", "yellow ledbetter");
 start = insert_front (start, "pap", "I don't know");
 start = insert_front (start, "pink", "I don't know");
 start = insert_front (start, "pink", "space");
 start = insert_front (start, "pink floyd", "time");

 //prints the list
 printf("========insert_front initialize test========\n");
 print_list(start);
 printf("============================================\n\n");
 }

 else{
 //insert_order initialize test

 start = insert_order (start, "pink", "space"); // insert empty
 start = insert_order (start, "pearl jam", "even flow"); //insert to the front
 start = insert_order (start, "pearl jam", "yellow ledbetter"); //insert to middle
 start = insert_order (start, "pearl jam", "even flow"); //insert equals
 start = insert_order (start, "pearl jam", "alive");
 start = insert_order (start, "pink floyd", "time"); //insert end
 start = insert_order (start, "pfp", "I don't know");
 start = insert_order (start, "pink", "I don't know");

 //prints the list
 printf("========insert_order initialize test========\n");
 print_list(start);
 printf("============================================\n\n");
}

 return start;
}

// tests the functions about finding nodes, if type is 's', then find with song and artist, otherwise just find with artist.
void find_node_test(struct song_node * start, char type){
  struct song_node * test;
  if(type == 's'){
  printf("========find song with both song and artist test========\n");
  //find the start
  test = find_song(start,"pearl jam", "alive");
  printf ("find song: pearl jam, alive\n");
  print_node(test);
  printf("====================\n");

  //find the middle
  test = find_song(start,"pearl jam", "yellow ledbetter");
  printf ("find song: pearl jam, yellow ledbetter\n");
  print_node(test);
  printf("====================\n");

  //find the end
  test = find_song(start,"pink floyd", "time");
  printf ("find song: pink floyd, time\n");
  print_node(test);
  printf("====================\n");

  //cannot find
  test = find_song(start,"pink d", "time");
  printf ("find song: NULL\n");
  print_node(test);
  printf("====================\n");

  printf("prints the list to make sure it's not modified\n");
  print_list(start);
  printf("========================================================\n\n");
}else{
  printf("========find song with artist test========\n");
  //find the start, artist with multiple songs
  test = find_artist(start,"pearl jam");
  printf ("find artist: pearl jam, alive\n");
  print_node(test);
  printf("====================\n");

  //find the middle, with multiple artists
  test = find_artist(start,"pink");
  printf ("find artist: pink, I don't know\n");
  print_node(test);
  printf("====================\n");

  //find the end, single artist
  test = find_artist(start,"pink floyd");
  printf ("find artist: pink floyd, time\n");
  print_node(test);
  printf("====================\n");

  //cannot find
  test = find_artist(start,"pink d");
  printf ("find artist: NULL\n");
  print_node(test);
  printf("====================\n");

  printf("prints the list to make sure it's not modified\n");
  print_list(start);
  printf("========================================================\n\n");
}
}

void rand_test(struct song_node * start){
printf("======================RANDOM SONG TEST=======================\n");
struct song_node * test;
struct song_node * node = NULL;

//test empty list
printf("======== empty list test========\n");
test = rand_song(node);
print_node(test);


//test one element
printf("===== one element in list test====\n");
node = insert_front(node,"hello", "world");
test = rand_song(node);
print_node(test);

//test regular list
printf("======== regular list test========\n");
int i;
for(i=0;i<5;i++){
  print_node(rand_song(start));
}
printf("===================================\n");

printf("prints the list to make sure it's not modified\n");
print_list(start);
printf("========================================================\n\n");

}

void remove_node_test(struct song_node * start){
  printf("================REMOVE NODE TEST================\n");
  printf("=============Remove NULL list test==========\n");
  struct song_node * empty = NULL;
  printf("list before removal: \n");
  print_list(empty);
  empty = remove_node(empty, "pearl jam", "alive");
  printf("\nlist after removal: \n");
  print_list(empty);
  printf("============================================\n");

  printf("=============Remove not found test==========\n");
  printf("list before removal: \n");
  print_list(start);
  start = remove_node(start, "pel jam", "alive");
  printf("\nlist after removal: \n");
  print_list(start);
  printf("==========================================\n");
  printf("========remove random node until list is empty========\n");
  while(start){
    printf("list before removal: \n");
    print_list(start);
    struct song_node * rm = rand_song(start);
    printf("\nrandom node chosen: \n");
    print_node(rm);
    start = remove_node(start, rm->artist, rm->name);
    //start= remove_node(start, "pearl jam","even flow");
    printf("\nlist after removal: \n");
    print_list(start);
    printf("=========================\n");
  }

}

int main(){


 // construct a linked list for test
 srand(time(NULL));
 struct song_node * start;

 //test list for insert front
 //construct_list(start, 'f');

 //test list for insert order
 start = construct_list(start, 'o');

 find_node_test(start, 'a');

 rand_test(start);

// removes everything
 remove_node_test(start);

//reconstruct test list
 start = construct_list(start, 'o');

 free_list_print(start);

 return 0;
}
