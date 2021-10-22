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


/************insert nodes in order, alphabetically by Artist then by Song***********/
struct song_node * insert_order(struct song_node * start, char artist[100],char name[100]){
 //allocate memory for new struct 
 struct song_node * p = malloc(sizeof(struct song_node));
 struct song_node * temp = start;
 //initialize new struct
  strcpy(p->artist,artist);
  strcpy(p->name, name);
 
 if(start == NULL){
  return p;
 }
 //making the strings that will be compared
 printf("====================\n");
  char p_str[200];  
  strncpy(p_str, p->artist, sizeof(p->artist));
  //strcpy(p_str, p->artist);
  printf("p_str copying artist: %s\n", p_str);
  char start_str[200]; 
  strncpy(start_str, start->artist, sizeof(start->artist));
 //strcpy(start_str, start->artist);
  printf("start_str copying artist: %s\n", start_str);
  strcat(p_str, p->name);
  printf("p_str cating name: %s\n", p_str);
  strcat(start_str, start-> name);
  printf("start_str cating name: %s\n", start_str);

  //find correct position to insert the new struct, keep track of prev
  printf ("comparison: %d\n", strcmp("pink floyd","pink"));
  struct song_node * prev = start;
  int front = 1;
     printf("continue: %d\n", cont(p,start));
  while(start -> next && cont(p,start)){
   front = 0;
   prev = start;
   start = start ->next; //next is null
   printf("Start: %s, %s\n", start -> artist, start ->name);
   printf("continue: %d\n", cont(p,start));
  
   }
   //strncpy(start_str, start->artist, sizeof(start->artist));
   //strcat(start_str, start-> name);

  //}
  // should go before start
   p->next = start;
   
  //p->next = start -> next;
  //start ->next = p;
  //prev -> next = p;
  printf("====================\n");
  if (front) return p;
  else{
  prev -> next = p;
  return temp;
  }
}

int cont (struct song_node * p, struct song_node * start){
   int cmp = strcmp(p->artist,start->artist);
   printf("cmp: %d\n",cmp);
   if (cmp<0){
    printf("artist is before\n");
    return 0;
   }else if (cmp == 0){
    if(strcmp(p->name,start->name)<=0){
     return 0;
    }else{
     return 1;
    }
    }
   else{
    return 1;
   }
}
/*************compare song nodes, returns < 0 if n1 goes before n2, if 0 the same, if > 0 n2 goes before n1*************/
int node_cmp (struct song_node * n1, struct song_node * n2);

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
