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
  while(str != '\0'){
    if(non_space_char(*str)){
      return str;
    }
    str++;
  }
  return str;
}

char *word_terminator(char *word)
{
  while(word != '\0'){
    if(space_char(*word)){
      return word
    }
    word++;
  }
  return word;
}

 
int count_words(char *str)
{
  char *temp = str;
  if(*temp == '\0'){
    return 0;
  }
  temp = word_start(temp);
  temp = word_terminator(temp);
  return 1 + count_words(temp);
}
char *copy_str(char *inStr, short len)
{
  char *copied_str = (char*) malloc(len + 1);
  int i = 0;
  while(i < len){
    copied_str[i] = inStr[i];
  }
  copied_str[len] = '\0';
  return copied_str;
}

char **tokenize(char* str)
{
  int length = count_words(str);
  char **char_array;
  char_array = (char**)malloc(length + 1);
  int i = 0;
  while(i < length){
    char *start = word_start(str);
    char *end = word_terminator(str);
    int sizediff = end - start;

    char_array[i] = copy_str(str,sizediff);
    
  }
  char_array[i] = '\0';
  return char_array;
}
void print_tokens(char **tokens)
{
  int i;
  int j;
  for(i = 0; tokens[i] != '\0'; i++){
    for(j = 0; tokens[i][j] != '\0'; j++){
      printf("%c", tokens[i][j]);
    }
    printf(" ");
  }
}
/*
void free_tokens(char **tokens)
{
  
}
*/

int main(){
  char *charfinish = " Hello World";
  char *newstart = word_start(charfinish);
  char *newfinish = word_terminator(newstart);
  int size = newfinish - newstart;
  int i = 0;
  /*
  while(i<size){
    
  }
  */
  printf("difference is %i\n",size);
  // char *x = word_start(charstart);
  //printf("the char is %s\n", x);
  char *theword = "  Ian bo bian";
  int y  = count_words(theword);
  printf("the count is %i\n", y);
}
