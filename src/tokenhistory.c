#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history()
{
  List *history = (List*)malloc(sizeof(List));
  history->root = NULL;
}

void add_history(List *list, char *str)
{
  int count = 1;
  int length;
  int i = 0;
  while(str[i] != '\0'){
    i++;
  }
  length = i;
  
  Item *newItem = (Item*)malloc(sizeof(Item));
  newItem -> str = copy_str(str, length);
  newItem -> next = NULL;
  
  if(list->root == NULL){
    list->root = newItem;
    newItem->id = count;
    return;
  }
  Item *temp = list->root;
  while(temp->next != NULL){
    count++;
    temp = temp->next;
  }
  temp->next = newItem;
  newItem->id = count;
}

char *get_history(List *list, int id)
{
  if(id == 1){
    list->root->str;
  }
  int i = 0;
  Item *temp = list->root;
  while(temp != NULL){
    if(temp->id == id){
      return temp->str;
    }
    i++;
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
/*
void free_history(List *list)
{

}
*/
