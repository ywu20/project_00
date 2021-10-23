#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// linked list song struct
struct song_node{
char name[100];
char artist[100];
struct song_node *next;
};



/****************insert nodes at the front*******************/
struct song_node * insert_front(struct song_node * start, char artist[100], char name[100]){

 //allocate memory for new struct
 struct song_node * p = malloc(sizeof(struct song_node));

 //initialize new struct
  strcpy(p->artist,artist);
  strcpy(p->name, name);


  //set new struct's next to point to given struct
  p->next = start;
  return p;
}



/*************compare song nodes, returns < 0 if n1 goes before n2, if 0 the same, if > 0 n2 goes before n1*************/
int node_cmp (struct song_node * p, struct song_node * start){
  // artist string comparison
   int cmp_art = strcmp(p->artist,start->artist);
   //name string comparison
   int cmp_name = strcmp(p->name,start->name);

   //p goes after start
   if ((cmp_art>0) || ((cmp_art == 0) && cmp_name>0)) return 1;

   //equal
   else if((cmp_art == 0) && (cmp_name == 0)) return 0;

   //p goes before start
   return -1;
}

/************insert nodes in order, alphabetically by Artist then by Song***********/
struct song_node * insert_order(struct song_node * start, char artist[100],char name[100]){

 //allocate memory for new struct
 struct song_node * p = malloc(sizeof(struct song_node));

 // keeps track of the starting point
 struct song_node * temp = start;

 //initialize new struct
  strcpy(p->artist,artist);
  strcpy(p->name, name);

//if the list is empty
 if(start == NULL) return p;

// printf("====================\n");

//keeps track of whether p is the first or not
  int front = 1;

//keep track of the previious node for insertion later
  struct song_node * prev = start;

  //find correct position to insert the new struct
  while(node_cmp(p,start)>0){
   front = 0; //if proceeds into the loop it's not the front

   //checks if it's the end of the original list
   if(start -> next == NULL){

     //insert p to the end.
     start -> next = p;
     return temp;
   }
//   printf("Start: %s, %s\n", start -> artist, start ->name);
   //printf("continue: %d\n", cont(p,start));

   //reset prev
   prev = start;

   //move to the next node
   start = start ->next;
   }

  //p should go before start and after prev
   p->next = start;



  //printf("====================\n");

  // if p is in the front, p would be the start.
  if (front) return p;

  else{
  // linking the node that goes before p.
  prev -> next = p;

  //returns the original start of the linked list.
  return temp;
  }
}

/***********print the entire list*****************/
void print_list (struct song_node * node){
  while(node){
  printf("{%s, %s, %p }\n", node -> artist, node -> name, node ->next);
  node = node ->next;
}
}


//find and return a pointer to a node based on artist and song name
struct song_node * find_song(struct song_node * start, char artist[100], char name[100]);

// find and return a pointer to the first song of an artist based on artist name
struct song_node * find_artist(struct song_node * start, char artist[100]);

//Return a pointer to random element in the list.
struct song_node * rand_song(struct song_node * start);

//remove a single specified node from the list, specified by both artist and song name.

struct song_node * remove_node(struct song_node * start, char artist[100], char name[100]);

//free the entire list
struct song_node * free_list(struct song_node * start);
