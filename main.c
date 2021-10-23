#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"
#include "library.h"


//test for insert, construct lists. If type is 'f', insert to the front, otherwise insert in order
struct song_node * construct_list (struct song_node * start, char type){

 if (type == 'f'){
 //insert_front initialize test
 start = insert_front (start, "pearl jam", "alive");
 start = insert_front (start, "pearl jam", "even flow");
 start = insert_front (start, "pearl jam", "yellow ledbetter");
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
 start = insert_order (start, "pearl jam", "alive"); //insert front
 start = insert_order (start, "pink floyd", "time"); //insert end

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
  printf ("find song: cannot find, NULL\n");
  print_node(test);
  printf("====================\n");

  printf("prints the list to make sure it's not modified\n");
  print_list(start);
  printf("========================================================\n\n");
 }
}
int main(){


 // construct a linked list for test
 struct song_node * start;

 //test list for insert front
 //construct_list(start, 'f');

 //test list for insert order
 start = construct_list(start, 'o');

 find_node_test(start, 's');

 return 0;
}
