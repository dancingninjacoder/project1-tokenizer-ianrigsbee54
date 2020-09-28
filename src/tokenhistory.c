#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history()
{
  List *history = (List*)malloc(sizeof(List));
  history->root = NULL;
  return history;
}

void add_history(List *list, char *str)
{ 
  Item *newItem = (Item*)malloc(sizeof(Item));
  newItem->str = str;
  newItem->next = NULL;
  if(list->root == NULL){
    list->root = newItem;
    newItem->id = 1;
  }else{
    int count = 2;
    Item *temp = list->root;
    while(temp->next != NULL){
      count++;
      temp = temp->next;
    }
    temp->next = newItem;
    newItem->id = count;
  }
}

char *get_history(List *list, int id)
{
  if(id == 1){
    list->root->str;
  }
  Item *temp = list->root;
  while(temp != NULL){
    if(temp->id == id){
      return temp->str;
    }
    temp = temp->next;
  }
  printf("id out of bounds");
  return NULL;
}

void print_history(List *list)
{
  Item *temp = list->root;
  while(temp != NULL){
    printf("id: %i\t String: %s\n", temp->id,temp->str);
    temp = temp->next;
  }
}

void free_history(List *list)
{
  Item *temp = list->root;
  Item *tempnext;
  while(temp != NULL){
    tempnext = temp->next;
    free(temp);
    temp = tempnext;
  }
}
