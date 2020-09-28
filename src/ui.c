#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

#define MAX 50
int main()
{
  // List *hist = init_history();
  char input[MAX];
  printf("enterinput\n");
  fgets(input, MAX, stdin);
  char **token = tokenize(input);
  print_tokens(token);
  free_tokens(token);
  printf("Welcome to tokenizer\n");
  printf("here are your commands\n");
  printf("q : quits program\n");
  printf("!x : brings up history at certain index x\n");
  /*
  while(*input != 'q'){
    printf("$ ");
    fgets(input, MAX, stdin);
    if(*input != '!' && *input != 'q'){
      printf("string entered is %s\n", input);
      char **token = tokenize(input);
      printf("tokenized string is\n");
      
      print_tokens(token);
      printf("freeing tokens\n");
      free_tokens(token);
      printf("adding to history\n");
      add_history(hist, input);
    }
    if(*input == '!'){
      int index = (int)(input[1]);
      char *histStr = get_history(hist, index);
      printf("item at index %i%s\n",index, histStr);
    }
  
    
  }
  printf("All of your history strings were\n");
  print_history(hist);
  printf("Now clearing history\n");
  free_history(hist);
  printf("Thank you for using tokenizer\n"); 
  */
  return 0;
  
}
