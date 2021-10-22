#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"
#include "library.h"


//test for insert, construct lists
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
 start = insert_front (start, "pink", "space");
 //start = insert_front (start, "pearl jam", "even flow");
 //print_list(start); 
 //start = insert_order (start, "pearl jam", "yellow ledbetter");
 //print_list(start);
 //start = insert_order (start, "pearl jam", "alive");
 //print_list(start);
 start = insert_order (start, "pink floyd", "time");
 
 //prints the list
 printf("========insert_order initialize test========\n");
 print_list(start);
 printf("============================================\n\n");
}
 
 return start;
}

int main(){


 // construct a linked list for test 
 struct song_node * start;
 
 //test list for insert front
 //construct_list(start, 'f'); 
 
 //test list for insert order
 construct_list(start, 'o');

 return 0;
}
