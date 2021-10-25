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
 start = insert_front (start, "pfp", "I don't know");
 start = insert_front (start, "pink", "I don't know");
 start = insert_front (start, "pink", "space");
 start = insert_front (start, "pink floyd", "time");

 //prints the list
 printf("\n========insert_front initialize test========\n");
 print_list(start);
 printf("\n============================================\n\n");
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
 printf("\n========insert_order initialize test========\n");
 print_list(start);
 printf("\n============================================\n\n");
}

 return start;
}

// tests the functions about finding nodes, if type is 's', then find with song and artist, otherwise just find with artist.
void find_node_test(struct song_node * start, char type){
  struct song_node * test;
  if(type == 's'){
  printf("\n========find song with both song and artist test========\n");
  //find the start
  test = find_song(start,"pearl jam", "alive");
  printf ("\nfind song: pearl jam, alive\n");
  print_node(test);
  printf("\n====================\n");

  //find the middle
  test = find_song(start,"pearl jam", "yellow ledbetter");
  printf ("\nfind song: pearl jam, yellow ledbetter\n");
  print_node(test);
  printf("\n====================\n");

  //find the end
  test = find_song(start,"pink floyd", "time");
  printf ("\nfind song: pink floyd, time\n");
  print_node(test);
  printf("\n====================\n");

  //cannot find
  test = find_song(start,"pink d", "time");
  printf ("\nfind song: NULL\n");
  print_node(test);
  printf("\n====================\n");

  printf("\nprints the list to make sure it's not modified\n");
  print_list(start);
  printf("\n========================================================\n\n");
}else{
  printf("\n========find song with artist test========\n");
  //find the start, artist with multiple songs
  test = find_artist(start,"pearl jam");
  printf ("find artist: pearl jam, alive\n");
  print_node(test);
  printf("\n====================\n");

  //find the middle, with multiple artists
  test = find_artist(start,"pink");
  printf ("\nfind artist: pink, I don't know\n");
  print_node(test);
  printf("\n====================\n");

  //find the end, single artist
  test = find_artist(start,"pink floyd");
  printf ("\nfind artist: pink floyd, time\n");
  print_node(test);
  printf("\n====================\n");

  //cannot find
  test = find_artist(start,"pink d");
  printf ("\nfind artist: NULL\n");
  print_node(test);
  printf("\n====================\n");

  printf("\nprints the list to make sure it's not modified\n");
  print_list(start);
  printf("\n========================================================\n\n");
}
}

void rand_test(struct song_node * start){
printf("\n======================RANDOM SONG TEST=======================\n");
struct song_node * test;
struct song_node * node = NULL;

//test empty list
printf("\n======== empty list test========\n");
test = rand_song(node);
print_node(test);


//test one element
printf("\n===== one element in list test====\n");
node = insert_front(node,"hello", "world");
test = rand_song(node);
print_node(test);

//test regular list
printf("\n======== regular list test========\n");
int i;
for(i=0;i<5;i++){
  print_node(rand_song(start));
  printf("\n");
}
printf("\n===================================\n");

printf("\nprints the list to make sure it's not modified\n");
print_list(start);
printf("\n========================================================\n\n");

}

void remove_node_test(struct song_node * start){
  printf("\n================REMOVE NODE TEST================\n");
  printf("\n=============Remove NULL list test==========\n");
  struct song_node * empty = NULL;
  printf("\nlist before removal: \n");
  print_list(empty);
  empty = remove_node(empty, "pearl jam", "alive");
  printf("\nlist after removal: \n");
  print_list(empty);
  printf("\n============================================\n");

  printf("\n=============Remove not found test==========\n");
  printf("\nlist before removal: \n");
  print_list(start);
  start = remove_node(start, "pel jam", "alive");
  printf("\nlist after removal: \n");
  print_list(start);
  printf("\n==========================================\n");
  printf("\n========remove random node until list is empty========\n");
  while(start){
    printf("\nlist before removal: \n");
    print_list(start);
    struct song_node * rm = rand_song(start);
    printf("\nrandom node chosen: \n");
    print_node(rm);
    start = remove_node(start, rm->artist, rm->name);
    //start= remove_node(start, "pearl jam","even flow");
    printf("\nlist after removal: \n");
    print_list(start);
    printf("\n=========================\n");
  }

}

void add_song_test(struct song_node ** lib){
  printf("\n===========ADD SONG TEST========\n");
  add_song (lib, "pink", "space"); // insert empty
  add_song (lib, "pearl jam", "even flow"); //insert to the front
  add_song (lib, "pearl jam", "yellow ledbetter"); //insert to middle
  add_song (lib, "pearl jam", "even flow"); //insert equals
  add_song (lib, "pearl jam", "alive");
  add_song (lib, "pink floyd", "time"); //insert end
  add_song (lib, "pfp", "I don't know");
  add_song (lib, "pink", "I don't know");
  add_song (lib, "zink", "Me don't know");
  add_song (lib, "Zhou Shen", "dA YU"); //caps
  add_song (lib, "&UM", "b*lA()"); //random char front
  add_song (lib, "", "do oyou"); //empty artist

  printf("print lib: \n");
  print_lib(lib);

  printf("print letter: \n");
  print_letter(lib, 'p');

  printf("print artist: \n");
  print_artist(lib, "pearl jam");
  print_artist(lib, "Zhou Shen");

}

// tests the functions about finding nodes, if type is 's', then find with song and artist, otherwise just find with artist.
void search_lib_test(struct song_node ** lib, char type){
  struct song_node * test;
  if(type == 's'){
  printf("\n========search library with both song and artist test========\n");
  //find the start
  test = search_song(lib,"pearl jam", "alive");
  printf ("\nfind song: pearl jam, alive\n");
  print_node(test);
  printf("\n====================\n");

  //find the middle
  test = search_song(lib,"pearl jam", "yellow ledbetter");
  printf ("\nfind song: pearl jam, yellow ledbetter\n");
  print_node(test);
  printf("\n====================\n");

  //find the end
  test = search_song(lib,"pink floyd", "time");
  printf ("\nfind song: pink floyd, time\n");
  print_node(test);
  printf("\n====================\n");

  //cannot find
  test = search_song(lib,"pink d", "time");
  printf ("\nfind song: NULL\n");
  print_node(test);
  printf("\n====================\n");

  printf("\nprints the lib to make sure it's not modified\n");
  print_lib(lib);
  printf("\n========================================================\n\n");
}else{
  printf("\n========search song with artist in library test========\n");
  //find the start, artist with multiple songs
  test = search_artist(lib,"pearl jam");
  printf ("find artist: pearl jam, alive\n");
  print_node(test);
  printf("\n====================\n");

  //find the middle, with multiple artists
  test = search_artist(lib,"pink");
  printf ("\nfind artist: pink, I don't know\n");
  print_node(test);
  printf("\n====================\n");

  //find the end, single artist
  test = search_artist(lib,"pink floyd");
  printf ("\nfind artist: pink floyd, time\n");
  print_node(test);
  printf("\n====================\n");

  //cannot find
  test = search_artist(lib,"pink d");
  printf ("\nfind artist: NULL\n");
  print_node(test);
  printf("\n====================\n");

  printf("\nprints the lib to make sure it's not modified\n");
  print_lib(lib);
  printf("\n========================================================\n\n");
}
}

void del_song_test(struct song_node ** lib){
  printf("\n================DEL SONG TEST================\n");

  printf("\n=============Remove not found test==========\n");
  printf("\nlib before removal of pel jam, alive:: \n");
  print_lib(lib);
  del_song(lib, "pel jam", "alive");
  printf("\nlib after removal: \n");
  print_lib(lib);
  printf("\n==========================================\n");
  printf("\n========remove songs========\n");
  printf("\nlib before removal of pearl jam, even flow: \n");
  print_lib(lib);
  del_song(lib, "pearl jam","even flow");
  printf("\nlib after removal: \n");
  print_lib(lib);
  printf("\n=========================\n");

  printf("\nlib before removal of pearl jam, alive: \n");
  print_lib(lib);
  del_song(lib, "pearl jam","alive");
  printf("\nlib after removal: \n");
  print_lib(lib);
  printf("\n=========================\n");

  printf("\nlib before removal of Zhou Shen dA YU: \n");
  print_lib(lib);
  del_song(lib, "Zhou Shen","dA YU");
  printf("\nlib after removal: \n");
  print_lib(lib);
  printf("\n=========================\n");

  printf("\nlib before removal of do oyou: \n");
  print_lib(lib);
  del_song(lib, "","do oyou");
  printf("\nlib after removal: \n");
  print_lib(lib);
  printf("\n=========================\n");

  }



int main(){

printf("LINKED LIST TEST \n");
 // construct a linked list for test
 srand(time(NULL));
 struct song_node * start;

 //test list for insert front
 //construct_list(start, 'f');

 //test list for insert order
 start = construct_list(start, 'o');

 find_node_test(start, 's');
 find_node_test(start, 'a');

 rand_test(start);

// removes everything
 remove_node_test(start);

//reconstruct test list
 start = construct_list(start, 'o');

 free_list_print(start);

printf("LIBRARY TEST: \n");

struct song_node ** lib = construct_lib();

add_song_test(lib);

search_lib_test(lib,'s');
search_lib_test(lib,'a');

printf("\n==============Testing Shuffle =============\n");
shuffle(lib);
print_lib(lib);

del_song_test(lib);

printf("\n==============Testing Clear Lib =============\n");
clear_lib_test(lib);
lib = construct_lib();
print_lib(lib);

 return 0;
}
