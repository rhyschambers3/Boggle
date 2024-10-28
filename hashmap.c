#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>
#include <string.h>

#include "llist.h"
#include "hashmap.h"

//local function for hashing an input value (do not edit)
unsigned int _hash(hashmap_t * hm, char * val){
  //based on Java's String.hashcode()
  double k = 0;
  double len = (double) strlen(val);
  int i=1;
  for(char * c = val; *c ; c++,i++){
    k += (*c) * pow(31,len-i);
  }

  return (unsigned int) (((unsigned long) k) % hm->num_buckets);
}


//local function: resize the hashmap by doubling the number of buckets and rehashing
void _resize(hashmap_t * hm){
  //TODO: resize the hashmap if the load gets too high
  //rehash the strings and put in corresponding new buckets
  
  //double the size of the buckets and intialize the new hashmap
  int doubleSize = 2 * hm -> num_buckets;
  llist_t ** oldbuckets = hm->buckets;
  hm -> buckets = calloc(sizeof(llist_t*), doubleSize);
  // for loop to initialize each bucket
  for (int i = 0; i < doubleSize; i++)
  {
    hm -> buckets[i] = ll_init();
  }
  hm -> num_buckets = doubleSize;
 
  //iterate through old buckets
  //rehash 
  for (int i = 0; i < (doubleSize / 2); i++)
  {
    ll_node_t * node = oldbuckets[i]->head;
    while(node != NULL)
    {
      int newnum = _hash(hm, node->val); //find the new hash value for the new hashtable
      ll_push(hm->buckets[newnum], node->val); //push the old nodes to the new hash
      node = node->next;  //move to the next node
    }
  ll_delete(oldbuckets[i]); //delete 
  }
  free (oldbuckets);
}


//initliaze a hashmap with initial number of buckets
hashmap_t * hm_init(){

  //create the hashmap
  hashmap_t * hm = calloc(sizeof(hashmap_t),1);


  //initialize all of the structs 
  hm -> buckets = calloc(sizeof(llist_t*), HM_INIT_NUM_BUCKETS);
    // for loop to initialize each bucket
   for (int i = 0; i < HM_INIT_NUM_BUCKETS; i++)
  {
      hm->buckets[i] = ll_init();
  }
  hm -> num_buckets = HM_INIT_NUM_BUCKETS;
  hm -> size = 0;

  return hm;
}


//delete/deallocate the hashmap
void hm_delete(hashmap_t * hm){

  //TODO: properly deallocate

  //delete the hashmap
  //free everything that has memory space allocatted to it
  for (int i = 0; i < hm->num_buckets; i++)
  {
    ll_delete(hm->buckets[i]);
  }
  free(hm->buckets);
  free(hm);
}

//add a string value to the hashmap
void hm_add(hashmap_t * hm, char * val){
  // You get this function for free :)
  
  //check the load on the hashtable, if > max load, resize!
  if(((hm->size+1)/(double) hm->num_buckets) > HM_MAX_LOAD){
    _resize(hm); 
  }

  unsigned int h = _hash(hm,val); //get hash
  ll_push(hm->buckets[h],val); //note that list does string dup
  hm->size++; //increase size


}

//see if a string value is in the hashmap
bool hm_check(hashmap_t * hm, char * val){

  //check bucket number that we are looking for 
  int bucketnum = _hash(hm, val);
  //create a node that points to the head of the bucket we are looking for
  ll_node_t * cur = hm->buckets[bucketnum]->head;

  //iterate through the linked list where the value should be
  while(cur != NULL)
  {
    if (strcmp(cur->val, val) == 0)
    {
      return true;
    }
    cur = cur -> next;

  }
  return false;
}


