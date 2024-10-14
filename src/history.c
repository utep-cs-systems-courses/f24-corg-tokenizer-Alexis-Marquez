#include "history.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List* init_history(){
  List *list = (List *)malloc(sizeof(List));
  list->root = NULL;
  return list;
}
void add_history(List *list, char *str){
  Item *currItem = list->root;
  Item *newItem = malloc(sizeof(Item));
  newItem->str = strdup(str);
  newItem->next = NULL;
  if(list->root == NULL){
    newItem->id = 1;
    list->root = newItem;
    return;
  }
  while(currItem->next != NULL){
    currItem = currItem->next;
  }
  newItem->id = currItem->id + 1;
  currItem->next = newItem;
}
char *get_history(List *list, int id){
  Item *currItem = list->root;
  int i = 1;
  if(id<=0){
    return NULL;
  }
  while(currItem != NULL && i<id){
    currItem = currItem->next;
    i++;
  }
  if(currItem==NULL){
    return NULL;
  }
  return currItem->str;
}
void print_history(List *list){
  Item *currItem = list->root;
  while(currItem != NULL){
    printf("%i %s\n",currItem->id , currItem->str);
    currItem = currItem->next;
  }
}
void free_history(List *list){
  Item *currItem = list->root;
  Item *nextItem;
  while(currItem != NULL) {
      nextItem = currItem->next;
      free(currItem);
      currItem = nextItem;
    }
    free(list);
}
