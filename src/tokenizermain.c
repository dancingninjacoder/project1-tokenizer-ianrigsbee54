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
  char *temp = str;
  char *char_start;
  while(*temp != '\0'){
    if(non_space_char(*temp)){
      char_start = temp;
      return char_start;
    }
    temp++;
  }
  return temp;
}

char *word_terminator(char *word)
{
  char *temp = word;
  char *char_end;
  while(*temp != '\0'){
    if(space_char(*temp)){
      char_end = temp;
      return char_end;
    }
    temp++;
  }
  return temp;
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
  char *copied_str = (char*) malloc(len*sizeof(char));
  copied_str = inStr;
  return copied_str;
}

int main(){
  char *charstart = " Hello";
  char *x = word_start(charstart);
  printf("the char is %s\n", x);
  char *theword = "  Ian bo bian";
  int y  = count_words(theword);
  printf("the count is %i\n", y);
}
