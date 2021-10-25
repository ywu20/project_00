#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// linked list song struct
struct song_node{
char artist[100];
char name[100];
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
  p->next = NULL;

//if the list is empty
 if(start == NULL) return p;

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
   //reset prev
   prev = start;
   //move to the next node
   start = start ->next;
   }

  //p should go before start and after prev
   p->next = start;
  // if p is in the front, p would be the start.
  if (front) return p;

  else{
  // linking the node that goes before p.
  prev -> next = p;
  //returns the original start of the linked list.
  return temp;
  }
}

/***********prints a node******************/
void print_node (struct song_node * node){
  if (node == NULL) printf("NULL\n");
  else printf("{%s, %s} ", node -> artist, node -> name);

}

/***********print the entire list*****************/
void print_list (struct song_node * node){
  printf("[");
  while(node){
  print_node(node);
  printf("|");
  node = node ->next;
}
printf("]\n");
}


/***********find and return a pointer to a node based on artist and song name***********/
struct song_node * find_song(struct song_node * start, char artist[100], char name[100]){
  // creates a node and initialize with the artist and name
  struct song_node * cmp = malloc(sizeof(struct song_node));
  strcpy(cmp->artist,artist);
  strcpy(cmp->name, name);

  // traverse through the list with temp so that start won't get messed up
  struct song_node * temp = start;

  //loop through the list, stop when the nodes are equal or at the end of the list
  while(temp && node_cmp (cmp, temp)!= 0) temp = temp -> next;

  //frees the cmp node
  free(cmp);

  return temp;
}

/********* find and return a pointer to the first song of an artist based on artist name**********/
struct song_node * find_artist(struct song_node * start, char artist[100]){
  // traverse through the list with temp so that start won't get messed up
  struct song_node * temp = start;

  //loop through the list, stop when the nodes are equal or at the end of the list
  while(temp && strcmp(temp->artist, artist)!= 0) temp = temp -> next;

  return temp;
}

/*******calculates the length of linked list (helper funciton)************/
int list_len (struct song_node* start){
  int len = 0;
  struct song_node * temp = start; //makes sure start is not modified

  //calculate the length of the list
  while(temp){
    len++;
    temp = temp->next;
  }

  return len;
}
//Return a pointer to random element in the list.
struct song_node * rand_song(struct song_node * start){

 //handles null inputs
  if(start==NULL) return NULL;

  int len=list_len(start); //keeps track of the length of the list
  struct song_node * temp = start; //makes sure start is not modified

 //generate a random number within range
  int x = rand()%len;

//reset temp
 temp = start;

//loop to the randomly chosen node
  while(x--)  temp = temp->next;

  return temp;
}

/**********remove a single specified node from the list, specified by both artist and song name.*********/

struct song_node * remove_node(struct song_node * start, char artist[100], char name[100]){
  // if the current node is not null
  if(start == NULL) return NULL;
  if(start){

    //creates a temporary node to use node comparison
    struct song_node * cmp = malloc(sizeof(struct song_node));
    strcpy(cmp->artist,artist);
    strcpy(cmp->name, name);

    //if the node to be removed is found
    if(node_cmp(cmp, start) == 0){

    //stores the next item on the list
    struct song_node * out = start -> next;

    //frees the temp node and the node to be removed.
      free(cmp);
      free(start);
      return out;
    }else{
      //frees temp node
      free(cmp);

      //connect what's before the removed item to what's after it.
      start -> next = remove_node(start ->next, artist, name);
    }
  }

  //returns start of list
  return start;
}

/**********free the entire list*************/
struct song_node * free_list(struct song_node * start){
  if(start != NULL){
  struct song_node * temp = start;
  while(start->next){
   start = start->next;

   //free current node
   free (temp);

   //go to next node
   temp=start;

  }
  free(temp);
}
  return start;
}

/**************free entire list with print test statements***********/
struct song_node * free_list_print(struct song_node * start){
  if(start != NULL){
  printf("============FREE LIST TEST============\n");
  struct song_node * temp = start;
  while(start->next){
   start = start->next;
   //free current node
   printf("frees:");
   print_node(temp);
   printf("\n");
   free (temp);

   //go to next node
   temp=start;

  }
  printf("frees:");
  print_node(temp);
  printf("\n");
  free(temp);
  printf("\n======================================\n\n");
}

  return start;
}
