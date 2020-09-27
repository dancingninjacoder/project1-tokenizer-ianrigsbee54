#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

void main()
{
  List *hist = init_history();
  char input[256];
  
  printf("Welcome to tokenizer\n");
  printf("here are your commands\n");
  printf("q : quits program\n");
  printf("!x : brings up history at certain index x\n");
  printf("h : brings up all history\n");

  while(*str != 'q'){
    printf("$ ");
    fgets(input, 256, stdin);
    if(*input[0] == '!'){
      int index = (int)(input[1]);
      
    }
  }
  
}
void print(char *str)
{
  while(*str != '\0'){
    printf("%c", *str);
    str++;
  }
  printf("\n");
}
