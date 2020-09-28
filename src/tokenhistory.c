#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Initializes list with the root being set to NULL*/
List *init_history()
{
  List *history = (List*)malloc(sizeof(List));
  history->root = NULL;
  return history;
}
/*adds a string to history list*/
void add_history(List *list, char *str)
{ 
  Item *newItem = (Item*)malloc(sizeof(Item)); /*allocate memory for a new node*/
  newItem->str = str;
  newItem->next = NULL;
  
  if(list->root == NULL){ /*checks if root is null*/
    list->root = newItem;
    newItem->id = 1;
  }else{
    int count = 2; /*start from 2 as the root is 1*/
    Item *temp = list->root;
    while(temp->next != NULL){/*iterate through list while incrementing count*/
      count++;
      temp = temp->next;
    }
    temp->next = newItem;/*sets tail of list to the new item*/
    newItem->id = count;
  }
}
/*retrieves the string stored at index id*/
char *get_history(List *list, int id)
{
  if(id == 1){
    list->root->str;/*if the id is 1 we retrieve the root*/
  }
  Item *temp = list->root;
  while(temp != NULL){ /*iterate through list until we reach target it*/
    if(temp->id == id){
      return temp->str;
    }
    temp = temp->next;
  }
  printf("id out of bounds");/*if we reached NULL then we went out of bounds*/
  return NULL;
}
/*prints all strings stored in the list*/
void print_history(List *list)
{
  Item *temp = list->root;
  while(temp != NULL){
    printf("id: %i\t String: %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}
/*frees all history items and the list itself*/
void free_history(List *list)
{
  Item *temp = list->root;
  Item *tempnext; 
  while(temp != NULL){
    tempnext = temp->next;/*stores the next node before freeing current node*/
    free(temp);
    temp = tempnext;/*now we set temp to be the next node*/
  }
}
