#include <stdlib.h>
#include <string.h>

#include "llist.h"

//initialize a linked list
llist_t * ll_init(){
  //initialize a linked list by creating a size for it
  //and setting head = null and size = 0
    llist_t * newList = malloc(sizeof(llist_t));
    newList->head = NULL;
    newList->size = 0;

  return newList; //clearly it shouldn't return null when you finish it
}

//delete a linked list
void ll_delete(llist_t * ll){
  //free the head and the entire linked list
  //free every node
  ll_node_t * cur = ll-> head;
  ll_node_t * prev = NULL; 

  while(cur != NULL)
  {
    prev = cur;
    cur = cur -> next;
    free(prev->val);
    free(prev); 
  }

    free(ll);
}


//push an item onto the front of the list
void ll_push(llist_t * ll, char * s){
  //TODO
  ll_node_t * newNode = malloc(sizeof(ll_node_t));
  newNode -> val = strdup(s);
  newNode -> next = ll -> head;
  ll -> head = newNode;
  ll->size++;
}




