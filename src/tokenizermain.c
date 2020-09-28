#include <stdio.h>

#include <stdlib.h>

#include "tokenizer.h"



int space_char(char c)
{
  if(c == ' '){
    return 1;
  }else if(c == '\0'){
    return 0;
  }else if(c == '\t'){
    return 1;
  }
  return 0;
}

int non_space_char(char c)
{
  if(c == '\0'){
    return 0;
  }
  if(!space_char(c)){
    return 1;
  }
  return 0;
}

char *word_start(char *str)
{
  while(space_char(*str)){
    str++;
  }
  return str;
}
char *word_terminator(char *word)
{
  while(non_space_char(*word)){
    word++;
  }
  return word;
}

int count_words(char *str)
{
  int count = 0;
  while(*str != '\0'){
    str = word_start(str);
    str = word_terminator(str);
    count++;
  }
  return count;
}

char *copy_str(char *inStr, short len)
{
  char *copied_str = (char*) malloc(sizeof(char)*(len + 1));
  int i = 0;
  while(i < len){
    copied_str[i] = inStr[i];
    i++;
  }
  copied_str[len] = '\0';
  return copied_str;
}

char **tokenize(char* str)
{
  int length = count_words(str);
  char **char_array;
  char_array = (char**)malloc(sizeof(char*) * (length + 1));
  int i = 0;
  while(i < length-1){
    str = word_start(str);
    int sizediff = word_terminator(str) - str;
    char_array[i] = copy_str(str,sizediff);
    str = word_terminator(str);
    i++;
  }
  char_array[i] = NULL;
  return char_array;
}
void print_tokens(char **tokens)
{
  int i;
  for(i = 0; tokens[i] != NULL; i++){
    printf("%s\n", tokens[i]);
  }
}
void free_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != NULL){
    free(tokens[i]);
    i++;
  }
  free(tokens);
}
