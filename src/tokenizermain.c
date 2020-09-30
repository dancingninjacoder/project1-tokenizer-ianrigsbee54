#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/*checks if char c is a space, tab, or the null terminator*/
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
/*checks if char c is a not a space and is a letter,digit,or symbol*/
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
/*iterates until we reach the start of a word*/
char *word_start(char *str)
{
  while(space_char(*str)){
    str++;
  }
  return str;/*return a pointer pointing to the start of a word*/
}
/*iterates until we reach the first space character*/
char *word_terminator(char *word)
{
  while(non_space_char(*word)){
    word++;
  }
  return word;/*return a pointer pointing to the start of a space*/
}
/*counts the number of words within a string and return that count*/
int count_words(char *str)
{
  int count = 0;
  while(*str != '\0'){/*iterate until we reach the null terminator*/
    str = word_start(str);
    str = word_terminator(str);
    count++;/*once we reach the end of a word we increment count*/
  }
  return count;
}
/*copies the string up until len into a memory allocated string and returns it*/
char *copy_str(char *inStr, short len)
{
  char *copied_str = (char*) malloc(sizeof(char)*(len + 1));/*allocated memory for len + 1*/
  int i = 0;
  while(i < len){/*start inserting into new string*/
    copied_str[i] = inStr[i];
    i++;
  }
  copied_str[len] = '\0';/*set the last part of the string to the null terminator*/
  return copied_str;
}

char **tokenize(char* str)
{
  int length = count_words(str);/*count number of words in string*/
  char **char_array;
  char_array = (char**)malloc(sizeof(char*) * (length + 1));/*allocate memory for our vector*/
  int i = 0;
  
  while(i < length){/*start filling vector with pointers returned from copy_str*/
    str = word_start(str);
    int sizediff = word_terminator(str) - str;/*find the difference in length*/
    char_array[i] = copy_str(str,sizediff);
    str = word_terminator(str);/*set str to start at the next space char for word_start*/
    i++;
  }
  char_array[i] = NULL;/*set last part of char_array to NULL*/
  return char_array;
}
void print_tokens(char **tokens)
{
  int i;
  for(i = 0; tokens[i] != NULL; i++){/*iterate through and print the contents of tokens*/
    printf("%s\n", tokens[i]);
  }
}

void free_tokens(char **tokens)
{
  int i = 0;
  while(tokens[i] != NULL){/*iterate through and free the contents of tokens*/
    free(tokens[i]);
    i++;
  }
  free(tokens);/*last we free tokens itself as we allocated memory for it*/
}
